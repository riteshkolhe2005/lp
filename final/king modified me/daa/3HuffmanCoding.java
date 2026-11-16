```java
import java.util.*;

// ============================================================
// PROGRAM: HUFFMAN CODING
// PURPOSE: To generate Huffman codes for given characters
//          based on their frequencies.
// CONCEPT: Greedy Algorithm, Binary Tree, Min Heap,
//          Priority Queue.
// ============================================================

class Node
{
    char data;          // Stores the character.
    int freq;           // Stores the frequency of the character.
    Node left, right;   // References to left and right child nodes.

    // Constructor: Initializes a new node.
    Node(char data, int freq)
    {
        this.data = data;   // Assigns character to node.
        this.freq = freq;   // Assigns frequency to node.
        left = right = null; // Initially, both children are null.
    }
}

class HuffmanCoding
{
    // ========================================================
    // FUNCTION: printCodes()
    // PURPOSE: Prints Huffman codes using tree traversal.
    // ========================================================

    public static void printCodes(Node root, String str)
    {
        // Base condition: If node is null, stop recursion.
        if(root == null)
            return;

        // '$' represents an internal node, not an actual character.
        // Therefore, print only leaf nodes.
        if(root.data != '$')
            System.out.println(root.data + ": " + str);

        // Moving to left child adds 0 to the Huffman code.
        printCodes(root.left, str + "0");

        // Moving to right child adds 1 to the Huffman code.
        printCodes(root.right, str + "1");
    }

    // ========================================================
    // FUNCTION: huffmanCodes()
    // PURPOSE: Constructs the Huffman tree and generates codes.
    // ========================================================

    public static void huffmanCodes(char data[], int freq[], int size)
    {
        // Creating a PriorityQueue that works as a Min Heap.
        // The node having the smallest frequency gets highest priority.
        PriorityQueue<Node> minHeap = new PriorityQueue<>(
            (a, b) -> a.freq - b.freq
        );

        // Insert all characters and their frequencies into Min Heap.
        for(int i = 0; i < size; i++)
        {
            minHeap.add(new Node(data[i], freq[i]));
        }

        // Continue until only one node remains in the heap.
        // The remaining node becomes the root of Huffman Tree.
        while(minHeap.size() > 1)
        {
            // Remove the node having the minimum frequency.
            Node left = minHeap.poll();

            // Remove the second minimum frequency node.
            Node right = minHeap.poll();

            // Create a new internal node.
            // '$' indicates that this is not an actual character.
            // Its frequency is the sum of both removed nodes.
            Node top = new Node('$', left.freq + right.freq);

            // Connect the two removed nodes as children.
            top.left = left;
            top.right = right;

            // Insert the newly created internal node into Min Heap.
            minHeap.add(top);
        }

        // The last remaining node is the root of Huffman Tree.
        // Start traversal with an empty string.
        printCodes(minHeap.poll(), "");
    }

    // ========================================================
    // MAIN FUNCTION: Execution starts here.
    // ========================================================

    public static void main(String args[])
    {
        // Scanner is used to accept input from the user.
        Scanner sc = new Scanner(System.in);

        // Accept the total number of characters.
        System.out.print("Enter number of characters: ");
        int n = sc.nextInt();

        // Array to store characters.
        char arr[] = new char[n];

        // Array to store corresponding frequencies.
        int freq[] = new int[n];

        // Accept each character and its frequency.
        for(int i = 0; i < n; i++)
        {
            System.out.print("Enter character: ");
            arr[i] = sc.next().charAt(0);

            // Accept frequency of the entered character.
            System.out.print("Enter frequency: ");
            freq[i] = sc.nextInt();
        }

        // Display the generated Huffman codes.
        System.out.println("\nHuffman Codes:");

        // Call the function to construct Huffman Tree.
        huffmanCodes(arr, freq, n);

        // Close Scanner to release resources.
        sc.close();
    }
}


/*
================================================================
1. HOW TO EXPLAIN THIS PROGRAM TO AN EXTERNAL EXAMINER
================================================================

"Sir/Mam, this program implements Huffman Coding using the
Greedy Algorithm.

Huffman Coding is a lossless data compression technique used
to reduce the number of bits required to represent characters.

First, we accept characters and their frequencies from the user.

Then, we insert all characters into a Min Heap implemented
using Java PriorityQueue.

After that, we repeatedly remove the two nodes having the
smallest frequencies.

We create a new internal node whose frequency is the sum of
the two removed nodes and make them its left and right children.

We insert this new node back into the Min Heap.

This process continues until only one node remains. This node
becomes the root of the Huffman Tree.

Finally, we traverse the tree recursively.

We assign 0 whenever we move to the left child and 1 whenever
we move to the right child.

The generated binary strings are the Huffman codes of the
respective characters."

================================================================
2. IMPORTANT CONCEPTS
================================================================

1. HUFFMAN CODING:
   It is a lossless data compression algorithm that assigns
   variable-length binary codes to characters.

2. GREEDY ALGORITHM:
   An algorithm that makes the locally optimal choice at each
   step to achieve an overall optimal solution.

   In Huffman Coding, we repeatedly select the two nodes
   having the smallest frequencies.

3. MIN HEAP:
   A complete binary tree in which the parent node has a
   smaller or equal value than its children.

   It allows us to efficiently retrieve the minimum element.

4. PRIORITY QUEUE:
   A data structure in which elements are processed according
   to their priority.

   Here, the node with the smallest frequency has the
   highest priority.

5. HUFFMAN TREE:
   A binary tree used to generate Huffman codes.
   Leaf nodes represent actual characters.
   Internal nodes represent combined frequencies.

6. LOSSLESS COMPRESSION:
   A compression technique in which the original data can be
   recovered without losing any information.

7. RECURSION:
   A technique in which a function calls itself.
   Here, printCodes() recursively traverses the Huffman Tree.

8. BINARY TREE:
   A tree data structure in which each node has at most
   two children: left and right.

9. PREFIX PROPERTY:
   No Huffman code is the prefix of another Huffman code.
   This makes decoding unambiguous.

10. TIME COMPLEXITY:
    Building the Huffman Tree: O(n log n)
    Printing the codes: O(n)
    Overall: O(n log n)

    Space Complexity: O(n)

    Here, n represents the number of distinct characters.


================================================================
3. SAMPLE INPUT
================================================================

Enter number of characters: 4

Enter character: A
Enter frequency: 5

Enter character: B
Enter frequency: 9

Enter character: C
Enter frequency: 12

Enter character: D
Enter frequency: 13


================================================================
4. EXPECTED OUTPUT
================================================================

Huffman Codes:
D: 00
C: 01
A: 10
B: 11

NOTE:
The exact codes can vary when frequencies are equal because
multiple valid Huffman Trees may exist.

The output above is valid for the given frequencies.


================================================================
5. STEP-BY-STEP LOGIC / DRY RUN
================================================================

Input:

Character     Frequency
A             5
B             9
C             12
D             13

STEP 1:
Insert all nodes into Min Heap.

A(5), B(9), C(12), D(13)

STEP 2:
Remove two minimum frequency nodes.

A(5) and B(9)

Create internal node '$' with frequency 14.

Insert it back.

STEP 3:
Now frequencies are:

C(12), D(13), $(14)

Remove C(12) and D(13).

Create internal node '$' with frequency 25.

Insert it back.

STEP 4:
Now frequencies are:

$(14), $(25)

Remove both and create root node with frequency 39.

STEP 5:
The root node is the final Huffman Tree.

Left edge = 0
Right edge = 1

STEP 6:
Traverse the tree and generate codes.

A = 10
B = 11
C = 01
D = 00


================================================================
6. EXPECTED EXTERNAL VIVA QUESTIONS WITH ANSWERS
================================================================

Q1. What is Huffman Coding?

Ans: Huffman Coding is a lossless data compression algorithm
that assigns variable-length binary codes to characters
according to their frequencies.

Q2. Which algorithm is used in Huffman Coding?

Ans: Greedy Algorithm.

Q3. Why is Huffman Coding called a Greedy Algorithm?

Ans: Because it repeatedly selects the two nodes having the
smallest frequencies at every step.

Q4. What is the use of Min Heap?

Ans: Min Heap helps efficiently retrieve the two nodes
having the smallest frequencies.

Q5. What is PriorityQueue in Java?

Ans: PriorityQueue is a data structure that processes
elements according to their priority.

Q6. What does poll() do?

Ans: poll() removes and returns the highest-priority element.
In our Min Heap, it returns the node with minimum frequency.

Q7. What does add() do?

Ans: It inserts an element into the PriorityQueue.

Q8. What is the purpose of '$' in this program?

Ans: '$' represents an internal node of the Huffman Tree.
It is not an actual input character.

Q9. Why do we assign 0 to the left edge?

Ans: It is a convention used to generate binary Huffman codes.
The right edge is assigned 1.

Q10. What is a leaf node?

Ans: A node that does not have any children is called a leaf
node. In this program, leaf nodes represent characters.

Q11. What is a root node?

Ans: The topmost node of a tree is called the root node.

Q12. What is lossless compression?

Ans: Compression in which the original data can be recovered
exactly without losing information.

Q13. What is the prefix property?

Ans: No generated Huffman code is the prefix of another code.

Q14. Why are different code lengths used?

Ans: Frequently occurring characters receive shorter codes,
while less frequent characters receive longer codes.

Q15. What is the time complexity of Huffman Coding?

Ans: O(n log n), where n is the number of distinct characters.

Q16. What is the space complexity?

Ans: O(n), for storing the Huffman Tree and PriorityQueue.

Q17. What is recursion?

Ans: Recursion is a technique in which a function calls itself.

Q18. Which function is responsible for generating codes?

Ans: printCodes() generates the codes by traversing the tree.

Q19. Why is a binary tree used?

Ans: Because every character can be represented using a
sequence of binary decisions, 0 and 1.

Q20. Where is Huffman Coding used?

Ans:
1. File compression.
2. ZIP compression.
3. JPEG encoding.
4. Data transmission.
5. Multimedia compression.

Q21. What happens if two characters have equal frequencies?

Ans: Either character may be selected first. Multiple valid
Huffman Trees and codes may be generated.

Q22. What is the difference between fixed-length and
variable-length coding?

Ans: Fixed-length coding uses the same number of bits for
every character, whereas variable-length coding uses
different numbers of bits.

Q23. What is the role of the constructor in Node class?

Ans: It initializes the character, frequency, and child
references of a node.

Q24. What does this.freq mean?

Ans: It refers to the instance variable freq of the current
object.

Q25. What is the purpose of root == null?

Ans: It checks whether the current node is null and stops
recursion if no node exists.

Q26. Why do we use minHeap.size() > 1?

Ans: Because we must continue combining nodes until only
one root node remains.

Q27. Can Huffman Coding be used for data encryption?

Ans: No. Its primary purpose is compression, not encryption.

Q28. What is the difference between compression and
decompression?

Ans: Compression reduces the size of data. Decompression
reconstructs the original data.

Q29. What happens if only one character is entered?

Ans: The current implementation prints an empty code because
the root itself is a leaf and traversal starts with an empty
string. A special single-character code would require an
additional handling condition.

Q30. What is the advantage of Huffman Coding?

Ans: It reduces the average number of bits required to
represent data by assigning shorter codes to frequent
characters.


================================================================
7. EXECUTION COMMANDS
================================================================

REQUIREMENT:
Java JDK must be installed.

WINDOWS:

Step 1: Save the file as:

HuffmanCoding.java

Step 2: Open CMD in the folder containing the file.

Step 3: Compile:

javac HuffmanCoding.java

Step 4: Run:

java HuffmanCoding


LINUX (UBUNTU):

Step 1: Save the file as:

HuffmanCoding.java

Step 2: Open Terminal in the folder containing the file.

Step 3: Compile:

javac HuffmanCoding.java

Step 4: Run:

java HuffmanCoding


CHECK JAVA INSTALLATION:

java -version

javac -version


================================================================
8. IMPORTANT POINTS TO REMEMBER BEFORE VIVA
================================================================

1. Algorithm: Greedy Algorithm.
2. Data Structure: Min Heap / Priority Queue.
3. Tree: Binary Tree.
4. Left Edge: 0.
5. Right Edge: 1.
6. Internal Node: '$'.
7. Leaf Node: Actual Character.
8. Main Function: huffmanCodes().
9. Code Generation Function: printCodes().
10. Time Complexity: O(n log n).
11. Space Complexity: O(n).
12. Compression Type: Lossless.

ONE-LINE CONCLUSION:

Huffman Coding is a Greedy Algorithm that uses a Min Heap
and Binary Tree to generate variable-length prefix codes
for efficient lossless data compression.

================================================================
*/
```