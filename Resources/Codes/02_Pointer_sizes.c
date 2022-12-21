#include<stdio.h>
#include<stdint.h> // contains data type to store addresses (i.e. pointer data type)

int main()
{
    char a1 = 'c';
    int a2 = 10;
    long a3 = 100;
    float a4 = 3.14;
    double a5 = 2.718;

    // Normal declaration of pointers in respective data types
    char *ptr_to_char = &a1;
    int *ptr_to_int = &a2;
    long int *ptr_to_long = &a3;
    float *ptr_to_float = &a4;
    double *ptr_to_double = &a5;
    // %p is used as default to print pointer type data.
    // %c, %d, %ld, %f, %lf are used for char, int, long, float, double respectively.
    // %lu refers to long unsigned int as sizeof() returns that data type.(size can never be negative hence unsigned)
    printf("Pointer to char     points to address : %p, Value = %c \t, Size of pointer : %lu\n",ptr_to_char,*ptr_to_char,sizeof(ptr_to_char));
    printf("Pointer to int      points to address : %p, Value = %d\t, Size of pointer : %lu\n",ptr_to_int,*ptr_to_int,sizeof(ptr_to_int));
    printf("Pointer to long int points to address : %p, Value = %ld\t, Size of pointer : %lu\n",ptr_to_long,*ptr_to_long,sizeof(ptr_to_long));
    printf("Pointer to float    points to address : %p, Value = %f, Size of pointer : %lu\n",ptr_to_float,*ptr_to_float,sizeof(ptr_to_float));
    printf("Pointer to double   points to address : %p, Value = %lf, Size of pointer : %lu\n",ptr_to_double,*ptr_to_double,sizeof(ptr_to_double));

    // intptr_t and uintptr_t data types for pointers
    intptr_t *ptr1 = &a1;
    printf("\nPointer of type 'intptr_t' points to address  : %p. Value = %c\n",ptr1,*ptr1); // some compiler versions may give warnings, can be ignored.
    // unitptr_t is always cast before assignment
    uintptr_t *ptr2 = (uintptr_t *)&a2;
    printf("Pointer of type 'uintptr_t' points to address : %p. Value = %d\n",ptr2,*ptr2); // some compiler versions may give warnings, can be ignored.

    return 0;
}
/*
Expected output:
Pointer to char     points to address : 0x7ffc86b1d757, Value = c       , Size of pointer : 8
Pointer to int      points to address : 0x7ffc86b1d758, Value = 10      , Size of pointer : 8
Pointer to long int points to address : 0x7ffc86b1d760, Value = 100     , Size of pointer : 8
Pointer to float    points to address : 0x7ffc86b1d75c, Value = 3.140000, Size of pointer : 8
Pointer to double   points to address : 0x7ffc86b1d768, Value = 2.718000, Size of pointer : 8

Pointer of type 'intptr_t' points to address  : 0x7ffc86b1d757. Value = c
Pointer of type 'uintptr_t' points to address : 0x7ffc86b1d758. Value = 10
*/