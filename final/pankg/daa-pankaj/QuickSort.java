
import java.util.Scanner;
import java.util.Random;

public class QuickSort {

    static Random random = new Random();

    // Swap two elements
    static void swap(int[] a, int i, int j) {

        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    // Partition array
    static int partition(int[] a, int low, int high) {

        int pivot = a[high];

        int i = low - 1;

        for (int j = low; j < high; j++) {

            if (a[j] <= pivot) {

                i++;

                swap(a, i, j);
            }
        }

        swap(a, i + 1, high);

        return i + 1;
    }

    // Deterministic Quick Sort
    static void deterministicQuickSort(
            int[] a, int low, int high) {

        if (low < high) {

            int p = partition(a, low, high);

            deterministicQuickSort(a, low, p - 1);

            deterministicQuickSort(a, p + 1, high);
        }
    }

    // Randomized Quick Sort
    static void randomizedQuickSort(
            int[] a, int low, int high) {

        if (low < high) {

            // Select random pivot
            int randomIndex =
                low + random.nextInt(high - low + 1);

            swap(a, randomIndex, high);

            int p = partition(a, low, high);

            randomizedQuickSort(a, low, p - 1);

            randomizedQuickSort(a, p + 1, high);
        }
    }

    // Manual display
    static void display(int[] a, int n) {

        for (int i = 0; i < n; i++) {

            System.out.print(a[i] + " ");
        }

        System.out.println();
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of elements: ");

        int n = sc.nextInt();

        if (n <= 0 || n > 10000) {
            System.out.println("Invalid size!");
            return;
        }

        int[] a = new int[n];
        int[] b = new int[n];

        System.out.println("Enter array elements:");

        for (int i = 0; i < n; i++) {

            a[i] = sc.nextInt();

            b[i] = a[i];
        }

        // Deterministic Quick Sort
        deterministicQuickSort(a, 0, n - 1);

        // Randomized Quick Sort
        randomizedQuickSort(b, 0, n - 1);

        System.out.println("\nDeterministic Quick Sort:");

        display(a, n);

        System.out.println("\nRandomized Quick Sort:");

        display(b, n);
    }
}

// i/p:
// Enter number of elements: 6

// 8 4 7 2 9 1

// o/p:
// Deterministic Quick Sort:
// 1 2 4 7 8 9

// Randomized Quick Sort:
// 1 2 4 7 8 9