#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    int weight[n], profit[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter weight and profit: ";
        cin >> weight[i] >> profit[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;

            else if (weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    cout << "\nMaximum Profit: " << dp[n][capacity];

    return 0;
}


/*
====================================================================
           0/1 KNAPSACK USING DYNAMIC PROGRAMMING
                       COMPLETE EXPLANATION
====================================================================

1. AIM:

To write a C++ program to solve the 0/1 Knapsack Problem
using Dynamic Programming and maximize the total profit
without exceeding the given knapsack capacity.

2. WHAT IS KNAPSACK PROBLEM?

Knapsack Problem is an optimization problem in which
we are given:

- A set of items.
- Weight of each item.
- Profit of each item.
- Maximum capacity of the knapsack.

The objective is to select items such that the total
profit is maximum without exceeding the capacity.

3. WHAT IS 0/1 KNAPSACK?

In 0/1 Knapsack:

- Each item can either be selected completely or rejected.
- An item cannot be divided into fractions.
- Each item can be selected at most once.

0 means the item is not selected.
1 means the item is selected.

Example:

Item A:
Weight = 10
Profit = 60

We can either:
- Select the complete item.
- Reject the complete item.

We cannot select half of Item A.

4. WHAT IS DYNAMIC PROGRAMMING?

Dynamic Programming is an algorithmic technique that
solves a complex problem by dividing it into smaller
overlapping subproblems.

It stores previously calculated results to avoid
recalculating the same subproblems.

In this program:
- A two-dimensional DP table is used.
- Each cell stores the maximum profit possible.
- Previous results are used to calculate new results.


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

LINE 2:
#include <algorithm>

Explanation:
- Includes the algorithm header file.
- It provides predefined algorithms.
- This program uses the max() function.
- max() returns the greater of two values.

LINE 3:
using namespace std;

Explanation:
- std is the standard C++ namespace.
- It allows us to use cin, cout and max without
  writing std:: before them.

====================================================================
4. MAIN FUNCTION EXPLANATION
====================================================================

LINE 4:
int main()

Explanation:
- main() is the starting point of program execution.
- int indicates that the function returns an integer.

LINE 5:
{

Explanation:
- Marks the beginning of the main function.

LINE 6:
int n, capacity;

Explanation:
- Declares two integer variables.
- n stores the total number of items.
- capacity stores the maximum weight capacity
  of the knapsack.

LINE 7:
cout << "Enter number of items: ";

Explanation:
- Displays a message asking the user to enter
  the number of items.

LINE 8:
cin >> n;

Explanation:
- Accepts the number of items from the user.
- Stores the entered value in n.

LINE 9:
int weight[n], profit[n];

Explanation:
- Declares two integer arrays.
- weight[] stores the weight of each item.
- profit[] stores the profit of each item.
- Both arrays contain n elements.

Example:

weight[0] = 10
profit[0] = 60

IMPORTANT:
Variable-length arrays are not part of standard C++.
Some compilers support them as an extension.
std::vector is the standard portable alternative.

====================================================================
5. INPUT LOOP EXPLANATION
====================================================================

LINE 10:
for (int i = 0; i < n; i++)

Explanation:
- A for loop is used to accept item information.
- i starts from zero.
- The loop executes n times.
- i++ increments the counter after each iteration.

LINE 11:
{

Explanation:
- Beginning of the for loop body.

LINE 12:
cout << "Enter weight and profit: ";

Explanation:
- Asks the user to enter the weight and profit
  of the current item.

LINE 13:
cin >> weight[i] >> profit[i];

Explanation:
- Accepts the weight and profit of the current item.
- weight[i] stores the item's weight.
- profit[i] stores the item's profit.

Example:
10 60

weight[0] = 10
profit[0] = 60

LINE 14:
}

Explanation:
- Marks the end of the input loop.

====================================================================
6. KNAPSACK CAPACITY INPUT
====================================================================

LINE 15:
cout << "Enter knapsack capacity: ";

Explanation:
- Displays a message asking for the maximum
  capacity of the knapsack.

LINE 16:
cin >> capacity;

Explanation:
- Accepts the knapsack capacity from the user.
- Stores the value in capacity.

Example:
capacity = 50

This means the knapsack can carry a maximum weight of 50.


====================================================================
7. DP TABLE DECLARATION
====================================================================

LINE 17:
int dp[n + 1][capacity + 1];

Explanation:
- Declares a two-dimensional integer array.
- dp stands for Dynamic Programming table.
- It stores the maximum profit for different numbers
  of items and different capacities.

Why n + 1?

- One extra row represents zero items.
- Rows range from 0 to n.

Why capacity + 1?

- One extra column represents zero capacity.
- Columns range from 0 to capacity.

Meaning:

dp[i][w] represents the maximum profit obtainable
using the first i items with a knapsack capacity w.

Example:

dp[2][30]

Means:
Maximum profit using the first two items with
a capacity of 30.


====================================================================
8. OUTER LOOP EXPLANATION
====================================================================

LINE 18:
for (int i = 0; i <= n; i++)

Explanation:
- This loop processes the number of available items.
- i starts at zero.
- It continues until i becomes equal to n.
- It calculates DP values for every possible number
  of items.

The extra iteration for i = 0 represents the case
where no items are available.

LINE 19:
{

Explanation:
- Beginning of the outer loop body.

====================================================================
9. INNER LOOP EXPLANATION
====================================================================

LINE 20:
for (int w = 0; w <= capacity; w++)

Explanation:
- This loop processes every possible capacity.
- w starts from zero.
- It continues until w becomes equal to capacity.
- It calculates the maximum profit for each capacity.

LINE 21:
{

Explanation:
- Beginning of the inner loop body.

====================================================================
10. BASE CONDITION EXPLANATION
====================================================================

LINE 22:
if (i == 0 || w == 0)

Explanation:
- Checks whether there are zero items or zero capacity.
- || is the logical OR operator.
- If either condition is true, maximum profit is zero.

Reason:

Case 1:
If there are no items, no profit can be obtained.

Case 2:
If capacity is zero, no positive-weight item can be
selected.

LINE 23:
dp[i][w] = 0;

Explanation:
- Assigns zero to the current DP table cell.
- This represents the base condition of the problem.

IMPORTANT:
These initial values are necessary to calculate
the remaining DP table entries correctly.


====================================================================
11. ITEM SELECTION CONDITION
====================================================================

LINE 24:
else if (weight[i - 1] <= w)

Explanation:
- Checks whether the current item can fit into the
  available capacity.
- weight[i - 1] represents the weight of the current item.
- i - 1 is used because array indexing starts from zero,
  while the DP table starts from one for the first item.

Example:

i = 2

Current item index = 2 - 1 = 1

Therefore, weight[1] represents the second item.

If the item's weight is less than or equal to w,
the item can be selected.

LINE 25:
{

Explanation:
- Beginning of the item selection condition.

LINE 26:
dp[i][w] = max(

Explanation:
- max() compares two possible profits.
- It returns the larger value.
- This helps select the option that produces
  maximum profit.

There are two choices:

1. Include the current item.
2. Exclude the current item.

The better choice is stored in dp[i][w].

LINE 27:
profit[i - 1] + dp[i - 1][w - weight[i - 1]],

Explanation:

This expression calculates the profit when the
current item is selected.

Breaking it down:

profit[i - 1]:
Profit of the current item.

w - weight[i - 1]:
Remaining capacity after selecting the current item.

dp[i - 1][w - weight[i - 1]]:
Maximum profit obtainable using previous items
with the remaining capacity.

The current item's profit is added to that result.

Formula:

Include =
Current Item Profit +
DP value of previous items with remaining capacity.

LINE 28:
dp[i - 1][w]

Explanation:
- Calculates the profit when the current item is rejected.
- dp[i - 1][w] represents the maximum profit obtainable
  using previous items without changing the capacity.

This is called the EXCLUDE case.

LINE 29:
);

Explanation:
- Ends the max() function call.
- The greater of INCLUDE and EXCLUDE is stored
  in dp[i][w].

IMPORTANT FORMULA:

dp[i][w] = max(
    profit[i-1] + dp[i-1][w-weight[i-1]],
    dp[i-1][w]
)

This is the main recurrence relation of 0/1 Knapsack.

====================================================================
12. ELSE CONDITION EXPLANATION
====================================================================

LINE 30:
else

Explanation:
- Executes when the current item's weight is greater
  than the available capacity.
- The item cannot be selected.

LINE 31:
dp[i][w] = dp[i - 1][w];

Explanation:
- Copies the maximum profit from the previous row.
- The current item is excluded.
- No new profit is added because the item cannot fit.

Example:

Current capacity = 5
Current item weight = 10

Since 10 > 5, the item cannot be selected.

Therefore:
dp[i][5] = dp[i-1][5]

LINE 32:
}

Explanation:
- Ends the inner loop body.

LINE 33:
}

Explanation:
- Ends the outer loop body.
- At this point, the entire DP table has been calculated.

====================================================================
13. DISPLAY FINAL ANSWER
====================================================================

LINE 34:
cout << "\nMaximum Profit: " << dp[n][capacity];

Explanation:
- Displays the maximum profit.
- dp[n][capacity] contains the final answer.
- It represents the maximum profit using all n items
  with the given knapsack capacity.
- \n moves the cursor to a new line.

LINE 35:
return 0;

Explanation:
- Terminates the main function.
- Returns 0 to indicate successful program execution.

LINE 36:
}

Explanation:
- Marks the end of the main function.


====================================================================
14. DYNAMIC PROGRAMMING RECURRENCE RELATION
====================================================================

Let:

n = Number of items
w = Current knapsack capacity
weight[i] = Weight of item i
profit[i] = Profit of item i

Base Condition:

dp[i][w] = 0, if i = 0 or w = 0

If the current item fits:

dp[i][w] = max(
    profit[i-1] + dp[i-1][w-weight[i-1]],
    dp[i-1][w]
)

If the current item does not fit:

dp[i][w] = dp[i-1][w]

The recurrence compares the two possibilities:
- Include the current item.
- Exclude the current item.


====================================================================
15. WORKING OF THE PROGRAM
====================================================================

Steps:

1. Start the program.
2. Accept the number of items.
3. Accept the weight and profit of each item.
4. Accept the knapsack capacity.
5. Create a two-dimensional DP table.
6. Initialize the first row and first column to zero.
7. Traverse the table row by row.
8. Check whether the current item fits.
9. If it fits:
   - Calculate profit by including the item.
   - Calculate profit by excluding the item.
   - Store the maximum of both values.
10. If it does not fit:
    - Copy the previous row's value.
11. Complete the DP table.
12. Display dp[n][capacity].
13. Stop.


====================================================================
16. COMPLETE DRY RUN WITH EXAMPLE
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


STEP 1: INITIALIZE DP TABLE

Rows = n + 1 = 4
Columns = capacity + 1 = 51

Initially:

dp[0][w] = 0 for every capacity.
dp[i][0] = 0 for every number of items.

STEP 2: PROCESS ITEM 1

Weight = 10
Profit = 60

For capacities below 10:
The item cannot fit, so profit = 0.

For capacities 10 and above:
The item can be selected, so profit = 60.

STEP 3: PROCESS ITEM 2

Weight = 20
Profit = 100

For capacity 20:

Include:
100 + dp[1][0] = 100

Exclude:
dp[1][20] = 60

Maximum = 100

For capacity 30:

Include:
100 + dp[1][10] = 160

Exclude:
dp[1][30] = 60

Maximum = 160

For capacity 50:

Include:
100 + dp[1][30] = 160

Exclude:
dp[1][50] = 60

Maximum = 160


STEP 4: PROCESS ITEM 3

Weight = 30
Profit = 120

For capacity 30:

Include:
120 + dp[2][0] = 120

Exclude:
dp[2][30] = 160

Maximum = 160

For capacity 40:

Include:
120 + dp[2][10] = 180

Exclude:
dp[2][40] = 160

Maximum = 180

For capacity 50:

Include:
120 + dp[2][20] = 220

Exclude:
dp[2][50] = 160

Maximum = 220


FINAL DP TABLE:

Capacity | 0 | 10 | 20 | 30 | 40 | 50
----------------------------------------
0 Items  | 0 | 0  | 0  | 0  | 0  | 0
1 Item   | 0 | 60 | 60 | 60 | 60 | 60
2 Items  | 0 | 60 | 100| 160| 160| 160
3 Items  | 0 | 60 | 100| 160| 180| 220

Note:
The complete table has capacities from 0 to 50.
Only selected columns are displayed above.

FINAL ANSWER:

Maximum Profit = 220

Selected Items:

Item 2:
Weight = 20
Profit = 100

Item 3:
Weight = 30
Profit = 120

Total Weight = 20 + 30 = 50

Total Profit = 100 + 120 = 220


====================================================================
17. ALGORITHM
====================================================================

Step 1: Start.

Step 2: Read number of items n.

Step 3: Read weight and profit of all items.

Step 4: Read knapsack capacity.

Step 5: Create DP table of size (n+1) x (capacity+1).

Step 6: Initialize the first row and first column to zero.

Step 7: For each item i from 1 to n:
        For each capacity w from 1 to capacity:

        If weight[i-1] <= w:

            Include =
            profit[i-1] + dp[i-1][w-weight[i-1]]

            Exclude =
            dp[i-1][w]

            dp[i][w] = max(Include, Exclude)

        Otherwise:

            dp[i][w] = dp[i-1][w]

Step 8: Display dp[n][capacity].

Step 9: Stop.


====================================================================
18. TIME AND SPACE COMPLEXITY
====================================================================

Let:
n = Number of items
W = Knapsack capacity

TIME COMPLEXITY:

O(n * W)

Reason:
- The DP table contains (n+1) rows.
- It contains (W+1) columns.
- Every cell requires constant-time computation.
- Therefore, total operations are proportional to n * W.

SPACE COMPLEXITY:

O(n * W)

Reason:
- A two-dimensional DP table is created.
- It contains (n+1) * (W+1) elements.
- Therefore, memory usage depends on both n and W.

IMPORTANT:
This is pseudo-polynomial time complexity because it
depends on the numerical value of capacity W, not merely
the number of bits required to represent W.


====================================================================
19. IMPORTANT DATA STRUCTURES AND CONCEPTS
====================================================================

1. DYNAMIC PROGRAMMING:
   Solves problems using previously calculated results.

2. DP TABLE:
   Stores solutions of smaller subproblems.

3. ARRAY:
   Stores multiple values of the same data type.

4. TWO-DIMENSIONAL ARRAY:
   Stores values in rows and columns.

5. OPTIMIZATION:
   Finding the best possible solution.

6. RECURRENCE RELATION:
   A mathematical formula that defines a problem
   using smaller subproblems.

7. OVERLAPPING SUBPROBLEMS:
   The same smaller problem appears multiple times.

8. OPTIMAL SUBSTRUCTURE:
   An optimal solution can be constructed from
   optimal solutions of smaller subproblems.

9. MAX FUNCTION:
   Returns the larger of two values.

10. BASE CONDITION:
    The initial condition used to start DP calculation.

11. INCLUDE CASE:
    Selecting the current item.

12. EXCLUDE CASE:
    Rejecting the current item.

13. PSEUDO-POLYNOMIAL COMPLEXITY:
    Complexity polynomial in the numerical input value,
    rather than its encoded input length.


====================================================================
20. SAMPLE INPUT AND SAMPLE OUTPUT
====================================================================

SAMPLE INPUT 1:

Enter number of items: 3

Enter weight and profit: 10 60
Enter weight and profit: 20 100
Enter weight and profit: 30 120

Enter knapsack capacity: 50


SAMPLE OUTPUT 1:

Maximum Profit: 220


EXPLANATION:

- Three items are entered.
- Knapsack capacity is 50.
- The best selection is Item 2 and Item 3.
- Total weight = 20 + 30 = 50.
- Total profit = 100 + 120 = 220.


------------------------------------------------------------

SAMPLE INPUT 2:

Enter number of items: 3

Enter weight and profit: 5 10
Enter weight and profit: 4 40
Enter weight and profit: 6 30

Enter knapsack capacity: 10


SAMPLE OUTPUT 2:

Maximum Profit: 70


EXPLANATION:

Possible optimal selection:

Item 2:
Weight = 4
Profit = 40

Item 3:
Weight = 6
Profit = 30

Total weight = 10
Total profit = 70.


------------------------------------------------------------

SAMPLE INPUT 3:

Enter number of items: 2

Enter weight and profit: 5 10
Enter weight and profit: 10 20

Enter knapsack capacity: 5


SAMPLE OUTPUT 3:

Maximum Profit: 10


EXPLANATION:

- Only one item can fit.
- Item 1 gives profit 10.
- Item 2 cannot fit.
- Maximum profit is 10.


------------------------------------------------------------

SAMPLE INPUT 4:

Enter number of items: 2

Enter weight and profit: 5 10
Enter weight and profit: 10 20

Enter knapsack capacity: 0


SAMPLE OUTPUT 4:

Maximum Profit: 0


EXPLANATION:

- Knapsack capacity is zero.
- No positive-weight item can be selected.
- Maximum profit remains zero.


====================================================================
21. VIVA QUESTIONS AND ANSWERS
====================================================================

BASIC VIVA QUESTIONS
--------------------

Q1. What is the Knapsack Problem?

Ans:
It is an optimization problem in which items are selected
to maximize profit without exceeding the capacity.

Q2. What is 0/1 Knapsack?

Ans:
A problem in which each item is either selected completely
or rejected.

Q3. What is the objective of this program?

Ans:
To maximize the total profit using Dynamic Programming.

Q4. Which algorithm is used?

Ans:
Dynamic Programming.

Q5. What is Dynamic Programming?

Ans:
An algorithmic technique that solves problems by storing
and reusing results of smaller subproblems.

Q6. Why is it called 0/1 Knapsack?

Ans:
Because each item has only two choices: selected (1)
or not selected (0).

Q7. Can items be divided in 0/1 Knapsack?

Ans:
No.

Q8. What is the difference between Fractional and
0/1 Knapsack?

Ans:
Fractional allows partial selection, while 0/1 allows
only complete selection or rejection.

Q9. What is an optimization problem?

Ans:
A problem that aims to find the best possible solution.

Q10. Which technique is commonly used for 0/1 Knapsack?

Ans:
Dynamic Programming.


DYNAMIC PROGRAMMING QUESTIONS
-----------------------------

Q11. What is a DP table?

Ans:
A table that stores the results of smaller subproblems.

Q12. Why is Dynamic Programming used?

Ans:
To avoid repeated calculations and improve efficiency.

Q13. What are overlapping subproblems?

Ans:
When the same smaller problem is solved multiple times.

Q14. What is optimal substructure?

Ans:
The property that an optimal solution can be constructed
from optimal solutions of smaller subproblems.

Q15. What is a recurrence relation?

Ans:
A mathematical formula that defines a problem using
smaller subproblems.

Q16. What is memoization?

Ans:
A top-down Dynamic Programming technique that stores
previously calculated results.

Q17. What is tabulation?

Ans:
A bottom-up Dynamic Programming technique that fills
a table using smaller previously calculated results.

Q18. Which approach is used in this program?

Ans:
Bottom-up tabulation.

Q19. What is the base condition?

Ans:
dp[i][w] = 0 when i = 0 or w = 0.

Q20. Why is the base condition necessary?

Ans:
It provides initial values for calculating the
remaining DP table.


ARRAY AND VARIABLE QUESTIONS
----------------------------

Q21. Why are two arrays used?

Ans:
One stores weights and the other stores profits.

Q22. What does weight[] store?

Ans:
The weight of each item.

Q23. What does profit[] store?

Ans:
The profit of each item.

Q24. What does capacity represent?

Ans:
The maximum weight the knapsack can carry.

Q25. What does n represent?

Ans:
The total number of items.

Q26. What does dp[i][w] represent?

Ans:
The maximum profit using the first i items with
capacity w.

Q27. Why is the DP table two-dimensional?

Ans:
Because the result depends on two variables:
number of available items and knapsack capacity.


DP TABLE QUESTIONS
------------------

Q28. Why is the DP table size n+1?

Ans:
To include the zero-item base case.

Q29. Why is the DP table size capacity+1?

Ans:
To include the zero-capacity base case.

Q30. Why is the first row initialized to zero?

Ans:
Because no profit can be obtained with zero items.

Q31. Why is the first column initialized to zero?

Ans:
Because no positive-weight item can fit into zero capacity.

Q32. Why do we use i-1?

Ans:
Because arrays use zero-based indexing, whereas the
DP table uses row 1 for the first item.

Q33. What does dp[n][capacity] represent?

Ans:
The maximum profit using all items and the given capacity.

Q34. What is the purpose of nested loops?

Ans:
To calculate every cell of the DP table.


RECURRENCE RELATION QUESTIONS
----------------------------

Q35. What is the recurrence relation?

Ans:

dp[i][w] = max(
    profit[i-1] + dp[i-1][w-weight[i-1]],
    dp[i-1][w]
)

when the current item fits.

Q36. What is the include case?

Ans:
Selecting the current item and adding its profit.

Q37. What is the exclude case?

Ans:
Not selecting the current item.

Q38. Why do we use max()?

Ans:
To select the choice that gives the greater profit.

Q39. What happens if the item does not fit?

Ans:
We copy the result from the previous row.

Q40. Why do we use dp[i-1] instead of dp[i]?

Ans:
Because each item can be selected only once. We must
use the previous row to avoid selecting the same item
multiple times.


COMPLEXITY QUESTIONS
--------------------

Q41. What is the time complexity?

Ans:
O(nW), where W is the knapsack capacity.

Q42. What is the space complexity?

Ans:
O(nW).

Q43. Why is time complexity O(nW)?

Ans:
Because the DP table contains approximately n times W
cells, and each cell takes constant time to calculate.

Q44. What is pseudo-polynomial complexity?

Ans:
Complexity polynomial in the numerical value of an input,
rather than its binary representation length.

Q45. Can space complexity be optimized?

Ans:
Yes. A one-dimensional DP array can reduce space
complexity to O(W).

Q46. What is the disadvantage of Dynamic Programming?

Ans:
It can require considerable memory and computation
for large capacities.


ADVANCED AND TRICKY EXTERNAL VIVA QUESTIONS
-------------------------------------------

Q47. Why is Greedy Algorithm not always optimal for
0/1 Knapsack?

Ans:
Because selecting the item with the highest ratio
may prevent a better combination of complete items.

Q48. Can Fractional Knapsack be solved using Greedy?

Ans:
Yes. Sorting by profit-to-weight ratio gives an optimal
solution.

Q49. What is the difference between memoization and
tabulation?

Ans:
Memoization is top-down, while tabulation is bottom-up.

Q50. What happens if we change max() to min()?

Ans:
The program will minimize the profit choices instead
of maximizing them.

Q51. What happens if we use dp[i][w-weight[i-1]] instead
of dp[i-1][w-weight[i-1]]?

Ans:
The recurrence may select the same item multiple times.
It becomes similar to an unbounded knapsack recurrence.

Q52. Why is dp[i-1][w] used in the exclude case?

Ans:
It represents the best profit without selecting the
current item.

Q53. What happens if an item's weight is greater than
the capacity?

Ans:
That item is excluded.

Q54. What happens if capacity is zero?

Ans:
Maximum profit is zero.

Q55. What happens if all item profits are zero?

Ans:
Maximum profit remains zero.

Q56. What happens if all item weights are greater than
the capacity?

Ans:
No item can be selected, so maximum profit is zero.

Q57. What is the difference between 0/1 Knapsack and
Unbounded Knapsack?

Ans:
0/1 allows each item at most once, while Unbounded
Knapsack allows repeated selection of items.

Q58. What is the difference between a greedy approach
and Dynamic Programming?

Ans:
Greedy makes a locally optimal choice at each step,
while Dynamic Programming compares and stores solutions
of subproblems.

Q59. Can this program find which items were selected?

Ans:
The current program only prints the maximum profit.
We can trace the DP table backward to identify selected
items.

Q60. Why is the first row zero?

Ans:
It represents the case where no items are available.

Q61. Why is the first column zero?

Ans:
It represents zero knapsack capacity.

Q62. What happens if we use <= instead of < in the
loop condition?

Ans:
It is already using <= so that the zero-item row and
zero-capacity column are included.

Q63. What is the maximum profit for the following?

Weights = 2, 3, 4
Profits = 4, 5, 6
Capacity = 5

Ans:
Maximum profit = 9 by selecting the first and second items.

Q64. Can we solve 0/1 Knapsack recursively?

Ans:
Yes, by considering include and exclude choices.

Q65. What is the time complexity of the basic recursive
0/1 Knapsack algorithm?

Ans:
O(2^n) in the worst case.

Q66. What is the time complexity of DP 0/1 Knapsack?

Ans:
O(nW).

Q67. What happens if an item's weight is zero?

Ans:
The program may select that item when it has positive
profit, but it does not validate negative weights
or other invalid input.

Q68. What happens if the number of items is zero?

Ans:
The answer is zero, assuming the program is given a
valid non-negative capacity and the arrays are handled
by the compiler.

Q69. What is the importance of optimal substructure?

Ans:
It allows the optimal solution to be constructed from
optimal solutions of smaller subproblems.

Q70. Give real-world applications of 0/1 Knapsack.

Ans:
- Budget allocation.
- Cargo selection.
- Project selection.
- Resource allocation.
- Investment planning.
- Storage optimization.


====================================================================
22. IMPORTANT DIFFERENCES: 0/1 VS FRACTIONAL KNAPSACK
====================================================================

0/1 KNAPSACK:

1. Items cannot be divided.
2. Each item is selected once or rejected.
3. Dynamic Programming is commonly used.
4. Time complexity: O(nW).
5. Ratio-based Greedy is not always optimal.

FRACTIONAL KNAPSACK:

1. Items can be divided.
2. Partial selection is allowed.
3. Greedy Algorithm is optimal.
4. Time complexity: O(n log n).
5. Items are sorted by profit-to-weight ratio.


====================================================================
23. IMPORTANT POINTS TO REMEMBER FOR EXTERNAL VIVA
====================================================================

1. 0/1 Knapsack is an optimization problem.
2. It uses Dynamic Programming.
3. Items cannot be divided.
4. A two-dimensional DP table is used.
5. dp[i][w] represents maximum profit.
6. The base condition is zero items or zero capacity.
7. The recurrence compares include and exclude cases.
8. max() selects the better result.
9. Time complexity is O(nW).
10. Space complexity is O(nW).
11. This program uses bottom-up tabulation.
12. The final answer is dp[n][capacity].
13. Ratio-based Greedy is not always optimal for 0/1 Knapsack.
14. One-dimensional DP can optimize the space to O(W).

====================================================================
                    END OF EXPLANATION
====================================================================
*/