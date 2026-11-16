#include <iostream>
using namespace std;

int main()
{
    int n, a = 0, b = 1, c;

    cout << "Enter number of terms: ";
    cin >> n;

    cout << "Fibonacci Series (Non-Recursive): ";

    for (int i = 0; i < n; i++)
    {
        cout << a << " ";

        c = a + b;
        a = b;
        b = c;
    }

    return 0;
}




/*
====================================================================
       FIBONACCI SERIES (NON-RECURSIVE) - COMPLETE EXPLANATION
====================================================================

1. AIM:
   To write a C++ program to generate the Fibonacci series for
   the given number of terms using a non-recursive (iterative)
   approach.

2. WHAT IS FIBONACCI SERIES?

   Fibonacci series is a sequence of numbers in which each
   number is obtained by adding the previous two numbers.

   The series starts with 0 and 1.

   Fibonacci Series:
   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

   Mathematical Formula:
   F(n) = F(n-1) + F(n-2)

   Initial Conditions:
   F(0) = 0
   F(1) = 1


====================================================================
3. LINE-BY-LINE CODE EXPLANATION
====================================================================

LINE 1:
#include <iostream>

Explanation:
- #include is a preprocessor directive.
- iostream stands for Input Output Stream.
- It is a standard C++ header file.
- It provides input and output functionality.
- It allows us to use cin and cout.
- Without this header file, cin and cout may not be available.

LINE 2:
using namespace std;

Explanation:
- namespace is used to organize identifiers.
- std is the standard namespace in C++.
- cout and cin belong to the std namespace.
- using namespace std allows us to use cin and cout
  without writing std:: before them.
- Without this statement, we must write std::cout and std::cin.

LINE 3:
int main()

Explanation:
- main() is the entry point of a C++ program.
- Program execution starts from the main() function.
- int indicates that the function returns an integer value
  to the operating system.
- Every standard C++ executable program must have a main()
  function.

LINE 4:
{

Explanation:
- Opening curly braces indicate the beginning of the main()
  function body.
- All statements inside these braces belong to main().

LINE 5:
int n, a = 0, b = 1, c;

Explanation:
- int is a data type used to store integer values.
- n stores the number of Fibonacci terms entered by the user.
- a stores the first current Fibonacci number.
- a is initialized to 0.
- b stores the second current Fibonacci number.
- b is initialized to 1.
- c is a temporary variable used to calculate the next
  Fibonacci number.
- All these variables are declared as integers.

LINE 6:
cout << "Enter number of terms: ";

Explanation:
- cout is used to display output on the screen.
- << is called the insertion operator.
- The message asks the user to enter the number of terms.
- The semicolon indicates the end of the statement.

LINE 7:
cin >> n;

Explanation:
- cin is used to accept input from the keyboard.
- >> is called the extraction operator.
- The entered value is stored in variable n.
- This value determines how many Fibonacci numbers
  will be displayed.

LINE 8:
cout << "Fibonacci Series (Non-Recursive): ";

Explanation:
- This statement displays the heading of the Fibonacci series.
- It informs the user that the program uses a non-recursive
  approach.
- Non-recursive means the program does not call the same
  function repeatedly.
- Instead, it uses an iterative loop.

LINE 9:
for (int i = 0; i < n; i++)

Explanation:
- for is an iteration or looping statement.
- It repeats a block of code a specified number of times.

It contains three parts:

1. int i = 0:
   Initializes the loop counter i to 0.

2. i < n:
   This is the loop termination condition.
   The loop continues as long as i is less than n.

3. i++:
   Increments i by 1 after each iteration.

- If n = 5, the loop executes 5 times.
- The loop generates exactly n Fibonacci terms.

LINE 10:
{

Explanation:
- Marks the beginning of the for loop body.
- All statements inside these braces execute during
  every iteration of the loop.

LINE 11:
cout << a << " ";

Explanation:
- Displays the current Fibonacci number stored in a.
- The space separates consecutive numbers.
- Initially, a = 0, so the first output is 0.

LINE 12:
c = a + b;

Explanation:
- Adds the current two Fibonacci numbers.
- Stores their sum in temporary variable c.
- This calculates the next Fibonacci number.
- For example, if a = 0 and b = 1:
  c = 0 + 1 = 1.

LINE 13:
a = b;

Explanation:
- Updates a with the value of b.
- The second current Fibonacci number becomes the first
  current Fibonacci number for the next iteration.
- This shifts the sequence forward.

LINE 14:
b = c;

Explanation:
- Updates b with the newly calculated Fibonacci number.
- The next pair of Fibonacci numbers is now ready.
- These two assignments maintain the Fibonacci sequence.

IMPORTANT:
The order of these three statements is important.

First:
c = a + b;

Second:
a = b;

Third:
b = c;

The temporary variable c preserves the sum before a and b
are updated.

LINE 15:
}

Explanation:
- Marks the end of the for loop body.
- The loop returns to its condition and checks whether
  another iteration is required.

LINE 16:
return 0;

Explanation:
- Terminates the main() function.
- Returns 0 to the operating system.
- A return value of 0 generally indicates successful
  program execution.

LINE 17:
}

Explanation:
- Marks the end of the main() function.
- The program execution is completed.


====================================================================
4. WORKING OF THE PROGRAM
====================================================================

The program generates Fibonacci numbers using an iterative
approach.

Steps:

1. Start the program.
2. Declare variables n, a, b and c.
3. Initialize a = 0 and b = 1.
4. Accept the number of terms from the user.
5. Execute the for loop.
6. Display the value of a.
7. Calculate c = a + b.
8. Update a = b.
9. Update b = c.
10. Repeat until i becomes equal to n.
11. Stop the program.


====================================================================
5. DRY RUN
====================================================================

Suppose the user enters:

n = 5

Initial values:
a = 0
b = 1

Iteration 1:
i = 0
Print a = 0
c = 0 + 1 = 1
a = 1
b = 1

Iteration 2:
i = 1
Print a = 1
c = 1 + 1 = 2
a = 1
b = 2

Iteration 3:
i = 2
Print a = 1
c = 1 + 2 = 3
a = 2
b = 3

Iteration 4:
i = 3
Print a = 2
c = 2 + 3 = 5
a = 3
b = 5

Iteration 5:
i = 4
Print a = 3
c = 3 + 5 = 8
a = 5
b = 8

Final Output:

Enter number of terms: 5
Fibonacci Series (Non-Recursive): 0 1 1 2 3


====================================================================
6. ALGORITHM
====================================================================

Step 1: Start.
Step 2: Declare n, a = 0, b = 1 and c.
Step 3: Read n.
Step 4: Repeat the following steps n times:
        a. Display a.
        b. Calculate c = a + b.
        c. Assign a = b.
        d. Assign b = c.
Step 5: Stop.


====================================================================
7. TIME AND SPACE COMPLEXITY
====================================================================

TIME COMPLEXITY:

O(n)

Reason:
- The for loop executes n times.
- Each iteration performs a constant number of operations.
- Therefore, total execution time increases linearly with n.

SPACE COMPLEXITY:

O(1)

Reason:
- The program uses only four integer variables.
- It does not use additional arrays or recursive function calls.
- Memory usage remains constant regardless of n.


====================================================================
8. IMPORTANT PROGRAMMING CONCEPTS
====================================================================

1. Iteration:
   Repeated execution of statements using a loop.

2. Recursion:
   A technique in which a function calls itself.

3. Non-Recursive Approach:
   A method that solves a problem without calling the same
   function recursively.

4. Variable:
   A named memory location used to store data.

5. Initialization:
   Assigning an initial value to a variable.

6. Increment Operator (++):
   Increases a variable's value by one.

7. Assignment Operator (=):
   Assigns the right-hand value to the left-hand variable.

8. Insertion Operator (<<):
   Used with cout to display output.

9. Extraction Operator (>>):
   Used with cin to accept input.

10. Loop:
    Executes a block of statements repeatedly.


====================================================================
9. VIVA QUESTIONS AND ANSWERS
====================================================================

BASIC VIVA QUESTIONS
--------------------

Q1. What is Fibonacci series?

Ans:
Fibonacci series is a sequence in which every number is
the sum of the previous two numbers.

Q2. What is the starting point of Fibonacci series?

Ans:
It starts with 0 and 1.

Q3. What is the mathematical formula of Fibonacci series?

Ans:
F(n) = F(n-1) + F(n-2).

Q4. What is the objective of this program?

Ans:
To generate Fibonacci numbers using an iterative or
non-recursive approach.

Q5. What is a non-recursive program?

Ans:
A program that solves a problem without calling the same
function recursively.

Q6. Which programming language is used?

Ans:
C++.

Q7. Which header file is used?

Ans:
<iostream>.

Q8. Why is iostream used?

Ans:
It provides input and output operations using cin and cout.

Q9. What is the use of main()?

Ans:
It is the starting point of program execution.

Q10. What is the use of return 0?

Ans:
It indicates successful termination of the program.


VARIABLE-RELATED QUESTIONS
--------------------------

Q11. What is the purpose of variable n?

Ans:
It stores the number of Fibonacci terms entered by the user.

Q12. What is the purpose of variable a?

Ans:
It stores the current first Fibonacci number.

Q13. What is the purpose of variable b?

Ans:
It stores the current second Fibonacci number.

Q14. What is the purpose of variable c?

Ans:
It temporarily stores the sum of a and b.

Q15. Why is a initialized to 0?

Ans:
Because the Fibonacci series starts with 0.

Q16. Why is b initialized to 1?

Ans:
Because 1 is the second number in the Fibonacci series.

Q17. Why is c not initialized?

Ans:
It receives its value through the expression c = a + b
before it is used.

Q18. Which data type is used?

Ans:
int, which stores integer values.

Q19. What happens if we use float instead of int?

Ans:
The program can still generate Fibonacci numbers, but
floating-point values are unnecessary for ordinary integer
Fibonacci calculations.

Q20. What happens if a and b are initialized to 1 and 1?

Ans:
The series becomes 1, 1, 2, 3, 5, 8, ...


LOOP-RELATED QUESTIONS
----------------------

Q21. Which loop is used in this program?

Ans:
for loop.

Q22. Why is a for loop used?

Ans:
Because the number of iterations is known in advance.

Q23. What is the initial value of i?

Ans:
0.

Q24. What is the loop condition?

Ans:
i < n.

Q25. What is the use of i++?

Ans:
It increments the loop counter by one.

Q26. If n = 10, how many times does the loop execute?

Ans:
10 times.

Q27. What happens if i <= n is used instead of i < n?

Ans:
The loop executes n + 1 times, producing one extra term.

Q28. What happens if i++ is removed?

Ans:
The loop counter does not increase, so if n is positive,
the loop becomes infinite.

Q29. Can we use a while loop instead?

Ans:
Yes. The same logic can be implemented using a while loop.

Q30. Can we use a do-while loop?

Ans:
Yes, but a do-while loop executes at least once, even
when n is zero or negative.


LOGIC-RELATED QUESTIONS
-----------------------

Q31. Why do we use c = a + b?

Ans:
To calculate the next Fibonacci number.

Q32. Why do we use a = b?

Ans:
To shift the second number into the first position.

Q33. Why do we use b = c?

Ans:
To shift the newly calculated number into the second position.

Q34. Why is c a temporary variable?

Ans:
It stores the sum before the original values of a and b
are updated.

Q35. What happens if we write a = b before c = a + b?

Ans:
The original value of a is lost, and the Fibonacci
calculation becomes incorrect.

Q36. What happens if we remove c = a + b?

Ans:
The next Fibonacci number will not be calculated correctly.

Q37. What happens if we remove a = b?

Ans:
The first number will not update correctly.

Q38. What happens if we remove b = c?

Ans:
The second number will not update correctly.

Q39. Why is the number printed before updating a and b?

Ans:
Because we want to display the current Fibonacci number
before moving to the next pair.

Q40. Can we generate Fibonacci series without using c?

Ans:
Yes. We can use another temporary variable or use
structured assignment techniques, but a temporary value
is still needed to preserve the old values.


OUTPUT-BASED QUESTIONS
----------------------

Q41. What is the output when n = 1?

Ans:
0

Q42. What is the output when n = 2?

Ans:
0 1

Q43. What is the output when n = 5?

Ans:
0 1 1 2 3

Q44. What is the output when n = 7?

Ans:
0 1 1 2 3 5 8

Q45. What happens when n = 0?

Ans:
The loop does not execute, so no Fibonacci numbers
are printed.

Q46. What happens when n is negative?

Ans:
The loop condition i < n is initially false, so no terms
are printed.

Q47. What happens when n = 10?

Ans:
0 1 1 2 3 5 8 13 21 34


COMPLEXITY-RELATED QUESTIONS
----------------------------

Q48. What is the time complexity?

Ans:
O(n).

Q49. Why is the time complexity O(n)?

Ans:
Because the loop executes n times, and each iteration
performs a constant number of operations.

Q50. What is the space complexity?

Ans:
O(1).

Q51. Why is the space complexity O(1)?

Ans:
Because only a fixed number of variables are used.

Q52. Is this approach efficient?

Ans:
Yes. It generates the sequence iteratively using linear
time and constant auxiliary space.


ADVANCED VIVA QUESTIONS
-----------------------

Q53. What is the difference between recursion and iteration?

Ans:
Recursion involves a function calling itself, whereas
iteration repeats statements using loops.

Q54. Which approach is better for Fibonacci series:
recursive or non-recursive?

Ans:
The iterative approach is generally more efficient in
this implementation because it takes O(n) time and O(1)
auxiliary space.

Q55. What is the time complexity of the basic recursive
Fibonacci implementation?

Ans:
It is exponential, approximately O(2^n).

Q56. What is the disadvantage of recursion?

Ans:
It requires additional function call stack memory and
may cause stack overflow for deep recursion.

Q57. What is an infinite loop?

Ans:
A loop that never terminates because its stopping
condition never becomes false.

Q58. What is a temporary variable?

Ans:
A variable used to temporarily store a value during
computation.

Q59. What is the difference between = and ==?

Ans:
= is the assignment operator.
== is the equality comparison operator.

Q60. What is the difference between ++i and i++?

Ans:
Both increment i by one. Prefix increment returns the
incremented value, while postfix increment returns the
original value before incrementing.

Q61. What is the maximum Fibonacci number that can be
stored in a signed 32-bit int?

Ans:
The largest Fibonacci number that fits is F(46) = 1836311903.
F(47) = 2971215073 exceeds the maximum signed 32-bit int.

Q62. What happens when integer overflow occurs?

Ans:
For signed integers in C++, overflow is undefined behavior.
The program must use a sufficiently large data type or
another suitable approach to avoid it.

Q63. Can we use long long instead of int?

Ans:
Yes. long long supports a larger range of integer values.

Q64. Can Fibonacci numbers be negative?

Ans:
The standard sequence generated by this program is
non-negative. Extended Fibonacci sequences can also
be defined for negative indices.

Q65. What are real-world applications of Fibonacci numbers?

Ans:
They appear in mathematical modelling, algorithm design,
computer science, number theory, and some natural growth
patterns.


====================================================================
10. IMPORTANT POINTS TO REMEMBER FOR EXTERNAL VIVA
====================================================================

1. Fibonacci series starts with 0 and 1.
2. Every next number is the sum of the previous two.
3. This program uses an iterative approach.
4. The for loop executes n times.
5. Variable c temporarily stores the sum.
6. Time complexity is O(n).
7. Auxiliary space complexity is O(1).
8. No recursive function is used.
9. The sequence is generated using three variables.
10. Statement order is important for correct execution.

====================================================================
                    END OF EXPLANATION
====================================================================
*/



