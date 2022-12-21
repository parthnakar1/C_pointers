#include<stdio.h>

int main()
{
    int x = 10;
    int y = 20;
    // Different types of pointer declarations
    int * ptr1;              // Pointer declaration but no assignment
    int* ptr2 = &y;          // Assignment during declaration
    int *ptr3 = NULL;        // Assigning NULL to a pointer
    void*ptr4; 
    ptr1 = &x;               // Assignment after declaration


    printf("Value of x = %d stored at location = %p\n",x,&x);
    printf("Value of y = %d stored at location = %p\n",y,&y);
    printf("ptr1 points at value = %d, stores (address of variable x) = %p and itself is stored at location = %p\n",*ptr1,ptr1,&ptr1);
    printf("ptr2 points at value = %d, stores (address of variable x) = %p and itself is stored at location = %p\n",*ptr2,ptr2,&ptr2);
    // Next statement if executed will give "Segmentation fault (core dumped)" error
    // printf("ptr3 points at value = %d, stores (address of variable x) = %p and itself is stored at location = %p\n",*ptr3,ptr3,&ptr3);
    // ptr4(void type) points to variable x
    ptr4 = &x;
    printf("ptr4(void type) points to variable x(int type)\n");
    printf("ptr4 points at value = %d, stores (address of variable x) = %p and itself is stored at location = %p\n",*(int*)ptr4,ptr4,&ptr4);
    
    ptr4 = &y;
    printf("ptr4(void type) points to variable y(int type)\n");
    printf("ptr4 points at value = %d, stores (address of variable x) = %p and itself is stored at location = %p\n",*(int*)ptr4,ptr4,&ptr4);
    
    if(ptr3)
    {
        printf("ptr3 is NULL\n");
    }
    else
    {
        printf("ptr3 is not NULL\n");
    }

    return 0;
}

/*
Value of x = 10 stored at location = 0x7ffc3c757860
Value of y = 20 stored at location = 0x7ffc3c757864
ptr1 points at value = 10, stores (address of variable x) = 0x7ffc3c757860 and itself is stored at location = 0x7ffc3c757868
ptr2 points at value = 20, stores (address of variable x) = 0x7ffc3c757864 and itself is stored at location = 0x7ffc3c757870
ptr4(void type) points to variable x(int type)
ptr4 points at value = 10, stores (address of variable x) = 0x7ffc3c757860 and itself is stored at location = 0x7ffc3c757878
ptr4(void type) points to variable y(int type)
ptr4 points at value = 20, stores (address of variable x) = 0x7ffc3c757864 and itself is stored at location = 0x7ffc3c757878
ptr3 is not NULL
*/