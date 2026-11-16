#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// Create Node
struct Node
{
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f)
    {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Compare frequencies
struct Compare
{
    bool operator()(Node* a, Node* b)
    {
        return a->freq > b->freq;
    }
};

// Print Huffman Codes
void printCodes(Node* root, string code)
{
    if (root == nullptr)
        return;

    if (root->left == nullptr && root->right == nullptr)
    {
        cout << root->ch << " : " << code << endl;
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main()
{
    int n;
    char ch;
    int freq;

    priority_queue<Node*, vector<Node*>, Compare> pq;

    cout << "Enter number of characters: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of characters!";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter character and frequency: ";
        cin >> ch >> freq;

        if (freq <= 0)
        {
            cout << "Frequency must be positive!";
            return 0;
        }

        pq.push(new Node(ch, freq));
    }

    // Build Huffman Tree
    while (pq.size() > 1)
    {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node('$',
                                  left->freq + right->freq);

        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    cout << "\nHuffman Codes:\n";

    printCodes(pq.top(), "");

    return 0;
}



/*
====================================================================
             HUFFMAN CODING USING GREEDY ALGORITHM
                         COMPLETE EXPLANATION
====================================================================

1. AIM:

To write a C++ program to implement Huffman Coding using
the Greedy Algorithm and generate variable-length binary
codes for characters based on their frequencies.

2. WHAT IS HUFFMAN CODING?

Huffman Coding is a lossless data compression technique.

It assigns variable-length binary codes to characters
according to their frequencies.

Important points:

1. Frequently occurring characters receive shorter codes.
2. Less frequently occurring characters receive longer codes.
3. No Huffman code is a prefix of another Huffman code.
4. It reduces the total number of bits required to represent
   data.
5. It uses a binary tree called a Huffman Tree.

Example:

Character frequencies:

A = 5
B = 9
C = 12
D = 13
E = 16
F = 45

Possible Huffman Codes:

A = 1100
B = 1101
C = 100
D = 101
E = 111
F = 0

Note:
The exact codes can differ depending on how equal-frequency
nodes are handled, but the coding cost remains optimal.


====================================================================
3. LINE-BY-LINE CODE EXPLANATION
====================================================================

LINE 1:
#include <iostream>

Explanation:
- #include is a preprocessor directive.
- iostream is a standard C++ header file.
- It provides input and output functionality.
- It allows the use of cin and cout.
- cin accepts input from the user.
- cout displays output on the screen.

LINE 2:
#include <queue>

Explanation:
- Includes the queue header file.
- Provides the priority_queue data structure.
- A priority queue is used to select the nodes having
  the smallest frequencies.
- It is an important part of Huffman tree construction.

LINE 3:
#include <vector>

Explanation:
- Includes the vector header file.
- vector is a dynamic array provided by the C++ Standard
  Template Library (STL).
- It is used as the underlying container of priority_queue.
- It can automatically manage its storage as elements
  are inserted or removed.

LINE 4:
#include <string>

Explanation:
- Includes the string header file.
- Provides the string data type.
- It is used to store the binary Huffman code.
- The code consists of 0s and 1s.

LINE 5:
using namespace std;

Explanation:
- std is the standard C++ namespace.
- Allows us to use cin, cout, queue, vector and string
  without writing std:: before each name.


====================================================================
4. NODE STRUCTURE EXPLANATION
====================================================================

LINE 6:
struct Node

Explanation:
- struct is used to create a user-defined data type.
- Node represents a node of the Huffman Tree.
- Every node stores a character, its frequency and
  pointers to its left and right children.

LINE 7:
{

Explanation:
- Marks the beginning of the Node structure.

LINE 8:
char ch;

Explanation:
- Declares a character variable ch.
- Stores the character represented by the node.
- Example: A, B, C, D.

LINE 9:
int freq;

Explanation:
- Declares an integer variable freq.
- Stores the frequency of the character or combined
  frequency of an internal node.

LINE 10:
Node *left, *right;

Explanation:
- Declares two pointers of type Node.
- left points to the left child.
- right points to the right child.
- These pointers connect nodes and construct the
  Huffman Tree.

LINE 11:
Node(char c, int f)

Explanation:
- This is a constructor of the Node structure.
- It is automatically called when a Node object is created.
- c is the character parameter.
- f is the frequency parameter.
- It initializes the node with the given character
  and frequency.

LINE 12:
{

Explanation:
- Beginning of the constructor body.

LINE 13:
ch = c;

Explanation:
- Assigns the parameter c to the member variable ch.
- Stores the character in the node.

LINE 14:
freq = f;

Explanation:
- Assigns the parameter f to the member variable freq.
- Stores the frequency in the node.

LINE 15:
left = right = nullptr;

Explanation:
- Initializes both child pointers to nullptr.
- nullptr indicates that the pointer does not point
  to a valid object.
- A newly created node initially has no children.

LINE 16:
}

Explanation:
- End of the constructor.

LINE 17:
};

Explanation:
- Ends the Node structure definition.
- Semicolon is required after a structure definition.


====================================================================
5. COMPARE STRUCTURE EXPLANATION
====================================================================

LINE 18:
struct Compare

Explanation:
- Defines another user-defined structure.
- It is used to compare two Huffman tree nodes.
- It helps the priority queue determine which node
  should have the highest priority.

LINE 19:
{

Explanation:
- Beginning of Compare structure.

LINE 20:
bool operator()(Node* a, Node* b)

Explanation:
- This is an overloaded function call operator.
- It makes objects of Compare usable as comparison
  functions.
- It accepts two Node pointers, a and b.
- It returns a Boolean value.
- true means a has lower priority than b in the
  priority queue ordering.

LINE 21:
{

Explanation:
- Beginning of the operator function.

LINE 22:
return a->freq > b->freq;

Explanation:
- Compares the frequencies of two nodes.
- The arrow operator (->) accesses a member through
  a pointer.
- If a->freq is greater than b->freq, it returns true.
- This comparison makes the priority queue behave
  as a min-priority queue.
- The node with the smallest frequency is available
  at the top.

IMPORTANT:
The priority queue normally behaves like a max-priority
queue.

The Compare structure reverses the comparison so that
the smallest frequency gets the highest priority.

LINE 23:
}

Explanation:
- Ends the overloaded operator function.

LINE 24:
};

Explanation:
- Ends the Compare structure.


====================================================================
6. PRINT HUFFMAN CODES FUNCTION
====================================================================

LINE 25:
void printCodes(Node* root, string code)

Explanation:
- Defines a user-defined function named printCodes.
- void means the function does not return any value.
- root is a pointer to the current tree node.
- code stores the binary code generated along the path.
- The function traverses the Huffman Tree recursively
  and prints the code for every leaf node.

LINE 26:
{

Explanation:
- Beginning of the printCodes function.

LINE 27:
if (root == nullptr)

Explanation:
- Checks whether the current node pointer is empty.
- If root is nullptr, there is no node to process.
- This condition prevents accessing an invalid pointer.

LINE 28:
return;

Explanation:
- Immediately exits the current function call.
- No further processing is performed for an empty node.

LINE 29:
if (root->left == nullptr && root->right == nullptr)

Explanation:
- Checks whether the current node is a leaf node.
- A leaf node has no left child and no right child.
- Leaf nodes represent the original input characters.
- Internal nodes contain combined frequencies.

LINE 30:
{

Explanation:
- Beginning of the leaf-node condition.

LINE 31:
cout << root->ch << " : " << code << endl;

Explanation:
- Prints the character stored in the leaf node.
- Prints its corresponding Huffman binary code.
- root->ch accesses the character through the pointer.
- code contains the binary path from root to leaf.
- endl moves the cursor to the next line.

LINE 32:
return;

Explanation:
- Stops processing the current leaf node.
- No further child traversal is required.

LINE 33:
}

Explanation:
- Ends the leaf-node condition.

LINE 34:
printCodes(root->left, code + "0");

Explanation:
- Recursively traverses the left subtree.
- Appends 0 to the current code.
- In Huffman coding, the left edge represents bit 0.
- The function continues until it reaches a leaf node.

LINE 35:
printCodes(root->right, code + "1");

Explanation:
- Recursively traverses the right subtree.
- Appends 1 to the current code.
- In Huffman coding, the right edge represents bit 1.

LINE 36:
}

Explanation:
- Ends the printCodes function.

IMPORTANT:
This function uses Depth First Search (DFS) to traverse
the Huffman Tree.

It uses recursive traversal to visit the left and right
subtrees.


====================================================================
7. MAIN FUNCTION EXPLANATION
====================================================================

LINE 37:
int main()

Explanation:
- main() is the starting point of program execution.
- int indicates that the function returns an integer.

LINE 38:
{

Explanation:
- Beginning of the main function.

LINE 39:
int n;

Explanation:
- Declares integer variable n.
- Stores the number of characters entered by the user.

LINE 40:
char ch;

Explanation:
- Declares a character variable.
- Stores the character entered by the user.

LINE 41:
int freq;

Explanation:
- Declares an integer variable.
- Stores the frequency of the entered character.

LINE 42:
priority_queue<Node*, vector<Node*>, Compare> pq;

Explanation:
- Declares a priority queue named pq.
- It stores pointers to Node objects.
- vector<Node*> is the underlying container.
- Compare defines the priority ordering.
- The smallest frequency node is available at the top.
- It is used during Huffman Tree construction.

Breaking it down:

priority_queue:
A container that provides access to the highest-priority
element.

Node*:
Stores pointers to Huffman Tree nodes.

vector<Node*>:
Stores the node pointers internally.

Compare:
Defines how two nodes are compared.

pq:
Name of the priority queue.


LINE 43:
cout << "Enter number of characters: ";

Explanation:
- Displays a message asking the user to enter the number
  of characters.

LINE 44:
cin >> n;

Explanation:
- Accepts the number of characters from the user.
- Stores the value in n.

LINE 45:
if (n <= 0)

Explanation:
- Checks whether the entered number is zero or negative.
- A valid Huffman input requires at least one character
  for this program.

LINE 46:
{

Explanation:
- Beginning of the if block.

LINE 47:
cout << "Invalid number of characters!";

Explanation:
- Displays an error message if n is not positive.

LINE 48:
return 0;

Explanation:
- Terminates the program immediately.

LINE 49:
}

Explanation:
- Ends the validation block.

LINE 50:
for (int i = 0; i < n; i++)

Explanation:
- Executes a loop n times.
- Accepts the character and frequency of every input symbol.
- i starts at 0 and increases by 1.

LINE 51:
{

Explanation:
- Beginning of the for loop body.

LINE 52:
cout << "Enter character and frequency: ";

Explanation:
- Asks the user to enter a character and its frequency.

LINE 53:
cin >> ch >> freq;

Explanation:
- Accepts a character and its frequency.
- Stores them in ch and freq.

Example:
A 5

ch = A
freq = 5

LINE 54:
if (freq <= 0)

Explanation:
- Checks whether the entered frequency is zero or negative.
- Huffman coding requires positive frequencies.

LINE 55:
{

Explanation:
- Beginning of the frequency validation block.

LINE 56:
cout << "Frequency must be positive!";

Explanation:
- Displays an error message for invalid frequency.

LINE 57:
return 0;

Explanation:
- Terminates the program if the frequency is invalid.

LINE 58:
}

Explanation:
- Ends the frequency validation block.

LINE 59:
pq.push(new Node(ch, freq));

Explanation:
- Creates a new Node dynamically using the new operator.
- Stores the character and its frequency.
- Inserts the address of the newly created node into
  the priority queue.
- push() inserts an element into the priority queue.

Example:
pq.push(new Node('A', 5));

Creates a node containing:
Character = A
Frequency = 5

LINE 60:
}

Explanation:
- Ends the input loop.


====================================================================
8. HUFFMAN TREE CONSTRUCTION
====================================================================

LINE 61:
while (pq.size() > 1)

Explanation:
- Uses a while loop to construct the Huffman Tree.
- pq.size() returns the number of nodes currently
  present in the priority queue.
- The loop continues while more than one node exists.
- The process combines two minimum-frequency nodes
  into a new internal node.

LINE 62:
{

Explanation:
- Beginning of the while loop body.

LINE 63:
Node* left = pq.top();

Explanation:
- Declares a pointer named left.
- top() returns the highest-priority element.
- Because of Compare, this is the smallest-frequency node.
- Stores its address in left.

LINE 64:
pq.pop();

Explanation:
- Removes the top element from the priority queue.
- The removed node remains allocated in memory.
- Only its pointer is removed from the queue.

LINE 65:
Node* right = pq.top();

Explanation:
- Gets the next smallest-frequency node.
- Stores its address in right.

LINE 66:
pq.pop();

Explanation:
- Removes the second smallest-frequency node from
  the priority queue.

LINE 67:
Node* newNode = new Node('$',
                         left->freq + right->freq);

Explanation:
- Creates a new internal Huffman Tree node.
- '$' is used as a placeholder character.
- It does not represent an original input character.
- The frequency of the new node is the sum of the
  frequencies of the left and right nodes.
- new allocates memory dynamically.
- The returned address is stored in newNode.

Example:

left->freq = 5
right->freq = 9

newNode frequency = 5 + 9 = 14.

LINE 68:
newNode->left = left;

Explanation:
- Connects the first selected node as the left child
  of the newly created internal node.

LINE 69:
newNode->right = right;

Explanation:
- Connects the second selected node as the right child
  of the newly created internal node.

LINE 70:
pq.push(newNode);

Explanation:
- Inserts the newly created internal node into
  the priority queue.
- Its frequency is used in subsequent comparisons.

LINE 71:
}

Explanation:
- Ends the while loop.
- The loop stops when only one node remains.
- This remaining node is the root of the Huffman Tree.


====================================================================
9. DISPLAY HUFFMAN CODES
====================================================================

LINE 72:
cout << "\nHuffman Codes:\n";

Explanation:
- Displays the heading Huffman Codes.
- \n represents a newline character.

LINE 73:
printCodes(pq.top(), "");

Explanation:
- pq.top() returns the remaining node.
- This node is the root of the completed Huffman Tree.
- printCodes() traverses the tree recursively.
- The second argument is an empty string.
- Initially, no binary bits have been assigned.
- The function appends 0 for left edges and 1 for
  right edges.

LINE 74:
return 0;

Explanation:
- Terminates the main function.
- Returns 0 to indicate successful execution.

LINE 75:
}

Explanation:
- Marks the end of the main function.


====================================================================
10. WORKING OF HUFFMAN CODING
====================================================================

Steps:

1. Start the program.
2. Accept the number of characters.
3. Validate the number of characters.
4. Accept each character and its frequency.
5. Validate that all frequencies are positive.
6. Create a separate node for every character.
7. Insert all nodes into the priority queue.
8. Extract the two nodes having the smallest frequencies.
9. Create a new internal node with their combined frequency.
10. Connect the extracted nodes as left and right children.
11. Insert the new node into the priority queue.
12. Repeat until only one node remains.
13. The remaining node becomes the root of the Huffman Tree.
14. Traverse the tree recursively.
15. Assign 0 to every left edge and 1 to every right edge.
16. Print the character and its binary code.
17. Stop.


====================================================================
11. DRY RUN WITH EXAMPLE
====================================================================

INPUT:

Number of characters = 4

A = 5
B = 9
C = 12
D = 13

INITIAL PRIORITY QUEUE:

A = 5
B = 9
C = 12
D = 13

STEP 1:

Extract two minimum frequencies:

A = 5
B = 9

Create a new node:

5 + 9 = 14

New node = 14

Remaining queue:

C = 12
D = 13
New node = 14

STEP 2:

Extract two minimum frequencies:

C = 12
D = 13

Create a new node:

12 + 13 = 25

New node = 25

Remaining queue:

14
25

STEP 3:

Extract two minimum frequencies:

14
25

Create a new root node:

14 + 25 = 39

Remaining queue:

39

Only one node remains, so Huffman Tree construction
is completed.

FINAL TREE:

                 39
                /  \
              14    25
             / \    / \
            5   9  12  13
            A   B  C   D

ASSIGNED CODES:

A = 00
B = 01
C = 10
D = 11

Note:
For this example, the codes are based on the specified
left-child and right-child assignments.


====================================================================
12. ALGORITHM
====================================================================

Step 1: Start.
Step 2: Read the number of characters n.
Step 3: Check whether n is positive.
Step 4: Create a priority queue.
Step 5: Read each character and its frequency.
Step 6: Create a node for each character.
Step 7: Insert all nodes into the priority queue.
Step 8: Repeat while queue size is greater than 1:
        a. Remove the minimum-frequency node.
        b. Remove the next minimum-frequency node.
        c. Create a new internal node.
        d. Set its frequency to the sum of both nodes.
        e. Assign them as left and right children.
        f. Insert the new node into the priority queue.
Step 9: Take the remaining node as the root.
Step 10: Traverse the Huffman Tree recursively.
Step 11: Assign 0 to left edges and 1 to right edges.
Step 12: Print all character codes.
Step 13: Stop.


====================================================================
13. TIME AND SPACE COMPLEXITY
====================================================================

Let n be the number of input characters.

TIME COMPLEXITY:

1. Inserting n nodes into the priority queue:

   O(n log n)

2. Building the Huffman Tree:

   There are n - 1 merging operations.
   Each operation performs two removals and one insertion.
   Each priority queue operation takes O(log n).

   Total: O(n log n)

3. Printing Huffman Codes:

   Tree traversal visits O(n) nodes.
   However, constructing and printing the code strings
   also involves string operations.

   A conservative bound is O(n^2) character work in the
   worst case for this implementation.

OVERALL TIME COMPLEXITY:

O(n log n + total output code length)

For the standard Huffman tree construction algorithm,
the priority queue construction takes O(n log n).

SPACE COMPLEXITY:

O(n) for the tree and priority queue.

The Huffman Tree contains:
- n leaf nodes.
- n - 1 internal nodes.
- Total = 2n - 1 nodes.

The recursive traversal also uses stack space
proportional to the tree height.

Therefore, total auxiliary space is O(n).


====================================================================
14. IMPORTANT DATA STRUCTURES AND CONCEPTS
====================================================================

1. STRUCTURE:
   A user-defined data type that groups related variables.

2. POINTER:
   A variable that stores the memory address of another
   variable or object.

3. CONSTRUCTOR:
   A special member function automatically called when
   an object is created.

4. PRIORITY QUEUE:
   A data structure that provides access to the
   highest-priority element.

5. MIN-PRIORITY QUEUE:
   A priority queue in which the smallest element
   has the highest priority.

6. VECTOR:
   A dynamic array provided by the C++ STL.

7. RECURSION:
   A technique in which a function calls itself.

8. GREEDY ALGORITHM:
   An algorithm that repeatedly selects the locally
   optimal choice.

9. HUFFMAN TREE:
   A binary tree used to generate prefix-free codes.

10. LEAF NODE:
    A node that has no children.

11. INTERNAL NODE:
    A node that has one or more children.
    In this Huffman implementation, every internal
    node has two children.

12. LOSSLESS COMPRESSION:
    A compression technique that allows the original
    data to be recovered exactly.

13. DFS:
    Depth First Search is a tree traversal technique
    that explores a branch before another branch.


====================================================================
15. SAMPLE INPUT AND SAMPLE OUTPUT
====================================================================

SAMPLE INPUT 1:

Enter number of characters: 4

Enter character and frequency: A 5
Enter character and frequency: B 9
Enter character and frequency: C 12
Enter character and frequency: D 13


SAMPLE OUTPUT 1:

Huffman Codes:

A : 00
B : 01
C : 10
D : 11


EXPLANATION:

- Four characters are entered.
- Their frequencies are 5, 9, 12 and 13.
- The two smallest frequencies are combined repeatedly.
- A Huffman Tree is constructed.
- The tree is traversed to generate binary codes.

Note:
The exact code ordering can depend on how equal priorities
are handled. For this particular input, all frequencies
are different, so the displayed codes follow the tree
construction shown above.


------------------------------------------------------------

SAMPLE INPUT 2:

Enter number of characters: 5

Enter character and frequency: A 2
Enter character and frequency: B 3
Enter character and frequency: C 7
Enter character and frequency: D 9
Enter character and frequency: E 15


SAMPLE OUTPUT 2:

Huffman Codes:

E : 0
D : 10
C : 110
A : 1110
B : 1111


EXPLANATION:

- Five characters are entered.
- The program repeatedly combines the two smallest
  frequencies.
- The final Huffman Tree is constructed.
- The most frequent character E receives the shortest code.
- The less frequent characters receive longer codes.


------------------------------------------------------------

SAMPLE INPUT 3:

Enter number of characters: 1

Enter character and frequency: A 10


SAMPLE OUTPUT 3:

Huffman Codes:

A :


EXPLANATION:

- Only one character is entered.
- The priority queue contains one node.
- The while loop does not execute.
- The only node becomes the root.
- Its code is an empty string in this implementation.

IMPORTANT:
A single-symbol Huffman alphabet is often conventionally
assigned code 0, but this program prints an empty code.


------------------------------------------------------------

SAMPLE INPUT 4:

Enter number of characters: 0


SAMPLE OUTPUT 4:

Invalid number of characters!


EXPLANATION:

- The entered number is zero.
- The condition n <= 0 becomes true.
- The program displays an error message and terminates.


------------------------------------------------------------

SAMPLE INPUT 5:

Enter number of characters: 2

Enter character and frequency: A 5
Enter character and frequency: B 0


SAMPLE OUTPUT 5:

Frequency must be positive!


EXPLANATION:

- Character A has a valid positive frequency.
- Character B has frequency zero.
- The validation condition freq <= 0 becomes true.
- The program terminates.


====================================================================
16. VIVA QUESTIONS AND ANSWERS
====================================================================

BASIC VIVA QUESTIONS
--------------------

Q1. What is Huffman Coding?

Ans:
Huffman Coding is a lossless data compression technique
that assigns variable-length binary codes to characters
based on their frequencies.

Q2. Who developed Huffman Coding?

Ans:
David A. Huffman developed it in 1952.

Q3. What is the objective of this program?

Ans:
To generate Huffman codes for characters using a
Greedy Algorithm.

Q4. Which algorithm is used?

Ans:
Greedy Algorithm.

Q5. What is a Greedy Algorithm?

Ans:
An algorithm that makes the locally optimal choice
at each step.

Q6. What is the main data structure used?

Ans:
Priority Queue.

Q7. What is a Huffman Tree?

Ans:
A binary tree used to generate Huffman codes.

Q8. What is lossless compression?

Ans:
A compression technique in which the original data
can be recovered exactly.

Q9. What is variable-length coding?

Ans:
A coding technique in which different characters
can have codes of different lengths.

Q10. Which character gets the shortest code?

Ans:
Generally, the character with the highest frequency.


HEADER FILE QUESTIONS
---------------------

Q11. Why is iostream used?

Ans:
For input and output operations.

Q12. Why is queue included?

Ans:
To use the priority_queue data structure.

Q13. Why is vector included?

Ans:
To provide the underlying container for the priority queue.

Q14. Why is string included?

Ans:
To store binary Huffman codes.

Q15. What is STL?

Ans:
STL stands for Standard Template Library. It provides
reusable containers, algorithms and iterators.


STRUCTURE AND POINTER QUESTIONS
-------------------------------

Q16. What is a structure?

Ans:
A user-defined data type that groups related variables.

Q17. Why is Node structure used?

Ans:
To represent the nodes of the Huffman Tree.

Q18. What does ch store?

Ans:
The character represented by a leaf node.

Q19. What does freq store?

Ans:
The frequency of a character or combined node.

Q20. What is a pointer?

Ans:
A variable that stores a memory address.

Q21. Why are left and right pointers used?

Ans:
To connect the left and right children of a tree node.

Q22. What is nullptr?

Ans:
It represents a null pointer that points to no object.

Q23. What is a constructor?

Ans:
A special member function called automatically
when an object is created.

Q24. What is the use of the Node constructor?

Ans:
It initializes the character, frequency and child pointers.

Q25. What is the new operator?

Ans:
It dynamically allocates memory.

Q26. What is the difference between new and delete?

Ans:
new allocates dynamic memory, whereas delete releases
memory allocated using new.


PRIORITY QUEUE QUESTIONS
------------------------

Q27. What is a priority queue?

Ans:
A data structure in which elements are accessed according
to their priority.

Q28. What is a min-priority queue?

Ans:
A priority queue in which the smallest element has
the highest priority.

Q29. Why is a priority queue used?

Ans:
To efficiently select the two minimum-frequency nodes.

Q30. What is pq.top()?

Ans:
It returns the highest-priority element without removing it.

Q31. What is pq.pop()?

Ans:
It removes the highest-priority element.

Q32. What is pq.push()?

Ans:
It inserts an element into the priority queue.

Q33. What does pq.size() return?

Ans:
The number of elements in the priority queue.

Q34. What is the default behavior of priority_queue?

Ans:
It behaves as a max-priority queue.

Q35. How is a min-priority queue created here?

Ans:
Using the custom Compare structure.

Q36. What is the purpose of Compare?

Ans:
It defines the ordering of nodes based on frequency.

Q37. What is operator overloading?

Ans:
Providing a custom implementation for an operator
when used with user-defined types.


HUFFMAN TREE QUESTIONS
----------------------

Q38. Why are two minimum-frequency nodes selected?

Ans:
Because Huffman coding uses the greedy strategy of
combining the two least frequent nodes.

Q39. What is an internal node?

Ans:
A node that contains combined frequency and has children.

Q40. Why is '$' used?

Ans:
It is a placeholder character for internal nodes.

Q41. Does '$' represent an actual input character?

Ans:
No.

Q42. What is a leaf node?

Ans:
A node with no left or right child.

Q43. What does the root node represent?

Ans:
It represents the complete Huffman Tree.

Q44. Why does the while loop execute while pq.size() > 1?

Ans:
Because combining continues until only one root node remains.

Q45. How many leaf nodes are present?

Ans:
There are n leaf nodes for n distinct input symbols.

Q46. How many internal nodes are present in a full Huffman Tree?

Ans:
n - 1 internal nodes for n leaves.

Q47. What is the total number of nodes?

Ans:
2n - 1.


RECURSION AND TREE TRAVERSAL QUESTIONS
-------------------------------------

Q48. Which function performs tree traversal?

Ans:
printCodes().

Q49. Which traversal technique is used?

Ans:
Depth First Search (DFS).

Q50. What is recursion?

Ans:
A function calling itself.

Q51. What is the base condition in printCodes()?

Ans:
if (root == nullptr).

Q52. What is the purpose of root == nullptr?

Ans:
It stops traversal when there is no node.

Q53. How is a leaf node identified?

Ans:
When both left and right pointers are nullptr.

Q54. Why is 0 added during left traversal?

Ans:
Because the left edge represents binary bit 0.

Q55. Why is 1 added during right traversal?

Ans:
Because the right edge represents binary bit 1.

Q56. What does code + "0" mean?

Ans:
It creates a string by appending 0 to the existing code.

Q57. What does endl do?

Ans:
It inserts a newline and flushes the output stream.


GREEDY ALGORITHM QUESTIONS
--------------------------

Q58. Why is Huffman Coding called a Greedy Algorithm?

Ans:
Because it repeatedly combines the two minimum-frequency
nodes at each step.

Q59. What is a locally optimal choice?

Ans:
The best choice made at the current step.

Q60. Does Huffman Coding produce an optimal prefix code?

Ans:
Yes, for the given symbol frequencies, the algorithm
produces an optimal binary prefix code.

Q61. What is the greedy-choice property?

Ans:
It means a locally optimal choice can be part of
a globally optimal solution.

Q62. What is optimal prefix coding?

Ans:
A prefix-free code with minimum weighted average
code length for the given frequencies.


COMPLEXITY QUESTIONS
--------------------

Q63. What is the time complexity of Huffman Tree construction?

Ans:
O(n log n).

Q64. Why is the complexity O(n log n)?

Ans:
Because there are n-1 merging operations and each
priority queue operation takes O(log n).

Q65. What is the space complexity?

Ans:
O(n) for the tree and priority queue.

Q66. What is the total number of nodes?

Ans:
2n - 1.

Q67. How many merging operations are performed?

Ans:
n - 1.

Q68. What is the complexity of priority queue insertion?

Ans:
O(log n).

Q69. What is the complexity of deleting the top element?

Ans:
O(log n).

Q70. What is the complexity of accessing the top element?

Ans:
O(1).


ADVANCED AND TRICKY EXTERNAL VIVA QUESTIONS
-------------------------------------------

Q71. What is a prefix code?

Ans:
A code in which no codeword is the prefix of another
codeword.

Q72. Why is prefix coding important?

Ans:
It allows encoded data to be decoded unambiguously
without requiring separators between codewords.

Q73. What is the difference between fixed-length and
variable-length coding?

Ans:
Fixed-length coding uses equal-sized codes, while
variable-length coding assigns different lengths.

Q74. What happens if all characters have equal frequencies?

Ans:
The resulting Huffman tree can be balanced or nearly
balanced, depending on the number of symbols and
tie-breaking behavior.

Q75. What happens if only one character is entered?

Ans:
The tree contains only one node, and this program
prints an empty code.

Q76. What happens if two characters have the same frequency?

Ans:
Either may be selected first depending on the priority
queue's tie-breaking behavior.

Q77. Does Huffman Coding always reduce the file size?

Ans:
No. For small inputs, storing the tree and other
metadata may make the compressed file larger.

Q78. What is the weighted path length?

Ans:
The sum of each character's frequency multiplied by
its code length.

Q79. What is the main goal of Huffman Coding?

Ans:
To minimize the total weighted code length.

Q80. Can Huffman Coding handle spaces and special characters?

Ans:
Yes, provided they are correctly supplied and handled
as input symbols.

Q81. Can Huffman Coding be used for images?

Ans:
Yes. It can be used in image compression systems.

Q82. Is Huffman Coding used in ZIP compression?

Ans:
Yes. Huffman coding is used in DEFLATE, which is used
by ZIP and gzip.

Q83. What is the difference between Huffman Coding
and Run-Length Encoding?

Ans:
Huffman Coding assigns variable-length codes based on
frequency, while Run-Length Encoding stores repeated
values using counts.

Q84. What happens if we use a normal queue instead
of a priority queue?

Ans:
We would need another way to find the two minimum
frequencies. A normal queue does not automatically
maintain frequency priority.

Q85. Why do we use a binary tree instead of an array?

Ans:
A binary tree naturally represents the hierarchical
structure of prefix codes.

Q86. What is the difference between a leaf and
an internal node?

Ans:
A leaf represents an input character, while an internal
node represents a combination of frequencies.

Q87. Can two characters have the same Huffman code?

Ans:
No. A valid Huffman code assigns a distinct codeword
to each symbol.

Q88. Is Huffman Coding a lossy or lossless technique?

Ans:
Lossless.

Q89. What is the advantage of Huffman Coding?

Ans:
It reduces the average number of bits required to
represent symbols.

Q90. What is its limitation?

Ans:
It requires frequency information and code-tree
information for decoding, and it may not compress
every input effectively.

Q91. What happens if frequency is negative?

Ans:
The program rejects the input because of freq <= 0.

Q92. What happens if n is negative?

Ans:
The program prints an invalid number of characters message.

Q93. What is the purpose of newNode->left = left?

Ans:
It connects the first extracted node as the left child.

Q94. What is the purpose of newNode->right = right?

Ans:
It connects the second extracted node as the right child.

Q95. Why is the new node inserted again into the queue?

Ans:
Because it must participate in the next frequency comparison.

Q96. Why is the root obtained using pq.top()?

Ans:
Because after all merging operations, only the root
pointer remains in the priority queue.

Q97. What is the difference between pq.top() and pq.pop()?

Ans:
top() accesses the highest-priority element, whereas
pop() removes it.

Q98. What happens if we forget to call pq.pop() after top()?

Ans:
The same node will be selected again, and the tree
construction will not work correctly.

Q99. What is the difference between -> and . operators?

Ans:
-> accesses members through pointers, while .
accesses members through objects.

Q100. Why is the code passed as a string?

Ans:
To build the binary code while traversing the tree.


====================================================================
17. IMPORTANT POINTS TO REMEMBER FOR EXTERNAL VIVA
====================================================================

1. Huffman Coding is a lossless compression technique.
2. It uses the Greedy Algorithm.
3. Priority Queue is the main data structure.
4. The two minimum-frequency nodes are combined.
5. The new node stores the sum of their frequencies.
6. The process continues until one root node remains.
7. Left edge represents 0.
8. Right edge represents 1.
9. Leaf nodes represent original characters.
10. Internal nodes represent combined frequencies.
11. The code is prefix-free.
12. Tree construction complexity is O(n log n).
13. Tree and priority queue space complexity is O(n).
14. printCodes() uses recursion and DFS.
15. Frequently occurring characters generally receive
    shorter codes.

====================================================================
                    END OF EXPLANATION
====================================================================
*/