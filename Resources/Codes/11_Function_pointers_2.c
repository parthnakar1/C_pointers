// This code tries to implement the following : 1. passing funcion pointer as an argument
//                                              2. An array of function pointers
#include<stdio.h>

void print_output(int ans)              // function to print output
{
    printf("The output of the operation (in int) is : %d\n",ans);
}

int add(int x1, int x2)
{
    return (x1 + x2);
}

int sub(int x1, int x2)
{
    return (x1 - x2);
}

int mul(int x1, int x2)
{
    return (x1 * x2);
}

int div(int x1, int x2)
{
    return (x1 / x2);
}

// the function that is central to exection of of all other functions
// its input arguments are a function pointer and two int variables
void calculate(void (*ptr)(int), int x1, int x2)
{
    // array of function pointers pointing to different operations
    int (*func_ptr_arr[4])(int x1, int x2) = {add, sub, mul, div};
    int result;
    for(int i = 0; i < 4; i++)
    {
        printf("Operation executed : %d\n",i+1);
        result = func_ptr_arr[i](x1,x2);                    // calling i th function pointer in the array
        ptr(result);                                        // calling function pointer passed as an argument
    }
}

int main()
{
    int x1 = 20, x2 = 10;
    void (*ptr1)(int);
    ptr1 = print_output;                                    // function pointer ptr1 points print_output(int) function
    printf("The four operations executed on x1 = %d and x2 = %d :\n",x1,x2);
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    calculate(ptr1,x1,x2);                                  // passing function pointer ptr1 and twi int variables as arguments

    return 0;
}
/*
Expected output:
he four operations executed on x1 = 20 and x2 = 10 :
1. Addition
2. Subtraction
3. Multiplication
4. Division
Operation executed : 1
The output of the operation (in int) is : 30
Operation executed : 2
The output of the operation (in int) is : 10
Operation executed : 3
The output of the operation (in int) is : 200
Operation executed : 4
The output of the operation (in int) is : 2
*/