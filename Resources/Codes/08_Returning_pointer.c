#include<stdio.h>
#include<stdlib.h>

int *func1(int data)
{
    int *ptr = (int *) malloc(sizeof(int));
    *ptr = data;
    return ptr;
}

int main()
{
    int x = 10;
    int *ptr = func1(x);
    printf("Variable x,  value = %d, address : %p\n",x, &x);
    printf("Pointer ptr, value = %d, address : %p\n",*ptr,ptr);
    free(ptr);                                                // freeing pointer allocated by func1

    return 0;
}
/*
Expected output:
Variable x,  value = 10, address : 0x7fffec98529c
Pointer ptr, value = 10, address : 0x56426d82a2a0
*/