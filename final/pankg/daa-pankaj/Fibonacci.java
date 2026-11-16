
import java.util.Scanner;

public class Fibonacci {

    // Recursive method
    static long fibRecursive(int n) {
        if (n <= 1)
            return n;

        return fibRecursive(n - 1)
             + fibRecursive(n - 2);
    }

    // Non-recursive method
    static long fibIterative(int n) {
        if (n <= 1)
            return n;

        long a = 0, b = 1, c;

        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }

        return b;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of terms: ");
        int n = sc.nextInt();

        if (n <= 0 || n > 93) {
            System.out.println("Enter terms between 1 and 93");
            return;
        }

        System.out.println("Recursive Fibonacci:");
        for (int i = 0; i < n; i++)
            System.out.print(fibRecursive(i) + " ");

        System.out.println("\nIterative Fibonacci:");
        for (int i = 0; i < n; i++)
            System.out.print(fibIterative(i) + " ");
    }
}



// sample:
// Enter number of terms: 7

// Recursive Fibonacci:
// 0 1 1 2 3 5 8

// Iterative Fibonacci:
// 0 1 1 2 3 5 8