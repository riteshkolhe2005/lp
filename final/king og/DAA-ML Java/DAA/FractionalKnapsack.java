import java.util.*;
class Item
{
    int weight;
    int value;

    Item(int weight, int value)
    {
        this.weight = weight;
        this.value = value;
    }
}

class FractionalKnapsack
{
    public static double fractionalKnapsack(int W, Item items[])
    {
        Arrays.sort(items, (a, b) ->
        {
            double r1 = (double) a.value / a.weight;
            double r2 = (double) b.value / b.weight;

            return Double.compare(r2, r1);
        });

        double totalValue = 0;

        for(int i = 0; i < items.length; i++)
        {
            if(W == 0)break;

            if(items[i].weight <= W)
            {
                totalValue += items[i].value;
                W -= items[i].weight;
            }
            else
            {
                totalValue += (double) items[i].value
                              * W / items[i].weight;
                W = 0;
            }
        }
        return totalValue;
    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of items: ");
        int n = sc.nextInt();

        Item items[] = new Item[n];

        for(int i = 0; i < n; i++)
        {
            System.out.print("Enter weight of item " + (i+1) + ": ");
            int weight = sc.nextInt();

            System.out.print("Enter value of item " + (i+1) + ": ");
            int value = sc.nextInt();

            items[i] = new Item(weight, value);
        }

        System.out.print("Enter Knapsack Capacity: ");
        int W = sc.nextInt();

        System.out.println("Maximum Value = " +
            fractionalKnapsack(W, items));

        sc.close();
    }
}
