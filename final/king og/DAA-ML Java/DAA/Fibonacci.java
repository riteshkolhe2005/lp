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