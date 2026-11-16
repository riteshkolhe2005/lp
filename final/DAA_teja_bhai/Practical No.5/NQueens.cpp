#include <iostream>
using namespace std;

int board[20][20];

bool isSafe(int row, int col, int n)
{
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

bool solveNQueens(int row, int n)
{
    if (row == n)
        return true;

    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col, n))
        {
            board[row][col] = 1;

            if (solveNQueens(row + 1, n))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    int n;

    cout << "Enter number of queens: ";
    cin >> n;

    if (n <= 0 || n > 20)
    {
        cout << "Enter N between 1 and 20.";
        return 0;
    }

    if (solveNQueens(0, n))
    {
        cout << "\nSolution:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";

            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists.";
    }

    return 0;
}


/*
===============================================================================
                    N-QUEENS PROBLEM USING BACKTRACKING
===============================================================================

1. AIM:
-------
To solve the N-Queens problem using the Backtracking algorithm.

2. THEORY:
----------
The N-Queens problem is a classic problem of Backtracking.

The objective is to place N queens on an N x N chessboard such that no two
queens attack each other.

A queen can attack another queen if they are in the same:
1. Row (horizontal direction).
2. Column (vertical direction).
3. Diagonal direction.

Rules:
- Only one queen can be placed in each row.
- Only one queen can be placed in each column.
- No two queens can share the same diagonal.

3. WHAT IS BACKTRACKING?
------------------------
Backtracking is an algorithmic technique that builds a solution step by step.

If a selected choice does not lead to a valid solution, the algorithm:
1. Goes back to the previous step.
2. Removes the previously placed choice.
3. Tries another possibility.

In this program, if placing a queen in a particular position does not lead
to a solution, the program removes that queen and tries another column.

4. LINE-BY-LINE CODE EXPLANATION:
---------------------------------

#include <iostream>
- Includes the input/output library.
- It is used for cin and cout.

using namespace std;
- Allows us to use standard library names without writing std::.

int board[20][20];
- Declares a global 20 x 20 chessboard.
- 0 represents an empty cell.
- 1 represents a queen.
- Since it is global, all functions can access it.
- Global variables are automatically initialized to zero.

bool isSafe(int row, int col, int n)
- Checks whether a queen can safely be placed at the given row and column.
- Returns true if the position is safe, otherwise false.

for (int i = 0; i < row; i++)
- Checks all previous rows in the same column.

if (board[i][col] == 1)
- Checks whether a queen already exists in that column.

return false;
- Returns false if another queen is found in the same column.

for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
- Checks the upper-left diagonal.
- Both row and column decrease while moving diagonally.

if (board[i][j] == 1)
- Checks whether a queen exists on the upper-left diagonal.

for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
- Checks the upper-right diagonal.
- Row decreases and column increases.

return true;
- Returns true if no attacking queen is found.
- It means the current position is safe.

bool solveNQueens(int row, int n)
- Recursive function that places queens row by row.

if (row == n)
- Base condition.
- Checks whether all N queens have been placed.

return true;
- Indicates that a valid solution has been found.

for (int col = 0; col < n; col++)
- Tries every column in the current row.

if (isSafe(row, col, n))
- Checks whether the current position is safe.

board[row][col] = 1;
- Places a queen at the current position.

if (solveNQueens(row + 1, n))
- Recursively tries to place a queen in the next row.

return true;
- Stops searching if a solution is found.

board[row][col] = 0;
- Removes the queen if the current choice does not lead to a solution.
- This operation is called BACKTRACKING.

return false;
- Indicates that no valid arrangement was found for the current path.

int main()
- Main function where program execution begins.

int n;
- Declares the number of queens.

cin >> n;
- Accepts the number of queens from the user.

if (n <= 0 || n > 20)
- Validates that N is between 1 and 20.

return 0;
- Terminates the program for invalid input.

if (solveNQueens(0, n))
- Starts solving the problem from row 0.

cout << "\nSolution:\n";
- Displays the solution heading.

Nested for loops:
- Print the complete chessboard.
- 1 represents a queen and 0 represents an empty cell.

else
- Executes when no solution exists.

cout << "No solution exists.";
- Displays the failure message.

return 0;
- Successfully terminates the program.


5. ALGORITHM:
--------------
Step 1: Start.
Step 2: Create an empty N x N chessboard.
Step 3: Start placing queens from row 0.
Step 4: Check each column in the current row.
Step 5: If the position is safe:
        a. Place the queen.
        b. Move to the next row recursively.
Step 6: If all N queens are placed, return true.
Step 7: If no safe position is available:
        a. Remove the previously placed queen.
        b. Try another column.
Step 8: If no arrangement is possible, return false.
Step 9: Display the solution or the no-solution message.
Step 10: Stop.


6. WORKING OF isSafe() FUNCTION:
--------------------------------

The isSafe() function checks three directions:

1. SAME COLUMN ABOVE:
   Checks whether another queen exists vertically above the current position.

2. UPPER-LEFT DIAGONAL:
   Checks whether another queen exists diagonally on the left side.

3. UPPER-RIGHT DIAGONAL:
   Checks whether another queen exists diagonally on the right side.

Why does it only check above the current row?

Because the program places queens row by row, from top to bottom.
No queens have been placed in the rows below the current row yet.

Therefore, checking the previous rows is sufficient.


7. DRY RUN FOR N = 4:
---------------------

INPUT:
Enter number of queens: 4

Initially, the board is empty:

0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0

The algorithm starts from row 0.

Step 1: Place queen at row 0, column 0.
Step 2: Place queen at row 1, column 2.
Step 3: No safe position is available in row 2.
Step 4: Backtrack and remove the queen from row 1, column 2.
Step 5: Place queen at row 1, column 3.
Step 6: Place queen at row 2, column 1.
Step 7: No safe position is available in row 3.
Step 8: Backtrack and try another arrangement.
Step 9: Place queen at row 0, column 1.
Step 10: Place queen at row 1, column 3.
Step 11: Place queen at row 2, column 0.
Step 12: Place queen at row 3, column 2.
Step 13: All four queens are placed successfully.

FINAL CHESSBOARD:

0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0

Queen positions:
- Queen 1: (0, 1)
- Queen 2: (1, 3)
- Queen 3: (2, 0)
- Queen 4: (3, 2)

No two queens attack each other.


8. SAMPLE INPUT AND OUTPUT:
---------------------------

EXAMPLE 1: N = 4

Input:
Enter number of queens: 4

Output:
Solution:
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0

Explanation:
A valid arrangement of four queens is found.


EXAMPLE 2: N = 1

Input:
Enter number of queens: 1

Output:
Solution:
1

Explanation:
A single queen can be placed safely on a 1 x 1 board.


EXAMPLE 3: N = 2

Input:
Enter number of queens: 2

Output:
No solution exists.

Explanation:
It is impossible to place two queens on a 2 x 2 chessboard without attacking
each other.


EXAMPLE 4: N = 3

Input:
Enter number of queens: 3

Output:
No solution exists.

Explanation:
It is impossible to place three queens on a 3 x 3 chessboard without
attacking each other.


EXAMPLE 5: INVALID INPUT

Input:
Enter number of queens: 25

Output:
Enter N between 1 and 20.

Explanation:
The program supports a maximum of 20 queens.


9. TIME AND SPACE COMPLEXITY:
-----------------------------

Let N represent the number of queens.

1. Checking a safe position:
   O(N)

2. Trying possible queen placements:
   O(N!)

3. Overall time complexity:
   O(N x N!) upper bound.

4. Chessboard space:
   O(N^2)

5. Recursion stack:
   O(N)

6. Overall space complexity:
   O(N^2)

Why is time complexity O(N x N!)?

- Each row tries possible column positions.
- The number of possible arrangements is bounded by approximately N!.
- Each safety check can take O(N) time.

Therefore, the commonly stated upper-bound complexity is O(N x N!).


10. VIVA QUESTIONS AND ANSWERS:
--------------------------------

A. BASIC QUESTIONS
------------------

Q1. What is the N-Queens Problem?
Ans: It is the problem of placing N queens on an N x N chessboard so that
no two queens attack each other.

Q2. Which algorithm is used in this program?
Ans: Backtracking.

Q3. What is a queen in chess?
Ans: A queen is a chess piece that can move horizontally, vertically and
diagonally.

Q4. What is the size of the chessboard?
Ans: N x N.

Q5. What does 1 represent in the board?
Ans: A queen.

Q6. What does 0 represent?
Ans: An empty cell.

Q7. What is the purpose of isSafe()?
Ans: It checks whether a queen can be placed at a particular position
without attacking another queen.

Q8. What is the purpose of solveNQueens()?
Ans: It recursively places queens row by row to find a valid arrangement.

Q9. Is this program recursive?
Ans: Yes. The solveNQueens() function calls itself.

Q10. What is the base condition?
Ans: if (row == n), which means all queens have been placed successfully.


B. BACKTRACKING QUESTIONS
-------------------------

Q11. What is backtracking?
Ans: It is a technique that tries possible solutions and reverses a choice
when it leads to failure.

Q12. Why is backtracking used in N-Queens?
Ans: Because some queen placements may lead to conflicts later.
Backtracking allows the program to undo those placements and try alternatives.

Q13. What is the backtracking statement in this program?
Ans: board[row][col] = 0;

Q14. What happens if a position is unsafe?
Ans: The program skips that position and checks the next column.

Q15. What happens if all columns are unsafe?
Ans: The function returns false, causing the previous recursive call to
backtrack.

Q16. Does backtracking always find a solution?
Ans: It finds a solution if one exists and the algorithm explores the
necessary possibilities.

Q17. Is backtracking a greedy algorithm?
Ans: No. Greedy algorithms make locally optimal choices, while backtracking
explores alternatives.

Q18. What is the difference between recursion and backtracking?
Ans: Recursion is a function calling itself. Backtracking is a problem-solving
technique that often uses recursion to explore and undo choices.


C. CODE-BASED QUESTIONS
-----------------------

Q19. Why is board[20][20] declared globally?
Ans: So that all functions can access the same chessboard without passing
it as an argument.

Q20. Why is the board initialized with zeros?
Ans: Because global variables in C++ are automatically initialized to zero.

Q21. Why is bool used in isSafe()?
Ans: Because the function returns either true or false.

Q22. Why does the first loop start from i = 0?
Ans: To check all previously processed rows.

Q23. Why does the first loop stop at i < row?
Ans: Because only rows above the current row can contain previously placed
queens.

Q24. Why does diagonal checking use two variables, i and j?
Ans: Because both row and column change while moving diagonally.

Q25. Why does the upper-left diagonal decrease both variables?
Ans: Moving upward decreases the row number, and moving left decreases the
column number.

Q26. Why does the upper-right diagonal decrease i but increase j?
Ans: Moving upward decreases the row number, while moving right increases
the column number.

Q27. Why does the column loop start at zero?
Ans: Because array indexing starts at zero in C++.

Q28. Why is row + 1 passed recursively?
Ans: To place the next queen in the next row.

Q29. Why is board[row][col] = 1 executed before recursion?
Ans: To reserve the current position before trying to place the next queen.

Q30. Why does the function return true immediately after finding a solution?
Ans: Because the program needs only one valid arrangement.


D. CONCEPTUAL QUESTIONS
-----------------------

Q31. Why can we place only one queen per row?
Ans: Because two queens in the same row would attack each other.

Q32. Why can we place only one queen per column?
Ans: Because two queens in the same column would attack each other.

Q33. How many queens are required for an N-Queens problem?
Ans: Exactly N queens.

Q34. Does a solution exist for N = 2?
Ans: No.

Q35. Does a solution exist for N = 3?
Ans: No.

Q36. Does a solution exist for N = 4?
Ans: Yes.

Q37. What is the smallest positive N for which a solution exists?
Ans: N = 1.

Q38. For which positive values of N does a solution exist?
Ans: N = 1 and every N >= 4. There is no solution for N = 2 or N = 3.

Q39. Does this program print all possible solutions?
Ans: No. It prints only the first solution found.

Q40. Can N-Queens be solved using other techniques?
Ans: Yes. It can also be solved using constraint satisfaction techniques
and other search algorithms.


E. COMPLEXITY QUESTIONS
-----------------------

Q41. What is the time complexity of this program?
Ans: O(N x N!) as an upper bound.

Q42. What is the space complexity?
Ans: O(N^2), mainly for the chessboard.

Q43. What is the complexity of isSafe()?
Ans: O(N), because it may scan previous rows and diagonals.

Q44. Why is the algorithm expensive for large N?
Ans: Because it may explore a large number of possible queen arrangements.

Q45. What is the recursion depth?
Ans: At most N, because one recursive call is made for each row.


F. OUTPUT-BASED AND TRICKY QUESTIONS
------------------------------------

Q46. What happens if the input is 0?
Ans: The program displays the valid-range message and terminates.

Q47. What happens if the input is greater than 20?
Ans: The program displays "Enter N between 1 and 20."

Q48. What happens if N = 1?
Ans: The program places one queen and prints a board containing 1.

Q49. What happens if N = 2?
Ans: The program explores possible placements and prints
"No solution exists."

Q50. What happens if N = 4?
Ans: It prints the first valid solution found.

Q51. What if we remove board[row][col] = 0?
Ans: The program will not correctly undo failed placements. This can prevent
it from finding a valid solution.

Q52. What if we remove the isSafe() check?
Ans: Queens may be placed in attacking positions, so the program could
produce an invalid arrangement.

Q53. Why does the program check only three directions?
Ans: Because queens are placed from top to bottom, so only the upper column
and upper diagonals can contain previously placed queens.

Q54. Why does the program not check the lower diagonal?
Ans: The lower rows have not been processed yet, so they cannot contain
previously placed queens.

Q55. What happens if we change return true to return false in the base case?
Ans: A completed arrangement would be treated as a failure, and the
algorithm would not correctly report a solution.

Q56. Can the same column be selected in different rows?
Ans: The loop may try it, but isSafe() rejects it if a queen already exists
in that column.

Q57. Can two queens be placed diagonally?
Ans: They can be placed in different diagonals, but not on the same diagonal.

Q58. How does the algorithm know when to stop?
Ans: When row == n, meaning all N queens have been placed successfully.

Q59. What is the difference between N-Queens and 8-Queens?
Ans: 8-Queens is a specific case of N-Queens where N = 8.

Q60. What is the main disadvantage of backtracking?
Ans: It may explore a large number of possibilities, making it expensive
for large inputs.


11. IMPORTANT VIVA POINTS:
---------------------------

Topic                  Important Point
---------------------------------------------------------
Problem                N-Queens
Algorithm              Backtracking
Data structure         2D array
Board size             N x N
Empty cell             0
Queen                  1
Safety checking        Same column and two upper diagonals
Base condition         row == n
Recursive call         solveNQueens(row + 1, n)
Backtracking           board[row][col] = 0
Time complexity        O(N x N!) upper bound
Space complexity       O(N^2)
N = 1                  Solution exists
N = 2                  No solution
N = 3                  No solution
N = 4                  Solution exists


12. TECHNICAL NOTES AND LIMITATIONS:
------------------------------------

1. FIXED BOARD SIZE:
   The program supports a maximum of 20 queens because the board is declared
   as board[20][20].

2. ONLY ONE SOLUTION:
   The program stops as soon as it finds the first valid arrangement.
   It does not print every possible arrangement.

3. GLOBAL ARRAY:
   The board is declared globally, so it is accessible to both isSafe()
   and solveNQueens().

4. INPUT VALIDATION:
   The program checks whether N is within the range 1 to 20, but it does
   not handle non-integer input.

5. PERFORMANCE:
   Backtracking can become expensive as N increases.


13. MOST IMPORTANT QUESTIONS FOR PRACTICAL VIVA:
------------------------------------------------

1. What is the N-Queens Problem?
2. What is backtracking?
3. Why is backtracking used here?
4. What is the purpose of isSafe()?
5. Why do we check only the upper diagonals?
6. What is the base condition?
7. What is the purpose of board[row][col] = 0?
8. What happens when N = 2 or N = 3?
9. What is the time complexity?
10. What is the space complexity?
11. Does this program print all solutions?
12. What happens if we remove the backtracking statement?

ONE-LINE VIVA EXPLANATION:
--------------------------

"The N-Queens problem is solved using backtracking. We place queens row by
row, check whether each position is safe, and if a placement leads to a
conflict, we remove that queen and try another position until a valid
arrangement is found."

===============================================================================
                              END OF EXPLANATION
===============================================================================
*/