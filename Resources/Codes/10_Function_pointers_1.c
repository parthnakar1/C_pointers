#include<stdio.h>
#include<stdlib.h>

void func1(int x1, int x2)
{
    if(x1 >= x2)
    {
        printf("x1 = %d is max\n",x1);
    }
    else
    {
        printf("x2 = %d is max\n",x2);
    }
}

int *func2(int x1)
{
    int *ptr = (int *) malloc(sizeof(int));
    *ptr = x1;
    return ptr;
}

int main()
{
    int x1 = 10, x2 = 20;
    void (*func_ptr1)(int,int);             // function pointer (return data type = void, two int inputs) declaration
    int *(*func_ptr2)(int);                 // function pointer (return data type = int pointer, one int input) declaration
    int *ptr = NULL;
    func_ptr1 = func1;                      // func_ptr1 assignment
    func_ptr2 = func2;                      // func_ptr2 assignment
    func_ptr1(x1,x2);                       // func1 call using function pointer
    ptr = func_ptr2(x1);                    // func2 call using function pointer
    printf("ptr : %p, value : %d\n",ptr,*ptr);
    free(ptr);                              // freeing ptr assigned by func2

    return 0;
}
/*
Expected output:
x2 = 20 is max
ptr : 0x55ad685be6b0, value : 10
*/