
import java.util.Scanner;

public class FractionalKnapsack {

    static class Item {

        int profit;
        int weight;
        double ratio;

        Item(int profit, int weight) {

            this.profit = profit;
            this.weight = weight;

            ratio = (double) profit / weight;
        }
    }

    // Manual Bubble Sort
    static void sortItems(Item[] items, int n) {

        for (int i = 0; i < n - 1; i++) {

            for (int j = 0; j < n - i - 1; j++) {

                if (items[j].ratio < items[j + 1].ratio) {

                    Item temp = items[j];

                    items[j] = items[j + 1];
                    items[j + 1] = temp;
                }
            }
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of items: ");
        int n = sc.nextInt();

        if (n <= 0 || n > 100) {
            System.out.println("Invalid input!");
            return;
        }

        Item[] items = new Item[n];

        System.out.println("Enter profit and weight:");

        for (int i = 0; i < n; i++) {

            int profit = sc.nextInt();
            int weight = sc.nextInt();

            if (profit < 0 || weight <= 0) {
                System.out.println("Invalid item!");
                return;
            }

            items[i] = new Item(profit, weight);
        }

        System.out.print("Enter knapsack capacity: ");
        int capacity = sc.nextInt();

        if (capacity < 0) {
            System.out.println("Invalid capacity!");
            return;
        }

        // Sort by profit/weight ratio
        sortItems(items, n);

        double totalProfit = 0;

        for (int i = 0; i < n && capacity > 0; i++) {

            if (items[i].weight <= capacity) {

                totalProfit += items[i].profit;

                capacity -= items[i].weight;
            }
            else {

                double fraction =
                    (double) capacity / items[i].weight;

                totalProfit += fraction * items[i].profit;

                capacity = 0;
            }
        }

        System.out.println("\nMaximum Profit = " + totalProfit);
    }
}


// sample input:
// Enter number of items: 3

// 60 10
// 100 20
// 120 30

// Enter knapsack capacity: 50

// o/p:
// Maximum Profit = 240.0