/*
====================================================================
11. SAMPLE INPUT AND SAMPLE OUTPUT
====================================================================

SAMPLE INPUT 1:

Enter number of terms: 5


SAMPLE OUTPUT 1:

Fibonacci Series (Non-Recursive): 0 1 1 2 3


EXPLANATION:

- The user enters 5.
- Therefore, the for loop executes 5 times.
- The program prints the first 5 Fibonacci numbers.
- The resulting series is 0, 1, 1, 2, 3.


------------------------------------------------------------

SAMPLE INPUT 2:

Enter number of terms: 8


SAMPLE OUTPUT 2:

Fibonacci Series (Non-Recursive): 0 1 1 2 3 5 8 13


EXPLANATION:

- The user enters 8.
- The loop executes 8 times.
- The program generates and displays 8 Fibonacci numbers.


------------------------------------------------------------

SAMPLE INPUT 3:

Enter number of terms: 1


SAMPLE OUTPUT 3:

Fibonacci Series (Non-Recursive): 0


EXPLANATION:

- The user enters 1.
- The loop executes only once.
- Only the first Fibonacci number (0) is displayed.


------------------------------------------------------------

SAMPLE INPUT 4:

Enter number of terms: 10


SAMPLE OUTPUT 4:

Fibonacci Series (Non-Recursive): 0 1 1 2 3 5 8 13 21 34


EXPLANATION:

- The user enters 10.
- The loop executes 10 times.
- The first 10 Fibonacci numbers are displayed.


====================================================================
12. IMPORTANT OBSERVATIONS
====================================================================

1. If input is 0, no Fibonacci terms are displayed.
2. If input is 1, output is 0.
3. If input is 2, output is 0 1.
4. Each new number is the sum of the previous two numbers.
5. The program generates exactly n terms for positive n.
6. The program uses an iterative approach instead of recursion.

====================================================================
                    END OF EXPLANATION
====================================================================
*/
