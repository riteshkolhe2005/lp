
import java.util.*;

class Item
{
    int weight;
    int value;

    Item(int weight, int value)
    {
        this.weight = weight;
        this.value = value;
    }
}

class FractionalKnapsack
{
    public static double fractionalKnapsack(int W, Item items[])
    {
        Arrays.sort(items, (a, b) ->
        {
            double r1 = (double) a.value / a.weight;
            double r2 = (double) b.value / b.weight;

            return Double.compare(r2, r1);
        });

        double totalValue = 0;

        for(int i = 0; i < items.length; i++)
        {
            if(W == 0)break;

            if(items[i].weight <= W)
            {
                totalValue += items[i].value;
                W -= items[i].weight;
            }
            else
            {
                totalValue += (double) items[i].value
                              * W / items[i].weight;
                W = 0;
            }
        }
        return totalValue;
    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of items: ");
        int n = sc.nextInt();

        Item items[] = new Item[n];

        for(int i = 0; i < n; i++)
        {
            System.out.print("Enter weight of item " + (i+1) + ": ");
            int weight = sc.nextInt();

            System.out.print("Enter value of item " + (i+1) + ": ");
            int value = sc.nextInt();

            items[i] = new Item(weight, value);
        }

        System.out.print("Enter Knapsack Capacity: ");
        int W = sc.nextInt();

        System.out.println("Maximum Value = " +
            fractionalKnapsack(W, items));

        sc.close();
    }
}

