#include <iostream>
#include <algorithm>
using namespace std;

struct Item
{
    int weight, profit;
    float ratio;
};

bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

int main()
{
    int n, capacity;
    float totalProfit = 0;

    cout << "Enter number of items: ";
    cin >> n;

    Item item[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter weight and profit: ";
        cin >> item[i].weight >> item[i].profit;

        item[i].ratio =
            (float)item[i].profit / item[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    sort(item, item + n, compare);

    for (int i = 0; i < n; i++)
    {
        if (capacity >= item[i].weight)
        {
            capacity -= item[i].weight;
            totalProfit += item[i].profit;
        }
        else
        {
            totalProfit +=
                item[i].ratio * capacity;

            break;
        }
    }

    cout << "\nMaximum Profit: " << totalProfit;

    return 0;
}


/*
====================================================================
          FRACTIONAL KNAPSACK USING GREEDY ALGORITHM
                       COMPLETE EXPLANATION
====================================================================

1. AIM:

To write a C++ program to solve the Fractional Knapsack
Problem using the Greedy Algorithm and maximize the total
profit within the given knapsack capacity.

2. WHAT IS KNAPSACK PROBLEM?

The Knapsack Problem is an optimization problem in which
we have a bag (knapsack) with limited capacity.

We are given:
- A set of items.
- Weight of each item.
- Profit of each item.
- Maximum capacity of the knapsack.

The objective is to select items in such a way that
the total profit is maximum without exceeding the
knapsack capacity.

3. TYPES OF KNAPSACK PROBLEM:

A. Fractional Knapsack:
   - Items can be divided into fractions.
   - We can take a part of an item.
   - Greedy Algorithm provides an optimal solution.

B. 0/1 Knapsack:
   - Items cannot be divided.
   - Either we select the complete item or reject it.
   - Dynamic Programming is commonly used for an exact
     optimal solution.

4. GREEDY APPROACH:

In Fractional Knapsack, we select items according to
their profit-to-weight ratio.

Formula:

Profit-to-Weight Ratio = Profit / Weight

The item having the highest ratio is selected first.

Example:

Item A:
Weight = 10
Profit = 60
Ratio = 60/10 = 6

Item B:
Weight = 20
Profit = 100
Ratio = 100/20 = 5

Item C:
Weight = 30
Profit = 120
Ratio = 120/30 = 4

Selection order:

A -> B -> C

Because A has the highest profit-to-weight ratio.


====================================================================
3. LINE-BY-LINE CODE EXPLANATION
====================================================================

LINE 1:
#include <iostream>

Explanation:
- #include is a preprocessor directive.
- iostream is a standard C++ header file.
- It provides input and output functionality.
- It allows us to use cin and cout.
- cin accepts input from the user.
- cout displays output on the screen.

LINE 2:
#include <algorithm>

Explanation:
- Includes the algorithm header file.
- It provides predefined algorithms in C++.
- This program uses the sort() function.
- sort() arranges items according to their profit-to-weight
  ratio.

LINE 3:
using namespace std;

Explanation:
- std is the standard C++ namespace.
- It allows us to use cin, cout and sort without writing
  std:: before each name.

====================================================================
4. ITEM STRUCTURE EXPLANATION
====================================================================

LINE 4:
struct Item

Explanation:
- struct is used to create a user-defined data type.
- Item represents one object or item of the knapsack problem.
- It groups weight, profit and ratio together.

LINE 5:
{

Explanation:
- Marks the beginning of the Item structure.

LINE 6:
int weight, profit;

Explanation:
- Declares two integer variables.
- weight stores the weight of the item.
- profit stores the profit obtained by selecting the item.

LINE 7:
float ratio;

Explanation:
- Declares a floating-point variable.
- Stores the profit-to-weight ratio.
- It may contain decimal values.

Formula:
ratio = profit / weight

LINE 8:
};

Explanation:
- Marks the end of the Item structure.
- Semicolon is required after a structure definition.


====================================================================
5. COMPARE FUNCTION EXPLANATION
====================================================================

LINE 9:
bool compare(Item a, Item b)

Explanation:
- Defines a user-defined comparison function.
- bool is the return type.
- Item a and Item b are two items being compared.
- The function determines their sorting order.
- It is passed to the sort() function.

LINE 10:
{

Explanation:
- Beginning of the compare function.

LINE 11:
return a.ratio > b.ratio;

Explanation:
- Compares the ratios of two items.
- If a.ratio is greater than b.ratio, it returns true.
- This arranges the items in descending order.
- Items having higher profit-to-weight ratios appear first.

Example:

A ratio = 6
B ratio = 5

Since 6 > 5, A comes before B.

LINE 12:
}

Explanation:
- Marks the end of the compare function.


====================================================================
6. MAIN FUNCTION EXPLANATION
====================================================================

LINE 13:
int main()

Explanation:
- main() is the starting point of program execution.
- int indicates that the function returns an integer.

LINE 14:
{

Explanation:
- Marks the beginning of the main function.

LINE 15:
int n, capacity;

Explanation:
- Declares two integer variables.
- n stores the total number of items.
- capacity stores the maximum capacity of the knapsack.

LINE 16:
float totalProfit = 0;

Explanation:
- Declares a floating-point variable.
- Initializes totalProfit to zero.
- Stores the total profit obtained from selected items.
- float is used because fractional selection can produce
  decimal profit values.

LINE 17:
cout << "Enter number of items: ";

Explanation:
- Displays a message asking the user to enter the
  total number of items.

LINE 18:
cin >> n;

Explanation:
- Accepts the number of items from the user.
- Stores the value in n.

LINE 19:
Item item[n];

Explanation:
- Creates an array of Item structures.
- The array stores n items.
- Each element contains weight, profit and ratio.
- item[i] represents the ith item.

IMPORTANT:
Variable-length arrays are not part of standard C++.
Some compilers support them as an extension.
std::vector<Item> is the standard alternative.

LINE 20:
for (int i = 0; i < n; i++)

Explanation:
- A for loop is used to accept information about each item.
- i starts from zero.
- The loop executes n times.
- i++ increments the counter after each iteration.

LINE 21:
{

Explanation:
- Beginning of the for loop body.

LINE 22:
cout << "Enter weight and profit: ";

Explanation:
- Asks the user to enter the weight and profit
  of the current item.

LINE 23:
cin >> item[i].weight >> item[i].profit;

Explanation:
- Accepts the weight and profit of the current item.
- item[i].weight stores its weight.
- item[i].profit stores its profit.
- The dot operator accesses structure members.

Example:

10 60

weight = 10
profit = 60

LINE 24:
item[i].ratio =
    (float)item[i].profit / item[i].weight;

Explanation:
- Calculates the profit-to-weight ratio.
- The ratio determines the priority of each item.
- (float) converts the profit into a floating-point value.
- This allows floating-point division instead of integer
  division.

Formula:

Ratio = Profit / Weight

Example:

Profit = 60
Weight = 10

Ratio = 60.0 / 10
      = 6.0

IMPORTANT:
Type casting is used to avoid integer division.

LINE 25:
}

Explanation:
- Ends the input loop.
- All item information and ratios have been calculated.


====================================================================
7. KNAPSACK CAPACITY INPUT
====================================================================

LINE 26:
cout << "Enter knapsack capacity: ";

Explanation:
- Displays a message asking for the maximum capacity
  of the knapsack.

LINE 27:
cin >> capacity;

Explanation:
- Accepts the maximum capacity from the user.
- Stores the value in capacity.

Example:
capacity = 50

This means the knapsack can carry a maximum weight of 50.


====================================================================
8. SORTING EXPLANATION
====================================================================

LINE 28:
sort(item, item + n, compare);

Explanation:
- sort() is a predefined function from the algorithm
  header file.
- It sorts the item array.
- item represents the beginning of the array.
- item + n represents the position just after the last
  array element.
- compare is the custom comparison function.
- Items are sorted in descending order of ratio.

Example:

Before sorting:

A = 6
B = 5
C = 4

After sorting:

A = 6
B = 5
C = 4

If the original order were C, A, B, sorting would
rearrange it to A, B, C.

IMPORTANT:
Sorting is performed according to the ratio, not
according to weight or profit alone.


====================================================================
9. ITEM SELECTION EXPLANATION
====================================================================

LINE 29:
for (int i = 0; i < n; i++)

Explanation:
- Executes a loop to select items.
- Items are already sorted by profit-to-weight ratio.
- Therefore, the highest-ratio item is considered first.

LINE 30:
{

Explanation:
- Beginning of the item selection loop.

LINE 31:
if (capacity >= item[i].weight)

Explanation:
- Checks whether the remaining capacity is sufficient
  to include the complete current item.
- If true, the entire item is selected.

LINE 32:
{

Explanation:
- Beginning of the if block.

LINE 33:
capacity -= item[i].weight;

Explanation:
- Subtracts the selected item's weight from the remaining
  knapsack capacity.
- The -= operator subtracts and assigns the result.

Example:

capacity = 50
weight = 10

New capacity = 50 - 10
             = 40

LINE 34:
totalProfit += item[i].profit;

Explanation:
- Adds the complete item's profit to totalProfit.
- The += operator adds a value and assigns the result.

Example:

totalProfit = 0
profit = 60

New totalProfit = 60

LINE 35:
}

Explanation:
- Ends the if block.

LINE 36:
else

Explanation:
- Executes when the remaining capacity is smaller than
  the weight of the current item.
- The complete item cannot be selected.
- Therefore, only a fraction of the item is selected.

LINE 37:
{

Explanation:
- Beginning of the else block.

LINE 38:
totalProfit +=
    item[i].ratio * capacity;

Explanation:
- Calculates the profit obtained by taking a fraction
  of the current item.
- ratio represents profit per unit of weight.
- Multiplying it by the remaining capacity calculates
  the profit from the selected fraction.

Formula:

Fractional Profit = Ratio * Remaining Capacity

Example:

Ratio = 4
Remaining Capacity = 5

Fractional Profit = 4 * 5
                  = 20

LINE 39:
break;

Explanation:
- Immediately terminates the for loop.
- The knapsack is now completely full.
- No more items can be selected.

LINE 40:
}

Explanation:
- Ends the else block.

LINE 41:
}

Explanation:
- Ends the item selection loop.


====================================================================
10. DISPLAY FINAL PROFIT
====================================================================

LINE 42:
cout << "\nMaximum Profit: " << totalProfit;

Explanation:
- Displays the final maximum profit.
- \n moves the output to a new line.
- totalProfit contains the accumulated profit from
  selected complete and fractional items.

LINE 43:
return 0;

Explanation:
- Terminates the main function.
- Returns 0 to indicate successful program execution.

LINE 44:
}

Explanation:
- Marks the end of the main function.


====================================================================
11. WORKING OF THE PROGRAM
====================================================================

Steps:

1. Start the program.
2. Accept the number of items.
3. Declare an array of Item structures.
4. Accept weight and profit of every item.
5. Calculate the profit-to-weight ratio.
6. Accept knapsack capacity.
7. Sort all items in descending order of ratio.
8. Start selecting items from the highest ratio.
9. Check whether the complete item fits.
10. If it fits:
    - Select the complete item.
    - Subtract its weight from capacity.
    - Add its profit to totalProfit.
11. Otherwise:
    - Select the fraction that fits.
    - Calculate fractional profit.
    - Add fractional profit to totalProfit.
    - Stop the loop.
12. Display maximum profit.
13. Stop.


====================================================================
12. DRY RUN WITH EXAMPLE
====================================================================

INPUT:

Number of items = 3

Item 1:
Weight = 10
Profit = 60

Item 2:
Weight = 20
Profit = 100

Item 3:
Weight = 30
Profit = 120

Knapsack Capacity = 50


STEP 1: CALCULATE RATIOS

Item 1:

Ratio = 60 / 10
      = 6

Item 2:

Ratio = 100 / 20
      = 5

Item 3:

Ratio = 120 / 30
      = 4


STEP 2: SORT ITEMS

Descending order of ratio:

Item 1: Ratio = 6
Item 2: Ratio = 5
Item 3: Ratio = 4


STEP 3: INITIAL VALUES

Capacity = 50
Total Profit = 0


STEP 4: SELECT ITEM 1

Weight = 10
Profit = 60

Capacity >= Weight

50 >= 10

Condition is TRUE.

New Capacity:

50 - 10 = 40

New Total Profit:

0 + 60 = 60


STEP 5: SELECT ITEM 2

Weight = 20
Profit = 100

40 >= 20

Condition is TRUE.

New Capacity:

40 - 20 = 20

New Total Profit:

60 + 100 = 160


STEP 6: SELECT FRACTION OF ITEM 3

Weight = 30
Profit = 120

Remaining Capacity = 20

20 < 30

Condition is FALSE.

Fraction selected:

20 / 30 = 2/3

Fractional Profit:

Ratio * Remaining Capacity

4 * 20 = 80

New Total Profit:

160 + 80 = 240

The break statement terminates the loop.


FINAL RESULT:

Maximum Profit = 240


====================================================================
13. SELECTION TABLE
====================================================================

Item   Weight   Profit   Ratio   Selected Weight   Profit
-----------------------------------------------------------
1      10       60       6       10                60
2      20       100      5       20                100
3      30       120      4       20                80

-----------------------------------------------------------

Total Selected Weight = 10 + 20 + 20 = 50

Total Profit = 60 + 100 + 80 = 240

Knapsack Capacity = 50


====================================================================
14. ALGORITHM
====================================================================

Step 1: Start.

Step 2: Read the number of items n.

Step 3: Read weight and profit of every item.

Step 4: Calculate the ratio of each item.

        ratio = profit / weight

Step 5: Read knapsack capacity.

Step 6: Sort items in descending order of ratio.

Step 7: Initialize totalProfit = 0.

Step 8: Traverse the sorted items.

Step 9: If the complete item fits:
        a. Subtract its weight from capacity.
        b. Add its profit to totalProfit.

Step 10: Otherwise:
         a. Calculate fractional profit.
         b. Add it to totalProfit.
         c. Terminate the loop.

Step 11: Display totalProfit.

Step 12: Stop.


====================================================================
15. TIME AND SPACE COMPLEXITY
====================================================================

Let n represent the number of items.

TIME COMPLEXITY:

1. Reading item information:

   O(n)

2. Calculating profit-to-weight ratios:

   O(n)

3. Sorting items:

   O(n log n)

4. Selecting items:

   O(n)

OVERALL TIME COMPLEXITY:

O(n log n)

Reason:
Sorting is the most time-consuming operation.

SPACE COMPLEXITY:

O(n)

Reason:
The program stores n items in an array.

Note:
The sorting implementation may use additional
implementation-dependent stack space.


====================================================================
16. IMPORTANT DATA STRUCTURES AND CONCEPTS
====================================================================

1. STRUCTURE:
   A user-defined data type that groups related variables.

2. ARRAY:
   A collection of elements of the same data type.

3. GREEDY ALGORITHM:
   An algorithm that makes the locally optimal choice
   at each step.

4. SORTING:
   Arranging elements according to a specific order.

5. COMPARATOR:
   A function that determines the ordering of elements.

6. TYPE CASTING:
   Converting a value from one data type to another.

7. FLOAT:
   A data type used to store decimal numbers.

8. RATIO:
   The profit obtained per unit of weight.

9. KNAPSACK CAPACITY:
   The maximum weight that the bag can carry.

10. FRACTIONAL SELECTION:
    Selecting only a part of an item.

11. OPTIMIZATION:
    Finding the best possible solution according
    to a given objective.

12. BREAK:
    A statement used to terminate a loop immediately.


====================================================================
17. SAMPLE INPUT AND SAMPLE OUTPUT
====================================================================

SAMPLE INPUT 1:

Enter number of items: 3

Enter weight and profit: 10 60
Enter weight and profit: 20 100
Enter weight and profit: 30 120

Enter knapsack capacity: 50


SAMPLE OUTPUT 1:

Maximum Profit: 240


EXPLANATION:

- Three items are entered.
- Their ratios are 6, 5 and 4.
- Items are sorted in descending ratio order.
- The first two items are completely selected.
- 20 units of the third item are selected.
- Total profit becomes 240.


------------------------------------------------------------

SAMPLE INPUT 2:

Enter number of items: 3

Enter weight and profit: 5 30
Enter weight and profit: 10 40
Enter weight and profit: 15 45

Enter knapsack capacity: 20


SAMPLE OUTPUT 2:

Maximum Profit: 85


EXPLANATION:

Ratios:

Item 1 = 30/5 = 6
Item 2 = 40/10 = 4
Item 3 = 45/15 = 3

Selection:

- Complete Item 1: Profit = 30.
- Complete Item 2: Profit = 40.
- Remaining capacity = 5.
- Take 5 units of Item 3.
- Fractional profit = 3 * 5 = 15.

Total Profit:

30 + 40 + 15 = 85.


------------------------------------------------------------

SAMPLE INPUT 3:

Enter number of items: 2

Enter weight and profit: 10 100
Enter weight and profit: 20 200

Enter knapsack capacity: 15


SAMPLE OUTPUT 3:

Maximum Profit: 150


EXPLANATION:

- Item 1 ratio = 10.
- Item 2 ratio = 10.
- The complete first item is selected.
- Remaining capacity = 5.
- Five units of the second item are selected.
- Fractional profit = 10 * 5 = 50.
- Total profit = 100 + 50 = 150.

Note:
Both items have the same ratio, so their selection
order does not change the optimal profit.


------------------------------------------------------------

SAMPLE INPUT 4:

Enter number of items: 3

Enter weight and profit: 10 60
Enter weight and profit: 20 100
Enter weight and profit: 30 120

Enter knapsack capacity: 0


SAMPLE OUTPUT 4:

Maximum Profit: 0


EXPLANATION:

- The knapsack capacity is zero.
- No item can be selected.
- Total profit remains zero.


====================================================================
18. VIVA QUESTIONS AND ANSWERS
====================================================================

BASIC VIVA QUESTIONS
--------------------

Q1. What is the Knapsack Problem?

Ans:
It is an optimization problem in which items are selected
to maximize profit without exceeding the given capacity.

Q2. What is Fractional Knapsack?

Ans:
A knapsack problem in which items can be divided into
fractions.

Q3. What is the objective of this program?

Ans:
To maximize total profit using the Greedy Algorithm.

Q4. Which algorithm is used?

Ans:
Greedy Algorithm.

Q5. What is a Greedy Algorithm?

Ans:
An algorithm that selects the locally optimal choice
at each step.

Q6. What is the main difference between Fractional and
0/1 Knapsack?

Ans:
Fractional Knapsack allows partial selection, whereas
0/1 Knapsack allows only complete selection or rejection.

Q7. What is the profit-to-weight ratio?

Ans:
It is the profit obtained per unit of weight.

Q8. What is the formula for ratio?

Ans:
Ratio = Profit / Weight.

Q9. Why are items sorted?

Ans:
To select the items having the highest profit-to-weight
ratio first.

Q10. What is the objective function?

Ans:
To maximize the total profit while keeping the total
selected weight within the capacity.


STRUCTURE AND ARRAY QUESTIONS
-----------------------------

Q11. What is a structure?

Ans:
A user-defined data type that groups related variables.

Q12. Why is Item structure used?

Ans:
To store weight, profit and ratio of each item together.

Q13. What does weight represent?

Ans:
The weight of an item.

Q14. What does profit represent?

Ans:
The profit obtained from an item.

Q15. What does ratio represent?

Ans:
Profit per unit of weight.

Q16. What is an array?

Ans:
A collection of elements of the same data type.

Q17. Why is an array used?

Ans:
To store multiple items.

Q18. What is item[i]?

Ans:
The ith element of the item array.

Q19. What is the dot operator?

Ans:
It accesses members of a structure or object.

Q20. What is a variable-length array?

Ans:
An array whose size is determined at runtime.


GREEDY ALGORITHM QUESTIONS
--------------------------

Q21. Why is Fractional Knapsack called a Greedy Algorithm?

Ans:
Because it repeatedly selects the item with the highest
profit-to-weight ratio.

Q22. What is a locally optimal choice?

Ans:
The best choice at the current step.

Q23. Does Greedy Algorithm give an optimal solution
for Fractional Knapsack?

Ans:
Yes, sorting by decreasing profit-to-weight ratio
gives an optimal solution.

Q24. Does Greedy Algorithm always give an optimal
solution for 0/1 Knapsack?

Ans:
No. A simple ratio-based greedy strategy is not
guaranteed to give the optimal 0/1 solution.

Q25. Why is ratio used instead of profit alone?

Ans:
Because ratio measures profit obtained per unit of
limited capacity.

Q26. Which item is selected first?

Ans:
The item having the highest ratio.

Q27. What happens when two items have the same ratio?

Ans:
Either can be selected first without affecting
the optimal profit.


SORTING QUESTIONS
-----------------

Q28. Which sorting function is used?

Ans:
sort().

Q29. Which header file provides sort()?

Ans:
<algorithm>.

Q30. What is the purpose of compare()?

Ans:
It sorts items in descending order of ratio.

Q31. What is a comparator?

Ans:
A function that defines the ordering of elements.

Q32. What does a.ratio > b.ratio mean?

Ans:
It places the item with the greater ratio before
the item with the smaller ratio.

Q33. What is the time complexity of sorting?

Ans:
O(n log n).

Q34. What happens if we use a.ratio < b.ratio?

Ans:
Items will be sorted in ascending order, which is
not the required greedy order.

Q35. What is the purpose of item + n?

Ans:
It points to the position immediately after the
last element of the array.


TYPE CASTING AND VARIABLE QUESTIONS
-----------------------------------

Q36. Why is float used for ratio?

Ans:
Because the ratio can contain decimal values.

Q37. What is type casting?

Ans:
Converting a value from one data type to another.

Q38. Why is (float) used?

Ans:
To perform floating-point division instead of integer
division.

Q39. What happens if type casting is removed?

Ans:
Integer division may occur before the result is assigned
to the float variable, causing loss of fractional parts.

Q40. Why is totalProfit declared as float?

Ans:
Because fractional item selection may generate
decimal profit.

Q41. What is the difference between int and float?

Ans:
int stores integer values, while float stores
floating-point values.

Q42. What is the purpose of capacity?

Ans:
It stores the remaining knapsack capacity.


LOOP AND CONDITION QUESTIONS
----------------------------

Q43. Which loops are used?

Ans:
Two for loops are used.

Q44. Why is the first loop used?

Ans:
To accept item details and calculate ratios.

Q45. Why is the second loop used?

Ans:
To select items and calculate total profit.

Q46. What is the purpose of if condition?

Ans:
To check whether the complete item fits in the remaining
capacity.

Q47. What is the purpose of else?

Ans:
To select a fraction when the complete item cannot fit.

Q48. What is the purpose of break?

Ans:
To terminate the loop after the knapsack becomes full.

Q49. What happens if break is removed?

Ans:
The loop continues, potentially processing additional
items even though capacity is zero.

Q50. What does capacity -= item[i].weight mean?

Ans:
It subtracts the selected item's weight from capacity.


FRACTIONAL SELECTION QUESTIONS
------------------------------

Q51. What is fractional selection?

Ans:
Selecting only a part of an item.

Q52. How is fractional profit calculated?

Ans:
Fractional Profit = Ratio * Remaining Capacity.

Q53. What happens when the complete item fits?

Ans:
The complete item is selected.

Q54. What happens when the complete item does not fit?

Ans:
Only the fraction that fits is selected.

Q55. Why does the program stop after fractional selection?

Ans:
Because the remaining capacity becomes completely full.

Q56. Can we take 50% of an item?

Ans:
Yes, if that fraction fits in the remaining capacity.

Q57. Can we take 25% of an item?

Ans:
Yes. Fractional Knapsack allows any suitable fraction.


COMPLEXITY QUESTIONS
--------------------

Q58. What is the time complexity?

Ans:
O(n log n).

Q59. Why is the complexity O(n log n)?

Ans:
Because sorting takes O(n log n), while the other
operations take O(n).

Q60. What is the space complexity?

Ans:
O(n).

Q61. Which operation takes the maximum time?

Ans:
Sorting.

Q62. What is the complexity of calculating ratios?

Ans:
O(n).

Q63. What is the complexity of selecting items?

Ans:
O(n).


ADVANCED AND TRICKY EXTERNAL VIVA QUESTIONS
-------------------------------------------

Q64. What is the difference between Fractional and
0/1 Knapsack?

Ans:
Fractional allows partial selection, while 0/1 allows
only complete selection or rejection.

Q65. Which algorithm is generally used for 0/1 Knapsack?

Ans:
Dynamic Programming for the standard exact solution.

Q66. Why is Fractional Knapsack easier than 0/1 Knapsack?

Ans:
Because partial selection is allowed, making the
profit-to-weight greedy strategy optimal.

Q67. What happens if capacity is greater than the
total weight of all items?

Ans:
All items are selected, and some capacity remains unused.

Q68. What happens if capacity is zero?

Ans:
No item is selected, and total profit remains zero.

Q69. What happens if an item's weight is zero?

Ans:
Division by zero occurs while calculating its ratio.
The program does not validate this case.

Q70. What happens if profit is zero?

Ans:
The item's ratio becomes zero, assuming positive weight.

Q71. What happens if profit is negative?

Ans:
The program calculates a negative ratio. Such an item
should generally not be selected in a profit-maximization
problem when selection is optional.

Q72. What happens if all items have the same ratio?

Ans:
Any selection order among them gives the same profit
per unit of weight.

Q73. Is the solution always optimal?

Ans:
Yes, for the standard Fractional Knapsack problem with
positive weights and non-negative profits.

Q74. What is an optimization problem?

Ans:
A problem in which we find the best solution according
to a specified objective.

Q75. What is the objective of optimization here?

Ans:
Maximizing total profit.

Q76. Can we select an item more than once?

Ans:
This implementation considers each listed item once.

Q77. What is the difference between profit and ratio?

Ans:
Profit is the total earning from an item, while ratio
is the earning per unit of weight.

Q78. Why is sorting done before selection?

Ans:
To ensure the highest-ratio items are considered first.

Q79. Can we sort by weight instead?

Ans:
Not for the standard greedy Fractional Knapsack strategy.
We must sort by profit-to-weight ratio.

Q80. Can we sort by profit alone?

Ans:
No. The highest-profit item may also have a very high
weight and a lower profit-to-weight ratio.

Q81. What is the role of the comparator?

Ans:
It defines the descending order of item ratios.

Q82. What is the difference between sort() and reverse()?

Ans:
sort() arranges elements according to an ordering rule,
while reverse() simply reverses their current order.

Q83. What is the difference between += and =?

Ans:
+= adds a value to the existing variable, while =
assigns a new value.

Q84. What is the difference between break and continue?

Ans:
break terminates the loop, whereas continue skips the
current iteration and proceeds to the next one.

Q85. Can this program be implemented using vector?

Ans:
Yes. vector<Item> can replace the variable-length array.

Q86. Why is float preferred over int for totalProfit?

Ans:
Because fractional selection can produce decimal values.

Q87. What happens if capacity is not sufficient for
the first item?

Ans:
A fraction of the first item is selected.

Q88. What happens if capacity is exactly equal to
an item's weight?

Ans:
The complete item is selected because the condition
uses >=.

Q89. Can Fractional Knapsack be solved using Dynamic
Programming?

Ans:
It can be formulated using other optimization techniques,
but the greedy approach is simpler and optimal for
the standard Fractional Knapsack problem.

Q90. Give real-world applications of Knapsack Problem.

Ans:
- Cargo loading.
- Resource allocation.
- Budget optimization.
- Investment selection models.
- Capacity planning.


====================================================================
19. IMPORTANT DIFFERENCES: FRACTIONAL VS 0/1 KNAPSACK
====================================================================

FRACTIONAL KNAPSACK:

1. Items can be divided.
2. Partial selection is allowed.
3. Greedy Algorithm is optimal.
4. Sort by profit-to-weight ratio.
5. Time complexity: O(n log n).

0/1 KNAPSACK:

1. Items cannot be divided.
2. Only complete selection or rejection is allowed.
3. Ratio-based Greedy Algorithm is not always optimal.
4. Dynamic Programming is commonly used.
5. Standard DP time complexity: O(nW), where W is capacity.


====================================================================
20. IMPORTANT POINTS TO REMEMBER FOR EXTERNAL VIVA
====================================================================

1. Fractional Knapsack is an optimization problem.
2. It uses the Greedy Algorithm.
3. Items are sorted by profit-to-weight ratio.
4. The highest-ratio item is selected first.
5. Partial item selection is allowed.
6. Ratio = Profit / Weight.
7. Fractional Profit = Ratio * Remaining Capacity.
8. sort() is used for sorting.
9. compare() sorts in descending order.
10. break terminates the selection loop.
11. Time complexity is O(n log n).
12. Space complexity is O(n).
13. Greedy Algorithm gives an optimal Fractional Knapsack
    solution.
14. Ratio-based Greedy Algorithm is not guaranteed
    to solve 0/1 Knapsack optimally.

====================================================================
                    END OF EXPLANATION
====================================================================
*/