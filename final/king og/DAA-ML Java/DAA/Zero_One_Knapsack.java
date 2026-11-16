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
