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