/*
================================================================
1. HOW TO EXPLAIN THIS PROGRAM TO AN EXTERNAL EXAMINER
================================================================

"Sir/Mam, this program implements Fractional Knapsack using
the Greedy Algorithm.

Fractional Knapsack is an optimization problem in which we
have a knapsack with limited capacity and multiple items
having different weights and values.

Our objective is to maximize the total value of items placed
inside the knapsack.

First, we accept the number of items, their weights,
their values, and the knapsack capacity from the user.

Then, we calculate the value-to-weight ratio of every item.

After that, we sort the items in descending order of their
value-to-weight ratio.

We select the items having the highest ratio first.

If the complete item fits inside the remaining capacity,
we include the entire item.

Otherwise, we include only the fraction of the item that
fits inside the remaining capacity.

Finally, we calculate and return the maximum total value.

This approach uses the Greedy Algorithm to obtain the
optimal solution."


================================================================
2. IMPORTANT CONCEPTS
================================================================

1. FRACTIONAL KNAPSACK:
   It is an optimization problem in which we can take either
   the complete item or a fraction of an item.

2. GREEDY ALGORITHM:
   An algorithm that makes the locally optimal choice at
   each step to achieve an overall optimal solution.

   Here, we select the item having the highest
   value-to-weight ratio first.

3. VALUE-TO-WEIGHT RATIO:
   It represents the value obtained per unit of weight.

   Formula:

   Ratio = Value / Weight

4. KNAPSACK CAPACITY:
   It represents the maximum weight that the knapsack
   can hold.

5. FRACTIONAL SELECTION:
   If an entire item cannot fit, we take only the fraction
   that fits into the remaining capacity.

6. ARRAYS.SORT():
   It is a Java method used to sort array elements.

   Here, it sorts items according to their
   value-to-weight ratio in descending order.

7. LAMBDA EXPRESSION:
   It provides a short way to implement a Comparator.

   Here, it compares two items based on their ratios.

8. COMPARATOR:
   It is used to define custom sorting logic.

9. DOUBLE:
   It is a Java data type used to store decimal values.

   It is required because fractional items can produce
   decimal values.

10. OPTIMAL SOLUTION:
    A solution that gives the maximum possible total value
    without exceeding the knapsack capacity.

11. TIME COMPLEXITY:
    Sorting: O(n log n)
    Traversal: O(n)

    Overall Time Complexity: O(n log n)

    Space Complexity: O(n) for the array of items.
    Auxiliary space depends on the sorting implementation.

    Here, n represents the number of items.


================================================================
3. SAMPLE INPUT
================================================================

Enter number of items: 3

Enter weight of item 1: 10
Enter value of item 1: 60

Enter weight of item 2: 20
Enter value of item 2: 100

Enter weight of item 3: 30
Enter value of item 3: 120

Enter Knapsack Capacity: 50


================================================================
4. EXPECTED OUTPUT
================================================================

Maximum Value = 240.0

NOTE:
The output is calculated by selecting complete items
and a fraction of the last item if required.


================================================================
5. STEP-BY-STEP LOGIC / DRY RUN
================================================================

INPUT:

Item       Weight       Value       Ratio
1          10           60          6
2          20           100         5
3          30           120         4

Knapsack Capacity = 50

STEP 1:
Calculate the value-to-weight ratio.

Ratio = Value / Weight

Item 1 = 60 / 10 = 6
Item 2 = 100 / 20 = 5
Item 3 = 120 / 30 = 4

STEP 2:
Sort the items in descending order of ratio.

Item 1 (Ratio 6)
Item 2 (Ratio 5)
Item 3 (Ratio 4)

STEP 3:
Select Item 1.

Weight = 10
Value = 60

Remaining Capacity = 50 - 10 = 40

Total Value = 60

STEP 4:
Select Item 2.

Weight = 20
Value = 100

Remaining Capacity = 40 - 20 = 20

Total Value = 60 + 100 = 160

STEP 5:
Item 3 has weight 30, but remaining capacity is only 20.

Therefore, select a fraction of Item 3.

Fraction = 20 / 30

Value Added = 120 * 20 / 30

Value Added = 80

STEP 6:
Calculate the final maximum value.

Total Value = 60 + 100 + 80

Maximum Value = 240

STEP 7:
Knapsack is completely filled.

Remaining Capacity = 0


================================================================
6. EXPECTED EXTERNAL VIVA QUESTIONS WITH ANSWERS
================================================================

Q1. What is Fractional Knapsack?

Ans: Fractional Knapsack is an optimization problem in
which we can select complete items or fractions of items
to maximize the total value.

Q2. Which algorithm is used in Fractional Knapsack?

Ans: Greedy Algorithm.

Q3. Why is Fractional Knapsack called a Greedy Algorithm?

Ans: Because we select the item having the highest
value-to-weight ratio at every step.

Q4. What is the formula for value-to-weight ratio?

Ans: Ratio = Value / Weight.

Q5. Why do we sort items in descending order?

Ans: To select the items having the highest
value-to-weight ratio first.

Q6. What is the purpose of Arrays.sort()?

Ans: It sorts the items according to their
value-to-weight ratio.

Q7. What is the purpose of Double.compare()?

Ans: It compares two double values and returns a value
indicating their relative order.

Q8. Why do we use double instead of int?

Ans: Because fractional selection can produce decimal
values, so double is required to store the result.

Q9. What is the purpose of the Item class?

Ans: It stores the weight and value of each item.

Q10. What is the purpose of the constructor?

Ans: It initializes the weight and value of an item.

Q11. What does this.weight mean?

Ans: It refers to the instance variable weight of the
current object.

Q12. What is the purpose of totalValue?

Ans: It stores the accumulated value of the selected items.

Q13. Why do we check items[i].weight <= W?

Ans: To check whether the complete item can fit inside
the remaining knapsack capacity.

Q14. What happens if the complete item does not fit?

Ans: We select only the fraction that fits into the
remaining capacity.

Q15. What is the formula for fractional value?

Ans:
Fractional Value = (Item Value * Remaining Capacity)
                   / Item Weight.

Q16. Why do we write W = 0?

Ans: Because the knapsack becomes completely full after
selecting the required fraction of the item.

Q17. What is the purpose of if(W == 0) break?

Ans: It stops the loop when the knapsack has no remaining
capacity.

Q18. What is the time complexity of Fractional Knapsack?

Ans: O(n log n), because sorting takes O(n log n) time
and traversal takes O(n) time.

Q19. What is the space complexity?

Ans: O(n) for storing the array of items. The auxiliary
space used by sorting depends on the implementation.

Q20. What is the difference between Fractional and
0/1 Knapsack?

Ans:
Fractional Knapsack:
We can select fractions of items.

0/1 Knapsack:
We can either select the complete item or reject it.
Fractions are not allowed.

Q21. Is Greedy Algorithm optimal for Fractional Knapsack?

Ans: Yes, selecting items in descending order of
value-to-weight ratio gives an optimal solution.

Q22. Is Greedy Algorithm always optimal for 0/1 Knapsack?

Ans: No. The greedy approach does not always give the
optimal solution for 0/1 Knapsack.

Q23. What is Scanner in Java?

Ans: Scanner is a class used to accept input from the user.

Q24. What does nextInt() do?

Ans: It reads an integer value from the user.

Q25. What does sc.close() do?

Ans: It closes the Scanner object.

Q26. What is an optimization problem?

Ans: A problem in which we try to find the best possible
solution by maximizing or minimizing an objective.

Q27. Why do we use typecasting (double)?

Ans: To perform floating-point division instead of
integer division.

Q28. What is the advantage of Fractional Knapsack?

Ans: It provides an optimal solution using a simple
Greedy approach.

Q29. What happens if the knapsack capacity is zero?

Ans: No items are selected, and the maximum value is zero.

Q30. Where is the Knapsack Problem used?

Ans:
1. Resource allocation.
2. Cargo loading.
3. Budget optimization.
4. Investment selection.
5. Storage optimization.


================================================================
7. EXECUTION COMMANDS
================================================================

REQUIREMENT:
Java JDK must be installed.

WINDOWS:

Step 1: Save the file as:

FractionalKnapsack.java

Step 2: Open CMD in the folder containing the file.

Step 3: Compile:

javac FractionalKnapsack.java

Step 4: Run:

java FractionalKnapsack


LINUX (UBUNTU):

Step 1: Save the file as:

FractionalKnapsack.java

Step 2: Open Terminal in the folder containing the file.

Step 3: Compile:

javac FractionalKnapsack.java

Step 4: Run:

java FractionalKnapsack


CHECK JAVA INSTALLATION:

java -version

javac -version


================================================================
8. IMPORTANT POINTS TO REMEMBER BEFORE VIVA
================================================================

1. Algorithm: Greedy Algorithm.
2. Problem: Fractional Knapsack.
3. Data Structure: Array of Objects.
4. Sorting: Arrays.sort().
5. Sorting Order: Descending.
6. Ratio: Value / Weight.
7. Complete Selection: When item weight <= remaining capacity.
8. Fractional Selection: When item weight > remaining capacity.
9. Result Variable: totalValue.
10. Return Type: double.
11. Time Complexity: O(n log n).
12. Space Complexity: O(n) including item storage.
13. Main Function: main().
14. Calculation Function: fractionalKnapsack().
15. Scanner: Used for user input.

ONE-LINE CONCLUSION:

Fractional Knapsack is a Greedy Algorithm that selects
items according to their value-to-weight ratio to maximize
the total value without exceeding the given knapsack capacity.

================================================================
*/
