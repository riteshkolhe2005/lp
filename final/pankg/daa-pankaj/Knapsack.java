
import java.util.Scanner;

public class Knapsack {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of items: ");
        int n = sc.nextInt();

        if (n < 0 || n > 100) {
            System.out.println("Invalid number of items!");
            return;
        }

        int[] weight = new int[n];
        int[] profit = new int[n];

        System.out.println("Enter weights:");

        for (int i = 0; i < n; i++) {

            weight[i] = sc.nextInt();

            if (weight[i] <= 0) {
                System.out.println("Invalid weight!");
                return;
            }
        }

        System.out.println("Enter profits:");

        for (int i = 0; i < n; i++) {

            profit[i] = sc.nextInt();

            if (profit[i] < 0) {
                System.out.println("Invalid profit!");
                return;
            }
        }

        System.out.print("Enter capacity: ");
        int W = sc.nextInt();

        if (W < 0 || W > 1000) {
            System.out.println("Invalid capacity!");
            return;
        }

        int[][] dp = new int[n + 1][W + 1];

        // Build DP table
        for (int i = 1; i <= n; i++) {

            for (int w = 0; w <= W; w++) {

                if (weight[i - 1] <= w) {

                    int include =
                        profit[i - 1] +
                        dp[i - 1][w - weight[i - 1]];

                    int exclude = dp[i - 1][w];

                    // Manual maximum
                    if (include > exclude)
                        dp[i][w] = include;
                    else
                        dp[i][w] = exclude;
                }
                else {

                    dp[i][w] = dp[i - 1][w];
                }
            }
        }

        System.out.println("\nMaximum Profit = " + dp[n][W]);

        // Find selected items
        System.out.print("Selected Items: ");

        int w = W;

        for (int i = n; i > 0; i--) {

            if (dp[i][w] != dp[i - 1][w]) {

                System.out.print(i + " ");

                w = w - weight[i - 1];
            }
        }

        System.out.println();
    }
}

// i/p:
// Enter number of items: 3

// Enter weights:
// 10 20 30

// Enter profits:
// 60 100 120

// Enter capacity: 50

// o/p:
// Maximum Profit = 220
// Selected Items: 3 1