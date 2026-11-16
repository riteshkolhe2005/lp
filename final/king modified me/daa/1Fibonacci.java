```java
import java.util.*;
class Fibonacci 
{
    public static int fibonacci_Recurrsive(int num)
    {
        if(num==0 || num ==1)
        {
            return num;
        }
        return fibonacci_Recurrsive(num-1)+fibonacci_Recurrsive(num-2);
    }

    public static void fibonacci_Iterative(int num)
    {
        int x=0;
        int y=1;

        System.out.print("\n"+x+" "+y);

        for(int i=3;i<=num+1;i++)
        {
            int z=x+y;
            System.out.print(" "+z);
            x=y;
            y=z;
        }
    }

    public static void main(String args[])
    {
        System.out.println("Enter the Number to find Fibonacci Series Number : ");
        Scanner sn=new Scanner(System.in);
        int num=-1;

        while(true)
        {
            System.out.print("\n 1)Fibonacci Series Recurrsive\n 2)Fibonacci Series Iterative \n 3)Exit");
            System.out.print("\nEnter Your Choice : " );
            int choice = sn.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("\n Enter the Number : ");
                    num=sn.nextInt();
                    System.out.println(fibonacci_Recurrsive(num));
                    break;
                case 2:
                    System.out.print("\n Enter the Number : ");
                    num=sn.nextInt();
                    fibonacci_Iterative(num);
                    break;
                case 3: 
                    System.exit(choice);
                default:
                    break;
            }
        }
    }
}

/*
=========================================================
A) LINE-BY-LINE EXPLANATION
=========================================================

1. import java.util.*;
   - Imports all classes from the java.util package.
   - Scanner class is available in this package.
   - Scanner is used to accept input from the user.

2. class Fibonacci
   - Declares a class named Fibonacci.
   - All methods and the main function are defined inside this class.

3. public static int fibonacci_Recurrsive(int num)
   - Declares a method to calculate the Fibonacci number using recursion.
   - public: Accessible from anywhere.
   - static: Can be called without creating an object.
   - int: Returns an integer value.
   - num: Represents the position of the Fibonacci number.

4. if(num==0 || num ==1)
   - Checks the base condition.
   - If num is 0 or 1, the method directly returns num.
   - These are the first two Fibonacci numbers.

5. return num;
   - Returns 0 if num is 0.
   - Returns 1 if num is 1.
   - This condition stops infinite recursive calls.

6. return fibonacci_Recurrsive(num-1)+fibonacci_Recurrsive(num-2);
   - Calculates the Fibonacci number using recursion.
   - Calls the same function with num-1 and num-2.
   - Adds both returned values.
   - Formula: F(n) = F(n-1) + F(n-2).

7. public static void fibonacci_Iterative(int num)
   - Declares a method to calculate and print the Fibonacci series
     using iteration.
   - void means the method does not return any value.

8. int x=0;
   - Stores the first Fibonacci number.

9. int y=1;
   - Stores the second Fibonacci number.

10. System.out.print("\n"+x+" "+y);
    - Prints the first two Fibonacci numbers: 0 and 1.
    - \n moves the cursor to a new line.

11. for(int i=3;i<=num+1;i++)
    - Executes a loop to generate the remaining Fibonacci numbers.
    - i=3: Starts from the third position.
    - i<=num+1: Continues until the required position.
    - i++: Increases i by one after each iteration.

12. int z=x+y;
    - Calculates the next Fibonacci number.
    - Adds the previous two numbers.

13. System.out.print(" "+z);
    - Prints the newly calculated Fibonacci number.

14. x=y;
    - Updates x with the previous value of y.

15. y=z;
    - Updates y with the newly calculated Fibonacci number.
    - These updates prepare the variables for the next iteration.

16. public static void main(String args[])
    - Main method is the starting point of Java execution.
    - args is an array of command-line arguments.

17. System.out.println(...)
    - Displays a message asking the user to enter a number.

18. Scanner sn=new Scanner(System.in);
    - Creates a Scanner object.
    - System.in accepts input from the keyboard.

19. int num=-1;
    - Declares an integer variable.
    - Initially assigns -1 to it.

20. while(true)
    - Creates an infinite loop.
    - The menu continues to appear until the user selects Exit.

21. System.out.print(...)
    - Displays three menu options:
      1. Recursive Fibonacci
      2. Iterative Fibonacci
      3. Exit

22. int choice = sn.nextInt();
    - Accepts the user's menu choice.
    - nextInt() reads an integer.

23. switch(choice)
    - Selects the operation according to the user's choice.

24. case 1:
    - Executes when the user selects recursive Fibonacci.

25. num=sn.nextInt();
    - Accepts the number from the user.

26. System.out.println(fibonacci_Recurrsive(num));
    - Calls the recursive method.
    - Displays the calculated Fibonacci number.

27. break;
    - Terminates the current switch case.

28. case 2:
    - Executes when the user selects iterative Fibonacci.

29. num=sn.nextInt();
    - Accepts the number from the user.

30. fibonacci_Iterative(num);
    - Calls the iterative method.
    - Prints the Fibonacci series.

31. case 3:
    - Executes when the user selects Exit.

32. System.exit(choice);
    - Terminates the Java program.

33. default:
    - Executes when the entered choice does not match
      any available case.

34. break;
    - Exits the switch statement.


=========================================================
B) PROGRAM LOGIC (HOW TO EXPLAIN TO EXTERNAL EXAMINER)
=========================================================

OBJECTIVE:
To implement the Fibonacci series using two approaches:
1. Recursion
2. Iteration

WHAT IS FIBONACCI SERIES?

Fibonacci series is a sequence in which every number is
the sum of the previous two numbers.

Example:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ...

Mathematical formula:
F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2)

WORKING OF RECURSIVE METHOD:

1. The user selects option 1.
2. The program accepts a number.
3. The recursive function is called.
4. It checks whether the number is 0 or 1.
5. If yes, it returns the number.
6. Otherwise, it calls itself with num-1 and num-2.
7. Both returned values are added.
8. Finally, the calculated Fibonacci number is displayed.

Example: fibonacci_Recurrsive(5)

F(5) = F(4) + F(3)
F(4) = F(3) + F(2)
F(3) = F(2) + F(1)

Final Answer = 5

WORKING OF ITERATIVE METHOD:

1. The user selects option 2.
2. The program accepts a number.
3. Two variables x and y are initialized to 0 and 1.
4. The first two Fibonacci numbers are printed.
5. A for loop calculates the next number.
6. The next number is calculated using z = x + y.
7. Variables x and y are updated.
8. The loop continues until the required position.
9. The Fibonacci series is printed.

Example for num = 5:

Initially:
x = 0, y = 1

Iteration 1:
z = 0 + 1 = 1

Iteration 2:
z = 1 + 1 = 2

Iteration 3:
z = 1 + 2 = 3

Iteration 4:
z = 2 + 3 = 5

Output:
0 1 1 2 3 5


=========================================================
C) IMPORTANT CONCEPTS
=========================================================

1. RECURSION
   - Recursion is a programming technique in which a function
     calls itself.
   - Example: fibonacci_Recurrsive(num-1).

2. BASE CONDITION
   - A condition that stops recursive function calls.
   - In this program: if(num==0 || num==1).

3. ITERATION
   - Repeated execution of statements using loops.
   - This program uses a for loop.

4. FIBONACCI SERIES
   - A sequence where each number is the sum of the previous
     two numbers.

5. STATIC METHOD
   - A method that belongs to the class rather than an object.
   - It can be called directly using the class.

6. SCANNER CLASS
   - Used to accept input from the keyboard.
   - Example: Scanner sn=new Scanner(System.in).

7. SWITCH STATEMENT
   - Used for selecting one operation from multiple choices.

8. TIME COMPLEXITY

   Recursive approach:
   O(2^n) approximately.
   It performs repeated calculations.

   Iterative approach:
   O(n).
   It calculates each Fibonacci number once.

9. SPACE COMPLEXITY

   Recursive approach:
   O(n) auxiliary stack space due to recursive calls.

   Iterative approach:
   O(1) auxiliary space because it uses only three variables.

10. DIFFERENCE BETWEEN RECURSION AND ITERATION

   Recursion:
   - Function calls itself.
   - Uses function call stack.
   - Generally slower for this Fibonacci implementation.
   - Requires a base condition.

   Iteration:
   - Uses loops.
   - Does not require recursive function calls.
   - More efficient in this program.
   - Uses less memory.


=========================================================
D) EXPECTED EXTERNAL VIVA QUESTIONS WITH ANSWERS
=========================================================

Q1. What is Fibonacci series?
Ans: Fibonacci series is a sequence in which each number
is the sum of the previous two numbers.

Q2. What are the first two Fibonacci numbers?
Ans: 0 and 1.

Q3. What is the formula of Fibonacci series?
Ans: F(n) = F(n-1) + F(n-2).

Q4. What is recursion?
Ans: Recursion is a technique in which a function calls itself.

Q5. What is a base condition?
Ans: A base condition stops recursive function calls.

Q6. What is the base condition in your program?
Ans: if(num==0 || num==1).

Q7. Why do we use recursion?
Ans: It helps solve problems by breaking them into smaller
subproblems.

Q8. What is iteration?
Ans: Iteration means repeatedly executing statements using loops.

Q9. Which loop is used in your program?
Ans: For loop.

Q10. What is the difference between recursion and iteration?
Ans: Recursion uses function calls, whereas iteration uses loops.

Q11. Which approach is more efficient in your program?
Ans: Iterative approach because it has O(n) time complexity,
whereas the recursive approach takes approximately O(2^n).

Q12. What is the time complexity of recursive Fibonacci?
Ans: Approximately O(2^n).

Q13. What is the time complexity of iterative Fibonacci?
Ans: O(n).

Q14. What is the space complexity of recursive Fibonacci?
Ans: O(n) because of the recursive call stack.

Q15. What is the space complexity of iterative Fibonacci?
Ans: O(1) auxiliary space.

Q16. Why do we use static in this program?
Ans: Static allows us to call methods without creating an
object of the class.

Q17. What is the use of Scanner?
Ans: Scanner is used to accept input from the user.

Q18. What is System.in?
Ans: System.in represents the standard input stream,
usually the keyboard.

Q19. What is the use of switch?
Ans: Switch is used to execute different blocks depending
on the selected menu option.

Q20. What is the use of break?
Ans: Break terminates the current switch case or loop.

Q21. What happens if we remove the base condition?
Ans: Recursive calls will continue until a stack overflow
or another runtime failure occurs.

Q22. What is stack overflow?
Ans: Stack overflow occurs when the function call stack
exceeds its available memory.

Q23. Can Fibonacci numbers be negative?
Ans: The standard Fibonacci sequence starts from 0 and
continues with non-negative positions. This program does
not properly handle negative input.

Q24. Why are x and y updated?
Ans: To store the previous two Fibonacci numbers for
calculating the next number.

Q25. What is the difference between print() and println()?
Ans: print() displays output on the same line, whereas
println() moves the cursor to the next line.

Q26. What is System.exit()?
Ans: It terminates the currently running Java application.

Q27. What is the output for Fibonacci position 6?
Ans: The sixth Fibonacci number using zero-based indexing
is 8. The iterative method in this program prints the first
six Fibonacci numbers.

Q28. Why is iterative Fibonacci faster?
Ans: Because it avoids repeated calculations and calculates
each next number only once.

Q29. What is a method in Java?
Ans: A method is a block of code that performs a specific task.

Q30. Can we implement Fibonacci without recursion?
Ans: Yes, we can implement it using loops or iteration.


=========================================================
E) SAMPLE INPUT AND OUTPUT
=========================================================

EXAMPLE 1: RECURSIVE APPROACH

Input:
1
5

Output:
Enter the Number : 5
5

Explanation:
The fifth Fibonacci number using zero-based indexing is 5.

EXAMPLE 2: ITERATIVE APPROACH

Input:
2
5

Output:
Enter the Number : 5
0 1 1 2 3 5

Explanation:
The program prints the first 6 Fibonacci numbers because
the iterative method prints both initial values and then
executes the loop up to num+1.

EXAMPLE 3: EXIT

Input:
3

Output:
Program terminates.


=========================================================
F) COMMANDS TO RUN THE JAVA PROGRAM
=========================================================

STEP 1: Save the file

Save your program with the filename:

Fibonacci.java

IMPORTANT:
The filename must match the public class name if the class
is declared public. In this program, the class is not public,
but using Fibonacci.java is recommended.

STEP 2: WINDOWS

Open CMD or Terminal in the folder containing the file.

Compile:
javac Fibonacci.java

Run:
java Fibonacci

STEP 3: LINUX / UBUNTU

Open Terminal in the folder containing the file.

Compile:
javac Fibonacci.java

Run:
java Fibonacci

STEP 4: CHECK JAVA INSTALLATION

Check Java compiler:
javac -version

Check Java runtime:
java -version

If Java is not installed, install JDK first.


=========================================================
G) IMPORTANT POINTS TO REMEMBER FOR EXTERNAL VIVA
=========================================================

1. Fibonacci formula:
   F(n) = F(n-1) + F(n-2).

2. First two numbers:
   0 and 1.

3. Recursive method:
   Function calls itself.

4. Base condition:
   num == 0 || num == 1.

5. Iterative method:
   Uses a for loop.

6. Recursive time complexity:
   Approximately O(2^n).

7. Iterative time complexity:
   O(n).

8. Recursive space complexity:
   O(n).

9. Iterative auxiliary space complexity:
   O(1).

10. Iterative method is more efficient for this program.

IMPORTANT CODE OBSERVATION:
The iterative method prints num+1 Fibonacci numbers,
not exactly num numbers. For example, num=5 prints
0 1 1 2 3 5.

Also, the recursive method returns a single Fibonacci
number, whereas the iterative method prints the series.

=========================================================
END OF EXPLANATION
=========================================================
*/
```