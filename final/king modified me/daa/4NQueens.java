import java.util.*;
class NQueens
{
    static int board[][];
    static int fixedRow;

    static boolean isSafe(int row, int col, int n)
    {
        for(int i = 0; i < n; i++)
        {
            if(i == row)
                continue;

            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 1)
                {
                    if(j == col || Math.abs(i - row) == Math.abs(j - col))
                        return false;
                }
            }
        }
        return true;
    }

    static boolean solve(int row, int n)
    {
        if(row == n)
            return true;

        if(row == fixedRow)
            return solve(row + 1, n);

        for(int col = 0; col < n; col++)
        {
            if(isSafe(row, col, n))
            {
                board[row][col] = 1;

                if(solve(row + 1, n))
                    return true;

                board[row][col] = 0;   
            }
        }
        return false;
    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter N: ");
        int n = sc.nextInt();

        if(n <= 0)
        {
            System.out.println("Invalid N");
            return;
        }

        board = new int[n][n];

        System.out.print("Enter first Queen row (0 to " + (n-1) + "): ");
        int row = sc.nextInt();

        System.out.print("Enter first Queen column (0 to " + (n-1) + "): ");
        int col = sc.nextInt();

        if(row < 0 || row >= n || col < 0 || col >= n)
        {
            System.out.println("Invalid position");
            return;
        }

        fixedRow = row;
        board[row][col] = 1;

        if(solve(0, n))
        {
            System.out.println("\nN-Queens Matrix:");
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                    System.out.print(board[i][j] + " ");
                System.out.println();
            }
        }
        else
        {
            System.out.println("Solution does not exist.");
        }

        sc.close();
    }
}

