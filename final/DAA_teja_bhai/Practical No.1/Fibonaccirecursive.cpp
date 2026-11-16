#include <iostream>
using namespace std;

int fibRecursive(int n)
{
    if (n <= 1)
        return n;

    return fibRecursive(n - 1) +
           fibRecursive(n - 2);
}

int main()
{
    int n;

    cout << "Enter number of terms: ";
    cin >> n;

    cout << "Fibonacci Series (Recursive): ";

    for (int i = 0; i < n; i++)
    {
        cout << fibRecursive(i) << " ";
    }

    return 0;
}


/*
====================================================================
          FIBONACCI SERIES (RECURSIVE) - COMPLETE EXPLANATION
====================================================================

1. AIM:
   To write a C++ program to generate the Fibonacci series
   using a recursive function.

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

LINE 2:
using namespace std;

Explanation:
- namespace is used to organize identifiers.
- std is the standard namespace in C++.
- cin and cout belong to the std namespace.
- This statement allows us to use cin and cout without
  writing std:: before them.

LINE 3:
int fibRecursive(int n)

Explanation:
- This is a user-defined function.
- fibRecursive is the name of the function.
- int indicates that the function returns an integer.
- int n is the parameter passed to the function.
- The function calculates and returns the nth Fibonacci
  number.
- This function calls itself, so it is called a recursive
  function.

LINE 4:
{

Explanation:
- Opening curly braces indicate the beginning of the
  function body.
- All statements inside these braces belong to the
  fibRecursive() function.

LINE 5:
if (n <= 1)

Explanation:
- if is a conditional statement.
- It checks whether n is less than or equal to 1.
- This condition represents the base condition of recursion.
- It prevents the function from calling itself indefinitely.
- For n = 0 or n = 1, the condition becomes true.

LINE 6:
return n;

Explanation:
- return sends a value back to the calling function.
- If n = 0, it returns 0.
- If n = 1, it returns 1.
- This is the base case of the Fibonacci sequence.
- It stops further recursive calls for these values.

IMPORTANT:
Base condition is necessary to terminate recursion.
Without it, recursive calls would continue until the
program runs out of stack memory.

LINE 7:
return fibRecursive(n - 1) +

Explanation:
- This statement calculates the Fibonacci number using
  the recursive approach.
- fibRecursive(n - 1) calls the same function with n - 1.
- The function calculates the previous Fibonacci number.
- The return value is added to the second recursive call.

LINE 8:
fibRecursive(n - 2);

Explanation:
- This calls the same function with n - 2.
- It calculates the Fibonacci number before the previous
  Fibonacci number.
- Both recursive results are added together.
- This follows the mathematical Fibonacci formula.

Example:
fibRecursive(4)

= fibRecursive(3) + fibRecursive(2)

= 2 + 1

= 3

LINE 9:
}

Explanation:
- Marks the end of the fibRecursive() function.

LINE 10:
int main()

Explanation:
- main() is the starting point of program execution.
- int indicates that the function returns an integer value
  to the operating system.

LINE 11:
{

Explanation:
- Marks the beginning of the main() function body.

LINE 12:
int n;

Explanation:
- Declares an integer variable n.
- It stores the number of Fibonacci terms entered by
  the user.

LINE 13:
cout << "Enter number of terms: ";

Explanation:
- cout displays output on the screen.
- << is called the insertion operator.
- It displays a message asking the user to enter the
  number of terms.

LINE 14:
cin >> n;

Explanation:
- cin accepts input from the keyboard.
- >> is called the extraction operator.
- The entered value is stored in variable n.

LINE 15:
cout << "Fibonacci Series (Recursive): ";

Explanation:
- Displays the heading of the Fibonacci series.
- It indicates that the program uses recursion.

LINE 16:
for (int i = 0; i < n; i++)

Explanation:
- This is a for loop.
- It executes the loop body n times when n is positive.

Three parts:

1. int i = 0:
   Initializes the loop counter to 0.

2. i < n:
   Checks whether the loop should continue.

3. i++:
   Increments the loop counter by 1.

LINE 17:
{

Explanation:
- Marks the beginning of the for loop body.

LINE 18:
cout << fibRecursive(i) << " ";

Explanation:
- Calls the fibRecursive() function with the current
  value of i.
- The function calculates the ith Fibonacci number.
- cout displays the returned value.
- A space separates consecutive Fibonacci numbers.

Example:
If i = 4:

fibRecursive(4) returns 3.

Therefore, 3 is displayed.

LINE 19:
}

Explanation:
- Marks the end of the for loop body.
- The loop increments i and checks its condition again.

LINE 20:
return 0;

Explanation:
- Terminates the main() function.
- Returns 0 to the operating system.
- Indicates successful program execution.

LINE 21:
}

Explanation:
- Marks the end of the main() function.
- The program execution is completed.


====================================================================
4. WHAT IS RECURSION?
====================================================================

Recursion is a programming technique in which a function
calls itself to solve a problem.

In this program, fibRecursive() calls itself with smaller
values of n.

There are two important parts of recursion:

1. BASE CASE:
   The condition that stops recursive calls.

   In this program:
   if (n <= 1)
       return n;

2. RECURSIVE CASE:
   The part where a function calls itself.

   In this program:
   return fibRecursive(n - 1) +
          fibRecursive(n - 2);

The base case prevents infinite recursion.


====================================================================
5. WORKING OF THE PROGRAM
====================================================================

Steps:

1. Start the program.
2. Define the recursive function fibRecursive().
3. Accept the number of terms from the user.
4. Execute the for loop from i = 0 to i < n.
5. Call fibRecursive(i) for each iteration.
6. Check whether n <= 1.
7. If true, return n.
8. Otherwise, calculate:
   fibRecursive(n - 1) + fibRecursive(n - 2).
9. Continue recursive calls until base conditions are reached.
10. Return the calculated Fibonacci number.
11. Display the result.
12. Repeat for all n terms.
13. Stop the program.


====================================================================
6. DRY RUN
====================================================================

Suppose the user enters:

n = 5

The for loop calls:

fibRecursive(0)
fibRecursive(1)
fibRecursive(2)
fibRecursive(3)
fibRecursive(4)

CALCULATION:

1. fibRecursive(0)

   Since 0 <= 1:
   Return 0.

2. fibRecursive(1)

   Since 1 <= 1:
   Return 1.

3. fibRecursive(2)

   = fibRecursive(1) + fibRecursive(0)
   = 1 + 0
   = 1

4. fibRecursive(3)

   = fibRecursive(2) + fibRecursive(1)
   = 1 + 1
   = 2

5. fibRecursive(4)

   = fibRecursive(3) + fibRecursive(2)
   = 2 + 1
   = 3

FINAL OUTPUT:

0 1 1 2 3


====================================================================
7. RECURSION TREE FOR fibRecursive(4)
====================================================================

                  fib(4)
                 /      \
             fib(3)    fib(2)
             /   \      /   \
          fib(2) fib(1) fib(1) fib(0)
           /   \
        fib(1) fib(0)

Calculation:

fib(4) = fib(3) + fib(2)
       = 2 + 1
       = 3

Note:
Some function calls are repeated, which makes the basic
recursive Fibonacci approach inefficient for large inputs.


====================================================================
8. ALGORITHM
====================================================================

Step 1: Start.
Step 2: Define function fibRecursive(n).
Step 3: Check if n <= 1.
Step 4: If true, return n.
Step 5: Otherwise, calculate:
        fibRecursive(n-1) + fibRecursive(n-2).
Step 6: Accept the number of terms from the user.
Step 7: Repeat from i = 0 to n-1.
Step 8: Call fibRecursive(i).
Step 9: Display the returned Fibonacci number.
Step 10: Stop.


====================================================================
9. TIME AND SPACE COMPLEXITY
====================================================================

TIME COMPLEXITY:

O(2^n) as a conventional upper bound for the naive recursive
Fibonacci function.

Reason:
- Each function call can generate two additional calls.
- Many Fibonacci values are calculated repeatedly.
- The number of calls grows exponentially.

For generating n terms, the total running time is also
O(2^n), dominated by the last Fibonacci calculation.

SPACE COMPLEXITY:

O(n) auxiliary space.

Reason:
- Recursive function calls are stored in the call stack.
- The maximum recursion depth is proportional to n.
- The function calls must finish before returning their
  calculated values.

IMPORTANT:
This recursive approach is less efficient than the
iterative Fibonacci program for large inputs.


====================================================================
10. SAMPLE INPUT AND SAMPLE OUTPUT
====================================================================

SAMPLE INPUT 1:

Enter number of terms: 5

SAMPLE OUTPUT 1:

Fibonacci Series (Recursive): 0 1 1 2 3

EXPLANATION:
- User enters 5.
- The loop executes 5 times.
- The recursive function calculates the first 5 terms.
- The output is 0 1 1 2 3.


------------------------------------------------------------

SAMPLE INPUT 2:

Enter number of terms: 8

SAMPLE OUTPUT 2:

Fibonacci Series (Recursive): 0 1 1 2 3 5 8 13

EXPLANATION:
- User enters 8.
- The loop executes 8 times.
- Eight Fibonacci numbers are calculated recursively.


------------------------------------------------------------

SAMPLE INPUT 3:

Enter number of terms: 1

SAMPLE OUTPUT 3:

Fibonacci Series (Recursive): 0

EXPLANATION:
- User enters 1.
- The loop executes once.
- fibRecursive(0) returns 0.


------------------------------------------------------------

SAMPLE INPUT 4:

Enter number of terms: 10

SAMPLE OUTPUT 4:

Fibonacci Series (Recursive): 0 1 1 2 3 5 8 13 21 34

EXPLANATION:
- User enters 10.
- The loop executes 10 times.
- The first 10 Fibonacci numbers are displayed.


====================================================================
11. VIVA QUESTIONS AND ANSWERS
====================================================================

BASIC VIVA QUESTIONS
--------------------

Q1. What is Fibonacci series?

Ans:
It is a sequence in which every number is the sum of
the previous two numbers.

Q2. What is the objective of this program?

Ans:
To generate Fibonacci numbers using recursion.

Q3. Which programming language is used?

Ans:
C++.

Q4. Which header file is used?

Ans:
<iostream>.

Q5. What is recursion?

Ans:
Recursion is a programming technique in which a function
calls itself.

Q6. What is a recursive function?

Ans:
A function that calls itself is called a recursive function.

Q7. Which function is recursive in this program?

Ans:
fibRecursive().

Q8. What is the starting point of the program?

Ans:
main() function.

Q9. What is the starting value of Fibonacci series?

Ans:
0 and 1.

Q10. What is the Fibonacci formula?

Ans:
F(n) = F(n-1) + F(n-2).


RECURSION-RELATED QUESTIONS
---------------------------

Q11. What is a base case?

Ans:
A condition that stops recursive function calls.

Q12. What is the base case in this program?

Ans:
if (n <= 1).

Q13. Why is a base case necessary?

Ans:
To prevent infinite recursive calls and terminate recursion.

Q14. What is the recursive case?

Ans:
The part where a function calls itself with smaller inputs.

Q15. What is the recursive statement in this program?

Ans:
fibRecursive(n-1) + fibRecursive(n-2).

Q16. What happens if the base case is removed?

Ans:
The function will continue making recursive calls and
eventually may cause stack overflow.

Q17. What is a call stack?

Ans:
A memory structure that stores information about active
function calls.

Q18. What is stack overflow?

Ans:
An error condition caused when the call stack exceeds
its available memory.

Q19. What is a recursive call?

Ans:
When a function calls itself, it is called a recursive call.

Q20. What happens when n = 0?

Ans:
The function returns 0.

Q21. What happens when n = 1?

Ans:
The function returns 1.

Q22. Why does fibRecursive(n-1) call fibRecursive(n-2)?

Ans:
To calculate the two previous Fibonacci numbers and
add them together.


FUNCTION-RELATED QUESTIONS
--------------------------

Q23. What is a user-defined function?

Ans:
A function created by the programmer to perform a
specific task.

Q24. What is the return type of fibRecursive()?

Ans:
int.

Q25. What is the parameter of fibRecursive()?

Ans:
Integer variable n.

Q26. What does return n mean?

Ans:
It sends the value of n back to the calling function.

Q27. Can a function call itself?

Ans:
Yes. This technique is called recursion.

Q28. Can recursion be implemented without a loop?

Ans:
Yes. A recursive function can perform repeated operations
through function calls.

Q29. Is main() recursive in this program?

Ans:
No. Only fibRecursive() calls itself.

Q30. What is the difference between function declaration
and function definition?

Ans:
A declaration specifies the function interface, while
a definition contains the actual implementation.


LOOP-RELATED QUESTIONS
---------------------

Q31. Which loop is used in main()?

Ans:
for loop.

Q32. Why is a for loop used?

Ans:
To call the recursive function for each Fibonacci term.

Q33. What is the initial value of i?

Ans:
0.

Q34. What is the loop condition?

Ans:
i < n.

Q35. What is the use of i++?

Ans:
It increments the loop counter by one.

Q36. If n = 5, how many times does the loop execute?

Ans:
5 times.

Q37. Can we replace the for loop with a while loop?

Ans:
Yes.


OUTPUT-BASED QUESTIONS
----------------------

Q38. What is the output when n = 1?

Ans:
0

Q39. What is the output when n = 2?

Ans:
0 1

Q40. What is the output when n = 5?

Ans:
0 1 1 2 3

Q41. What is the output when n = 7?

Ans:
0 1 1 2 3 5 8

Q42. What happens when n = 0?

Ans:
The loop does not execute, so no terms are printed.

Q43. What happens when n is negative?

Ans:
The loop does not execute because i < n is initially false.


COMPLEXITY-RELATED QUESTIONS
----------------------------

Q44. What is the time complexity of recursive Fibonacci?

Ans:
O(2^n) as a conventional upper bound.

Q45. Why is recursive Fibonacci inefficient?

Ans:
Because it calculates the same Fibonacci values repeatedly.

Q46. What is the space complexity?

Ans:
O(n).

Q47. Why is space complexity O(n)?

Ans:
Because recursive calls are stored in the call stack.

Q48. Which approach is faster: recursive or iterative?

Ans:
The iterative approach is faster for this problem because
it calculates each term once.

Q49. What is the complexity of iterative Fibonacci?

Ans:
Time: O(n).
Auxiliary space: O(1).

Q50. Can recursion be optimized?

Ans:
Yes. Memoization and dynamic programming can avoid
repeated calculations.


ADVANCED AND TRICKY EXTERNAL VIVA QUESTIONS
-------------------------------------------

Q51. What is the difference between recursion and iteration?

Ans:
Recursion uses repeated function calls, whereas iteration
uses loops to repeat statements.

Q52. What is direct recursion?

Ans:
When a function directly calls itself.

Q53. Is this program using direct recursion?

Ans:
Yes.

Q54. What is indirect recursion?

Ans:
When one function calls another function, which eventually
calls the first function again.

Q55. What is tail recursion?

Ans:
A recursion in which the recursive call is the final
operation performed by the function.

Q56. Is this Fibonacci function tail recursive?

Ans:
No. It must add the results of two recursive calls after
those calls return.

Q57. What is multiple recursion?

Ans:
When a function makes more than one recursive call.
This program uses multiple recursion because it makes
two recursive calls.

Q58. What is overlapping subproblem?

Ans:
When the same smaller problem is calculated repeatedly.

Q59. Does this program have overlapping subproblems?

Ans:
Yes. For example, fibRecursive(2) is calculated multiple
times while calculating fibRecursive(4) and larger values.

Q60. What is memoization?

Ans:
A technique that stores previously calculated results
to avoid repeated calculations.

Q61. What is dynamic programming?

Ans:
A problem-solving technique that stores results of
subproblems and reuses them.

Q62. What happens if n = 4?

Ans:
The output is 0 1 1 2.

Q63. What happens if we change n - 2 to n - 1?

Ans:
The mathematical Fibonacci formula is changed, and the
program will no longer calculate the standard sequence.

Q64. What happens if the base condition becomes n == 1?

Ans:
The function no longer handles n = 0 as a base case,
which can lead to unbounded recursion for that input.

Q65. What happens if we use n < 1 instead of n <= 1?

Ans:
The value n = 1 will not be handled by the base case,
causing incorrect recursion.

Q66. Can we calculate Fibonacci using an array?

Ans:
Yes. We can store previously calculated Fibonacci values
in an array using dynamic programming.

Q67. What is the maximum Fibonacci number that fits in
a signed 32-bit int?

Ans:
F(46) = 1836311903.
F(47) exceeds the maximum signed 32-bit integer.

Q68. What happens when signed integer overflow occurs?

Ans:
It results in undefined behavior in C++.

Q69. Why is recursion useful?

Ans:
It makes problems with naturally recursive structures
easier to express, such as tree traversal and divide-and-
conquer algorithms.

Q70. What are the disadvantages of recursion?

Ans:
- Additional call stack memory.
- Function call overhead.
- Possible stack overflow.
- Repeated calculations in inefficient recursive algorithms.


====================================================================
12. IMPORTANT DIFFERENCES: RECURSIVE VS NON-RECURSIVE
====================================================================

RECURSIVE APPROACH:

1. Uses a function that calls itself.
2. Uses a call stack.
3. Time complexity for this implementation: O(2^n)
   as a conventional upper bound.
4. Auxiliary space complexity: O(n).
5. Recalculates Fibonacci values repeatedly.

NON-RECURSIVE APPROACH:

1. Uses a loop.
2. Does not use recursive function calls.
3. Time complexity: O(n).
4. Auxiliary space complexity: O(1).
5. Calculates each Fibonacci term once.

CONCLUSION:

The iterative approach is more efficient for generating
Fibonacci numbers, while recursion demonstrates the
concept of a function calling itself.


====================================================================
13. IMPORTANT POINTS TO REMEMBER FOR EXTERNAL VIVA
====================================================================

1. The program generates Fibonacci numbers using recursion.
2. fibRecursive() is the recursive function.
3. Base condition is n <= 1.
4. Recursive formula is F(n) = F(n-1) + F(n-2).
5. The function returns an integer.
6. The for loop generates n terms.
7. Time complexity is O(2^n) as a conventional upper bound.
8. Auxiliary space complexity is O(n).
9. Recursive calls are stored in the call stack.
10. Repeated calculations make this implementation inefficient.
11. Memoization can improve performance.
12. Iterative Fibonacci is generally more efficient.


====================================================================
                    END OF EXPLANATION
====================================================================
*/