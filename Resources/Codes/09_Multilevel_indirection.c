#include<stdio.h>

void max(int **ptr,int *x1,int *x2)   // function that makes the pointer passed as argument point to max
{
    if(*x1 >= *x2)
    {
        *ptr = x1;
    }
    else
    {
        *ptr = x2;
    }
    printf("ptr        : %p, *ptr    : %p, **ptr    : %d\n",ptr,*ptr,**ptr);  // ptr saves the address of passed pointer,
}                                                                             // *ptr points to address saved by passed ptr and
                                                                              // **ptr points to value at saved address.
int main()
{
    int x1 = 5, x2 = 10;
    int *ptr_max = NULL;
    printf("x1 address : %p, value:%d\n",&x1,x1);
    printf("x2 address : %p, value:%d\n",&x2,x2);
    max(&ptr_max, &x1, &x2);
    printf("&ptr_max   : %p, ptr_max : %p, *ptr_max : %d\n",&ptr_max,ptr_max,*ptr_max);
    return 0;
}
/*
Expected output:
x1 address : 0x7ffccc966b88, value:5
x2 address : 0x7ffccc966b8c, value:10
ptr        : 0x7ffccc966b90, *ptr    : 0x7ffccc966b8c, **ptr    : 10
&ptr_max   : 0x7ffccc966b90, ptr_max : 0x7ffccc966b8c, *ptr_max : 10
*/