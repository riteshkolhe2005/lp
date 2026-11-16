
import java.util.Scanner;

public class NQueens {

    static int[][] board;
    static int n;

    // Check whether position is safe
    static boolean isSafe(int row, int col) {

        // Check same column
        for (int i = 0; i < row; i++) {

            if (board[i][col] == 1)
                return false;
        }

        // Check upper-left diagonal
        int i = row - 1;
        int j = col - 1;

        while (i >= 0 && j >= 0) {

            if (board[i][j] == 1)
                return false;

            i--;
            j--;
        }

        // Check upper-right diagonal
        i = row - 1;
        j = col + 1;

        while (i >= 0 && j < n) {

            if (board[i][j] == 1)
                return false;

            i--;
            j++;
        }

        return true;
    }

    // Backtracking function
    static boolean solveNQueens(int row) {

        // All queens successfully placed
        if (row == n)
            return true;

        for (int col = 0; col < n; col++) {

            if (isSafe(row, col)) {

                // Place queen
                board[row][col] = 1;

                if (solveNQueens(row + 1))
                    return true;

                // Backtrack
                board[row][col] = 0;
            }
        }

        return false;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter N: ");
        n = sc.nextInt();

        if (n <= 0 || n > 20) {
            System.out.println("Invalid N!");
            return;
        }

        board = new int[n][n];

        System.out.print("Enter first queen column (1 to "
                         + n + "): ");

        int col = sc.nextInt();

        if (col < 1 || col > n) {
            System.out.println("Invalid position!");
            return;
        }

        // Place first queen in first row
        board[0][col - 1] = 1;

        if (solveNQueens(1)) {

            System.out.println("\nN-Queens Solution:");

            for (int i = 0; i < n; i++) {

                for (int j = 0; j < n; j++) {

                    System.out.print(board[i][j] + " ");
                }

                System.out.println();
            }
        }
        else {

            System.out.println("No solution exists!");
        }
    }
}


// i/p:
// Enter N: 4

// Enter first queen column (1 to 4): 2

// o/p:
// N-Queens Solution:

// 0 1 0 0
// 0 0 0 1
// 1 0 0 0
// 0 0 1 0