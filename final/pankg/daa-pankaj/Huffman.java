
import java.util.Scanner;

public class Huffman {

    static class Node {
        char ch;
        int frequency;
        Node left, right;

        Node(char ch, int frequency) {
            this.ch = ch;
            this.frequency = frequency;
        }
    }

    // Manual Min Heap
    static class MinHeap {

        Node[] heap;
        int size;

        MinHeap(int capacity) {
            heap = new Node[capacity];
            size = 0;
        }

        void insert(Node node) {

            int i = size;
            heap[size] = node;
            size++;

            // Heapify upward
            while (i > 0) {

                int parent = (i - 1) / 2;

                if (heap[parent].frequency <=
                    heap[i].frequency)
                    break;

                Node temp = heap[parent];
                heap[parent] = heap[i];
                heap[i] = temp;

                i = parent;
            }
        }

        Node extractMin() {

            Node minimum = heap[0];

            size--;

            if (size == 0)
                return minimum;

            heap[0] = heap[size];

            int i = 0;

            // Heapify downward
            while (true) {

                int left = 2 * i + 1;
                int right = 2 * i + 2;
                int smallest = i;

                if (left < size &&
                    heap[left].frequency <
                    heap[smallest].frequency) {

                    smallest = left;
                }

                if (right < size &&
                    heap[right].frequency <
                    heap[smallest].frequency) {

                    smallest = right;
                }

                if (smallest == i)
                    break;

                Node temp = heap[i];
                heap[i] = heap[smallest];
                heap[smallest] = temp;

                i = smallest;
            }

            return minimum;
        }
    }

    // Build Huffman Tree
    static Node buildTree(char[] ch, int[] freq, int n) {

        MinHeap heap = new MinHeap(2 * n + 1);

        for (int i = 0; i < n; i++) {
            heap.insert(new Node(ch[i], freq[i]));
        }

        while (heap.size > 1) {

            Node left = heap.extractMin();
            Node right = heap.extractMin();

            Node parent = new Node(
                '$',
                left.frequency + right.frequency
            );

            parent.left = left;
            parent.right = right;

            heap.insert(parent);
        }

        return heap.extractMin();
    }

    // Display Huffman Codes
    static void printCodes(Node root, String code) {

        if (root == null)
            return;

        if (root.left == null && root.right == null) {

            if (code.length() == 0)
                code = "0";

            System.out.println(root.ch + " : " + code);
            return;
        }

        printCodes(root.left, code + "0");
        printCodes(root.right, code + "1");
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of characters: ");
        int n = sc.nextInt();

        if (n <= 0 || n > 100) {
            System.out.println("Invalid input!");
            return;
        }

        char[] ch = new char[n];
        int[] freq = new int[n];

        System.out.println("Enter character and frequency:");

        for (int i = 0; i < n; i++) {

            ch[i] = sc.next().charAt(0);
            freq[i] = sc.nextInt();

            if (freq[i] <= 0) {
                System.out.println("Frequency must be positive!");
                return;
            }
        }

        Node root = buildTree(ch, freq, n);

        System.out.println("\nHuffman Codes:");

        printCodes(root, "");
    }
}

// i/p:
// Enter number of characters: 4

// a 5
// b 9
// c 12
// d 13

// o/p:
// Huffman Codes:
// c : 00
// d : 01
// a : 100
// b : 101