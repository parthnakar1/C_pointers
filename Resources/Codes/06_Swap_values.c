#include<stdio.h>

void pass_by_value(int x1, int x2)
{
    int temp = x2;
    x2 = x1;
    x1 = x2;
}

void pass_by_reference(int *x1, int *x2)
{
    int temp = *x2;
    *x2 = *x1;
    *x1 = temp;
}

int main()
{
    int x1 = 10, x2 = 20;
    printf("x1 = %d, x2 = %d\n",x1,x2);
    printf("Calling pass_by_value function\n");
    pass_by_value(x1,x2);
    printf("x1 = %d, x2 = %d\n",x1,x2);
    printf("Calling pass_by_reference function\n");
    pass_by_reference(&x1,&x2);
    printf("x1 = %d, x2 = %d\n",x1,x2);

    return 0;
}
/*
Expected output:
x1 = 10, x2 = 20
Calling pass_by_value function
x1 = 10, x2 = 20
Calling pass_by_reference function
x1 = 20, x2 = 10
*/
// The values are not swapped in pass_by_value as function copies the data in new stack frame, keeping original data as it is
// The values are swapped in pass_by reference as variable x1 and x2 addresses are passed as arguments.