#include<stdio.h>

int main()
{
    int a1 = 1;
    const int a2 = 2;

    // Constant Pointer to a Non Constant Variable
    int *const ptr_const_1 = &a1;
    // *ptr_const = 11;         invalid
    // a1 = 11;                 valid
    printf("Constant pointer (ptr_const_1)     points to address (variable int): %p, Value = %d\n",ptr_const_1,*ptr_const_1);

    // Constant Pointer to a Constant Variable
    // ptr_const_1 = &a2;       invalid
    const int *const ptr_const_2 = &a2;
    printf("Constant pointer (ptr_const_2)     points to address (constant int): %p, Value = %d\n",ptr_const_2,*ptr_const_2);

    // Pointer to Constant to a Non Constant variable
    const int *ptr_to_const = &a1;
    // *ptr_to_const = 22;      invalid
    // a2 = 22;                 invalid
    printf("Pointer to constant (ptr_to_const) points to address (variable int): %p, Value = %d\n",ptr_to_const,*ptr_to_const);
    
    // Pointer to Constant to a Constant Variable
    ptr_to_const = &a2;  // Pointer to constants can point to non constant variables
    // *ptr_to_const = 11;      invalid
    // a1 = 33;                 valid
    printf("Pointer to constant (ptr_to_const) points to address (constant int): %p, Value = %d\n",ptr_to_const,*ptr_to_const);

    return 0;
}
/*
Expected output:
Constant pointer (ptr_const_1)     points to address (variable int): 0x7ffd51a609d8, Value = 1
Constant pointer (ptr_const_2)     points to address (constant int): 0x7ffd51a609dc, Value = 2
Pointer to constant (ptr_to_const) points to address (variable int): 0x7ffd51a609d8, Value = 1
Pointer to constant (ptr_to_const) points to address (constant int): 0x7ffd51a609dc, Value = 2
*/