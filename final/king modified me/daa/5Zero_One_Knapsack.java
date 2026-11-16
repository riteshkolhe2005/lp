import java.util.Scanner;
class Zero_One_Knapsack 
{
    public static int zeroOneKnapsack(int wt[],int val[],int n,int W)
    {
        int dp[][]=new int[n+1][W+1];

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=W;j++)
            {
                if(wt[i-1]<=j)
                {
                    dp[i][j]=Math.max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][W];
    }
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of items: ");
        int n = sc.nextInt();

        int val[] = new int[n];
        int wt[] = new int[n];

        for(int i = 0; i < n; i++)
        {
            System.out.print("Enter weight of item " + (i+1) + ": ");
            wt[i] = sc.nextInt();

            System.out.print("Enter value of item " + (i+1) + ": ");
            val[i] = sc.nextInt();
        }

        System.out.print("Enter Knapsack Capacity: ");
        int W = sc.nextInt();

        System.out.println("Maximum value in 0-1 Knapsack = " +
        zeroOneKnapsack(wt, val, n, W));

        sc.close();
    }
}

/*
=========================================================
1. LINE-BY-LINE EXPLANATION
=========================================================

import java.util.Scanner;
- Imports Scanner class.
- Scanner is used to accept input from the keyboard.

class Zero_One_Knapsack
- Defines a class named Zero_One_Knapsack.
- Java programs contain classes.

public static int zeroOneKnapsack(...)
- Defines a method that implements the 0/1 Knapsack algorithm.
- public: Accessible from anywhere.
- static: Can be called without creating an object.
- int: Returns an integer value.
- wt[]: Array containing weights of items.
- val[]: Array containing values of items.
- n: Total number of items.
- W: Maximum knapsack capacity.

int dp[][] = new int[n+1][W+1];
- Creates a two-dimensional DP (Dynamic Programming) table.
- Rows represent items.
- Columns represent knapsack capacities.
- n+1 and W+1 are used because indexing starts from zero.
- Initially, all elements contain 0.

for(int i=1; i<=n; i++)
- Iterates through all available items.
- i represents the current item number in the DP table.

for(int j=1; j<=W; j++)
- Iterates through all possible capacities.
- j represents the current knapsack capacity.

if(wt[i-1] <= j)
- Checks whether the current item can fit into the knapsack.
- wt[i-1] represents the weight of the current item.
- i-1 is used because array indexing starts from zero.

dp[i][j] = Math.max(dp[i-1][j],
                    val[i-1]+dp[i-1][j-wt[i-1]]);

- If the item fits, we have two choices:

  1. EXCLUDE the current item:
     dp[i-1][j]

  2. INCLUDE the current item:
     val[i-1] + dp[i-1][j-wt[i-1]]

- Math.max() selects the maximum value between these choices.
- Notice that both choices use the previous row (i-1).
- This ensures that an item cannot be selected more than once.

else
- Executes when the current item weight is greater than
  the available capacity.

dp[i][j] = dp[i-1][j];
- The current item cannot fit.
- Therefore, we exclude it.
- The previous maximum value is copied.

return dp[n][W];
- Returns the maximum value possible.
- dp[n][W] represents the answer using all items
  with the given knapsack capacity.

---------------- MAIN METHOD ----------------

public static void main(String args[])
- Starting point of Java program execution.

Scanner sc = new Scanner(System.in);
- Creates Scanner object to accept user input.

int n = sc.nextInt();
- Accepts the total number of items.

int val[] = new int[n];
- Creates an array to store item values.

int wt[] = new int[n];
- Creates an array to store item weights.

for(int i=0; i<n; i++)
- Iterates through all items to accept their details.

wt[i] = sc.nextInt();
- Accepts the weight of the current item.

val[i] = sc.nextInt();
- Accepts the value of the current item.

int W = sc.nextInt();
- Accepts the maximum knapsack capacity.

zeroOneKnapsack(wt, val, n, W)
- Calls the knapsack method.
- Passes weight array, value array, number of items
  and capacity as arguments.

System.out.println()
- Displays the maximum obtainable value.

sc.close();
- Closes the Scanner object.


=========================================================
2. PROGRAM LOGIC (HOW TO EXPLAIN TO EXTERNAL EXAMINER)
=========================================================

"This program implements the 0/1 Knapsack problem using
Dynamic Programming.

First, we accept the number of items, their weights,
their values and the maximum capacity of the knapsack.

Then, we create a two-dimensional DP table.

The rows represent the items and the columns represent
the knapsack capacity.

For every item, we check whether its weight is less than
or equal to the current capacity.

If the item fits, we have two choices:

1. Include the item and add its value to the best result
   obtained using the remaining capacity.

2. Exclude the item and retain the previous maximum value.

We use Math.max() to select the better option.

If the item does not fit, we simply exclude it.

Finally, dp[n][W] gives us the maximum value that can
be obtained without exceeding the knapsack capacity."

IMPORTANT:
In 0/1 Knapsack, each item can either be selected once
or not selected at all. We cannot select an item multiple
times.


=========================================================
3. IMPORTANT CONCEPTS
=========================================================

A. What is Knapsack Problem?

It is an optimization problem in which we have a bag
with limited capacity and multiple items having different
weights and values.

Our objective is to maximize the total value without
exceeding the capacity.

B. What is 0/1 Knapsack?

Each item has only two possibilities:
- 1 = Item is selected.
- 0 = Item is not selected.

An item cannot be divided or selected multiple times.

C. What is Dynamic Programming?

Dynamic Programming is an algorithmic technique that
breaks a complex problem into smaller overlapping
subproblems and stores their results to avoid
recalculating them.

D. What is a DP Table?

A DP table stores the solutions of smaller subproblems.

In this program:
- Rows represent items.
- Columns represent capacities.
- Each cell stores the maximum value possible.

E. Recurrence Relation:

If wt[i-1] <= j:

dp[i][j] = max(
    dp[i-1][j],
    val[i-1] + dp[i-1][j-wt[i-1]]
)

Otherwise:

dp[i][j] = dp[i-1][j]

F. Why do we use a 2D array?

Because we need to store results for different
combinations of items and capacities.

G. Time Complexity:

O(n * W)

Where:
n = Number of items.
W = Knapsack capacity.

H. Space Complexity:

O(n * W)

Because we use a 2D DP array of size
(n+1) * (W+1).


=========================================================
4. EXPECTED EXTERNAL VIVA QUESTIONS WITH ANSWERS
=========================================================

Q1. What is the 0/1 Knapsack problem?

Ans: It is an optimization problem in which we select
items to maximize total value without exceeding the
knapsack capacity. Each item can be selected only once.

Q2. Which algorithmic technique is used?

Ans: Dynamic Programming.

Q3. Why is it called 0/1 Knapsack?

Ans: Because each item has only two choices:
either select it (1) or reject it (0).

Q4. What is Dynamic Programming?

Ans: It is a technique that solves complex problems
by dividing them into smaller subproblems and storing
their results.

Q5. What is the difference between 0/1 Knapsack and
Fractional Knapsack?

Ans:
0/1 Knapsack:
- Items cannot be divided.
- Each item is selected completely or rejected.
- Dynamic Programming can solve it.

Fractional Knapsack:
- Items can be divided.
- We can select fractions of items.
- Greedy approach is used.

Q6. Why do we use Math.max()?

Ans: To choose the maximum value between including
and excluding the current item.

Q7. What does dp[i][j] represent?

Ans: Maximum value obtainable using the first i items
with knapsack capacity j.

Q8. Why do we use n+1 and W+1?

Ans: To include the base cases of zero items and
zero capacity.

Q9. What is the base condition?

Ans: When there are zero items or zero capacity,
the maximum value is zero.

Q10. What is the time complexity?

Ans: O(n * W).

Q11. What is the space complexity?

Ans: O(n * W).

Q12. Can we select the same item multiple times?

Ans: No. Each item can be selected at most once.

Q13. What is the difference between Greedy and
Dynamic Programming?

Ans:
Greedy makes the locally optimal choice at each step.
Dynamic Programming considers multiple possibilities
and stores their optimal results.

Q14. What is an overlapping subproblem?

Ans: When the same smaller problem is solved multiple
times during the execution of an algorithm.

Q15. What is optimal substructure?

Ans: A problem has optimal substructure when its
optimal solution can be constructed using optimal
solutions of smaller subproblems.

Q16. Can 0/1 Knapsack be solved using recursion?

Ans: Yes. It can be solved using recursion, but
Dynamic Programming avoids repeated calculations.

Q17. What happens if an item is heavier than the
knapsack capacity?

Ans: That item cannot be selected.

Q18. Is this a bottom-up or top-down approach?

Ans: Bottom-up approach because we solve smaller
subproblems first and gradually build the final answer.

Q19. Can we use a one-dimensional DP array?

Ans: Yes. Space can be optimized to O(W) using
a one-dimensional DP array and iterating capacities
in descending order.

Q20. Where is the Knapsack problem used?

Ans:
- Resource allocation.
- Budget optimization.
- Cargo loading.
- Investment selection.
- Project selection.


=========================================================
5. SAMPLE INPUT AND OUTPUT
=========================================================

INPUT:

Enter number of items: 3

Enter weight of item 1: 10
Enter value of item 1: 60

Enter weight of item 2: 20
Enter value of item 2: 100

Enter weight of item 3: 30
Enter value of item 3: 120

Enter Knapsack Capacity: 50


OUTPUT:

Maximum value in 0-1 Knapsack = 220


EXPLANATION:

Available items:

Item 1: Weight = 10, Value = 60
Item 2: Weight = 20, Value = 100
Item 3: Weight = 30, Value = 120

Knapsack capacity = 50

Best selection:
- Item 2 (Weight 20, Value 100)
- Item 3 (Weight 30, Value 120)

Total weight = 20 + 30 = 50
Total value = 100 + 120 = 220

Therefore, maximum value = 220.


=========================================================
6. COMMANDS TO RUN THE PROGRAM
=========================================================

IMPORTANT:
Save the file as:

Zero_One_Knapsack.java

WINDOWS:

Step 1: Open CMD or Terminal in the folder containing
        your Java file.

Step 2: Compile:

javac Zero_One_Knapsack.java

Step 3: Execute:

java Zero_One_Knapsack


LINUX (UBUNTU):

Step 1: Open Terminal in the project directory.

Step 2: Compile:

javac Zero_One_Knapsack.java

Step 3: Execute:

java Zero_One_Knapsack


If Java is not installed, install the JDK first.

Ubuntu:

sudo apt update
sudo apt install default-jdk

Windows:
Install a JDK and configure its bin directory in PATH.

Check Java installation:

java -version
javac -version


=========================================================
7. QUICK REVISION BEFORE VIVA
=========================================================

Program Name: 0/1 Knapsack

Algorithm: Dynamic Programming

Approach: Bottom-Up

Data Structure: 2D Array

Time Complexity: O(n * W)

Space Complexity: O(n * W)

Main Function: zeroOneKnapsack()

Important Method: Math.max()

DP Table: dp[n+1][W+1]

Objective: Maximize total value without exceeding
knapsack capacity.

MOST IMPORTANT VIVA ANSWER:

"If the item fits, we compare the value obtained by
including it and excluding it. We select the maximum.
If it does not fit, we exclude it."

=========================================================
END OF EXPLANATION
=========================================================
*/