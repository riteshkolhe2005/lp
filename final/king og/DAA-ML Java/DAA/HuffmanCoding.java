
import java.util.*;

class Node
{
    char data;
    int freq;
    Node left, right;

    Node(char data, int freq)
    {
        this.data = data;
        this.freq = freq;
        left = right = null;
    }
}

class HuffmanCoding
{
    public static void printCodes(Node root, String str)
    {
        if(root == null)
            return;

        if(root.data != '$')
            System.out.println(root.data + ": " + str);

        printCodes(root.left, str + "0");
        printCodes(root.right, str + "1");
    }

    public static void huffmanCodes(char data[], int freq[], int size)
    {
        PriorityQueue<Node> minHeap = new PriorityQueue<>(
            (a, b) -> a.freq - b.freq
        );

        for(int i = 0; i < size; i++)
        {
            minHeap.add(new Node(data[i], freq[i]));
        }

        while(minHeap.size() > 1)
        {
            Node left = minHeap.poll();
            Node right = minHeap.poll();

            Node top = new Node('$', left.freq + right.freq);

            top.left = left;
            top.right = right;

            minHeap.add(top);
        }

        printCodes(minHeap.poll(), "");
    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of characters: ");
        int n = sc.nextInt();

        char arr[] = new char[n];
        int freq[] = new int[n];

        for(int i = 0; i < n; i++)
        {
            System.out.print("Enter character: ");
            arr[i] = sc.next().charAt(0);

            System.out.print("Enter frequency: ");
            freq[i] = sc.nextInt();
        }

        System.out.println("\nHuffman Codes:");
        huffmanCodes(arr, freq, n);

        sc.close();
    }
}