/*
===========================================================
1. LINE-BY-LINE CODE EXPLANATION
===========================================================

1. import java.util.*;
   - Imports utility classes from Java.
   - Scanner class is used to accept input from the user.

2. class NQueens
   - Defines a class named NQueens.
   - Java programs contain classes.

3. static int board[][];
   - Declares a 2D integer array.
   - Represents the chessboard.
   - 1 represents a queen.
   - 0 represents an empty position.

4. static int fixedRow;
   - Stores the row number of the already placed queen.
   - This queen cannot be moved.

5. static boolean isSafe(int row, int col, int n)
   - Checks whether placing a queen at the given position
     is safe or not.
   - Returns true if safe, otherwise false.

6. for(int i = 0; i < n; i++)
   - Iterates through all rows of the chessboard.

7. if(i == row)
       continue;
   - Skips the current row.
   - Only one queen is placed in each row by the algorithm.

8. for(int j = 0; j < n; j++)
   - Iterates through all columns.

9. if(board[i][j] == 1)
   - Checks whether a queen is already present
     at the current position.

10. if(j == col || Math.abs(i - row) == Math.abs(j - col))
    - Checks two attacking conditions:
      a) Same column: j == col
      b) Same diagonal:
         Absolute row difference equals absolute column difference.
    - If either condition is true, the position is unsafe.

11. return false;
    - Indicates that the position is unsafe.

12. return true;
    - Indicates that the position is safe.

13. static boolean solve(int row, int n)
    - Recursive function used to solve the N-Queens problem.
    - Uses the Backtracking technique.

14. if(row == n)
        return true;
    - Base condition of recursion.
    - If all rows have been processed, a solution is found.

15. if(row == fixedRow)
        return solve(row + 1, n);
    - Skips the row containing the initially placed queen.
    - The initially placed queen remains fixed.

16. for(int col = 0; col < n; col++)
    - Tries every column in the current row.

17. if(isSafe(row, col, n))
    - Checks whether the current position is safe.

18. board[row][col] = 1;
    - Places a queen at the safe position.

19. if(solve(row + 1, n))
        return true;
    - Recursively solves the next row.
    - If a solution is found, returns true.

20. board[row][col] = 0;
    - Removes the previously placed queen.
    - This happens when the selected position does not
      lead to a valid solution.
    - This step is called BACKTRACKING.

21. return false;
    - Indicates that no valid position was found
      in the current row.

22. public static void main(String args[])
    - Main method.
    - Execution of the Java program starts here.

23. Scanner sc = new Scanner(System.in);
    - Creates Scanner object to accept user input.

24. int n = sc.nextInt();
    - Accepts the size of the chessboard.

25. if(n <= 0)
    - Checks whether N is valid.
    - N must be greater than zero.

26. board = new int[n][n];
    - Creates an N × N chessboard.
    - Initially, all positions contain zero.

27. int row = sc.nextInt();
    - Accepts the row position of the first queen.

28. int col = sc.nextInt();
    - Accepts the column position of the first queen.

29. if(row < 0 || row >= n || col < 0 || col >= n)
    - Checks whether the entered position is within
      the chessboard boundaries.

30. fixedRow = row;
    - Stores the row of the first queen.

31. board[row][col] = 1;
    - Places the first queen permanently on the board.

32. if(solve(0, n))
    - Calls the recursive solving function.
    - Starts processing from row zero.

33. System.out.println("\nN-Queens Matrix:");
    - Displays the solution heading.

34. for(int i = 0; i < n; i++)
    - Iterates through all rows.

35. for(int j = 0; j < n; j++)
    - Iterates through all columns.

36. System.out.print(board[i][j] + " ");
    - Prints the chessboard values.

37. System.out.println();
    - Moves to the next line after printing one row.

38. else
    - Executes if no valid solution exists.

39. System.out.println("Solution does not exist.");
    - Displays that no solution was found.

40. sc.close();
    - Closes the Scanner object.


===========================================================
2. PROGRAM LOGIC - HOW TO EXPLAIN TO EXTERNAL EXAMINER
===========================================================

"This program implements the N-Queens problem using
the Backtracking algorithm.

First, we accept the size N of the chessboard from
the user and create an N × N matrix.

Then we accept the position of the first queen.
This queen is fixed and cannot be moved.

After that, we call the solve() recursive function.

The solve() function tries to place one queen in
each remaining row.

Before placing a queen, the isSafe() function checks
whether the position is valid.

A queen can attack another queen horizontally,
vertically, and diagonally.

If the position is safe, we place the queen and
recursively move to the next row.

If we reach a situation where no valid position
is available, we remove the previously placed queen
and try another position.

This process is called Backtracking.

When all rows are successfully processed, the
program displays the chessboard matrix.

If no valid arrangement is possible, it displays
that the solution does not exist."


===========================================================
3. IMPORTANT CONCEPTS
===========================================================

A) N-QUEENS PROBLEM

- It is a classical problem in computer science.
- The objective is to place N queens on an N × N
  chessboard.
- No two queens should attack each other.
- No two queens can share the same row, column,
  or diagonal.

B) BACKTRACKING

- Backtracking is an algorithmic technique.
- It tries to find a solution step by step.
- If a choice does not lead to a valid solution,
  it goes back and tries another choice.
- In this program, an incorrectly placed queen
  is removed by:

  board[row][col] = 0;

C) RECURSION

- Recursion means a function calling itself.
- The solve() function calls itself for the next row.
- Recursion continues until all rows are processed
  or no valid arrangement is possible.

D) 2D ARRAY

- A two-dimensional array stores data in rows
  and columns.
- Here, it represents the chessboard.
- Example: int board[4][4];

E) Math.abs()

- Returns the absolute (positive) value of a number.
- Used to check diagonal attacks.

F) DIAGONAL CONDITION

Math.abs(i - row) == Math.abs(j - col)

- If the difference between row numbers equals
  the difference between column numbers,
  both positions lie on the same diagonal.

G) STATIC KEYWORD

- Static variables and methods belong to the class.
- They can be accessed without creating an object.
- Here, board, fixedRow, isSafe(), and solve()
  are static.


===========================================================
4. TIME AND SPACE COMPLEXITY
===========================================================

Time Complexity:
- Worst-case time complexity: O(N!)
- The algorithm tries different queen arrangements.
- Backtracking reduces unnecessary possibilities.

Space Complexity:
- O(N²) for the chessboard.
- O(N) for the recursive function call stack.
- Overall space complexity: O(N²).


===========================================================
5. EXPECTED EXTERNAL VIVA QUESTIONS WITH ANSWERS
===========================================================

Q1. What is the N-Queens problem?
Ans. It is a problem of placing N queens on an
     N × N chessboard such that no two queens
     attack each other.

Q2. Which algorithm is used in this program?
Ans. Backtracking algorithm.

Q3. What is Backtracking?
Ans. Backtracking is a technique that tries different
     possibilities and goes back when a choice fails.

Q4. Why is Backtracking used?
Ans. It helps find a valid solution by eliminating
     choices that cannot lead to a solution.

Q5. How does a queen move in chess?
Ans. A queen can move horizontally, vertically,
     and diagonally.

Q6. What does isSafe() do?
Ans. It checks whether a queen can be placed at a
     particular position without attacking another queen.

Q7. Why do we use Math.abs()?
Ans. To calculate absolute differences between
     row and column positions for diagonal checking.

Q8. Explain the diagonal condition.
Ans. Two positions are on the same diagonal when
     the absolute difference between their row
     and column indices is equal.

Q9. What is recursion?
Ans. Recursion is a technique in which a function
     calls itself.

Q10. What is the base condition in this program?
Ans. if(row == n)
         return true;

Q11. Why is board[row][col] = 0 used?
Ans. It removes a queen when the current arrangement
     does not produce a valid solution.

Q12. What is the purpose of fixedRow?
Ans. It stores the row of the initially placed queen
     so that the program does not modify that row.

Q13. What is a 2D array?
Ans. A 2D array stores elements in rows and columns.

Q14. What does boolean return?
Ans. It returns either true or false.

Q15. What is the time complexity?
Ans. Worst-case time complexity is O(N!).

Q16. What is the space complexity?
Ans. O(N²), mainly because of the chessboard matrix.

Q17. Can two queens be placed in the same row?
Ans. No. The algorithm places only one queen per row.

Q18. Can two queens be placed in the same column?
Ans. No. The isSafe() function checks column conflicts.

Q19. What happens if no solution exists?
Ans. The program displays "Solution does not exist."

Q20. What is the difference between recursion
     and backtracking?
Ans. Recursion is a function calling itself.
     Backtracking is a problem-solving technique
     that uses recursion to explore possibilities
     and undo invalid choices.

Q21. Why is the first queen fixed?
Ans. The program is designed to find a solution
     with the initially entered queen remaining
     at its original position.

Q22. What is the role of solve(0, n)?
Ans. It starts the recursive process from the first row.

Q23. What is the significance of row == n?
Ans. It indicates that all rows have been processed
     successfully.

Q24. What is pruning in Backtracking?
Ans. Pruning means eliminating invalid possibilities
     without exploring them further.

Q25. Does every N have an N-Queens solution?
Ans. For the standard N-Queens problem, solutions
     exist for N = 1 and all N >= 4.
     No solutions exist for N = 2 and N = 3.
     With a fixed queen, some otherwise solvable
     boards may also have no solution.


===========================================================
6. SAMPLE INPUT AND OUTPUT
===========================================================

Example 1:

Input:

Enter N: 4
Enter first Queen row (0 to 3): 0
Enter first Queen column (0 to 3): 1

Output:

N-Queens Matrix:

0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0

Explanation:

- The board size is 4 × 4.
- The first queen is fixed at position (0,1).
- The remaining three queens are placed using
  Backtracking.
- No two queens attack each other.

Note:
Rows and columns use zero-based indexing.

Example 2:

Input:

Enter N: 2
Enter first Queen row (0 to 1): 0
Enter first Queen column (0 to 1): 0

Output:

Solution does not exist.

Reason:
It is impossible to place two non-attacking queens
on a 2 × 2 chessboard.


===========================================================
7. COMMANDS TO RUN THE PROGRAM
===========================================================

First save the file as:

NQueens.java

WINDOWS:

Step 1: Open Command Prompt in the folder containing
        NQueens.java.

Step 2: Compile:

javac NQueens.java

Step 3: Execute:

java NQueens


LINUX (UBUNTU):

Step 1: Open Terminal in the folder containing
        NQueens.java.

Step 2: Compile:

javac NQueens.java

Step 3: Execute:

java NQueens


REQUIREMENT:

Install Java Development Kit (JDK).

Check Java installation:

java -version

Check Java compiler:

javac -version


===========================================================
8. IMPORTANT POINTS TO REMEMBER FOR EXTERNAL VIVA
===========================================================

1. Problem: N-Queens Problem.
2. Algorithm: Backtracking.
3. Data Structure: 2D Array.
4. Technique: Recursion.
5. Safety Checking: Same column and diagonal.
6. Base Condition: row == n.
7. Backtracking Statement: board[row][col] = 0.
8. Time Complexity: O(N!).
9. Space Complexity: O(N²).
10. Language: Java.

MOST IMPORTANT VIVA ANSWER:

If the external examiner asks:

"Explain your program in short."

Answer:

"Sir/Madam, this program solves the N-Queens problem
using Backtracking. We first accept the chessboard
size and fix the position of the first queen.
Then we try to place the remaining queens row by row.
Before placing each queen, we check whether its
position is safe. If a position fails, we remove
that queen and try another position. This process
continues until a valid arrangement is found."
===========================================================
*/