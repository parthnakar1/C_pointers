#include<stdio.h>
#include<stdlib.h>

// static int *ptr1 = malloc(sizeof(int));      invalid - will give error
// int *ptr = (int *) malloc(sizeof(int));      invalid - will give error
int *global_ptr;            // declaration of global pointer

int main()
{
    printf("Pointers in pointing to memory in heap\n");
    
    global_ptr = (int *) malloc(sizeof(int));           // assigning address to global pointer inside main()
    *global_ptr = 10;                                   // data value assignment
    printf("global_ptr value : %d\t, address : %p\n",*global_ptr, global_ptr);

    int *local_ptr = (int *) malloc(sizeof(int));
    printf("Garbage value before assignment\n");
    printf("local_ptr  value : %d\t, address : %p\n",*local_ptr, local_ptr);
    *local_ptr = 20;
    printf("Value after assignment\n");
    printf("local_ptr  value : %d\t, address : %p\n",*local_ptr, local_ptr);

    int x = 30;
    int *ptr = &x;
    printf("Pointer not pointing to memory in heap\n");
    printf("ptr        value : %d\t, address : %p\n",*ptr, ptr);

    // recommended to use free() for pointers pointing to memory in heap.
    free(local_ptr);
    free(global_ptr);
    local_ptr = NULL; 
    // global_ptr now acts as a dangling pointer.
    printf("After freeing both pointers pointing to heap memory address\n");
    printf("global_ptr value : %d\t, address : %p\n",*global_ptr,global_ptr);
    // printf("local _ptr  value : %d\t, address : %p\n",*local_ptr,local_ptr);   this line would give segmentation fault as NULL is an invalid address.

    return 0;
}
/*
Expected output:
Pointers in pointing to memory in heap
global_ptr value : 10   , address : 0x56284c4676b0
Garbage value before assignment
local_ptr  value : 0    , address : 0x56284c4676d0
Value after assignment
local_ptr  value : 20   , address : 0x56284c4676d0
Pointer not pointing to memory in heap
ptr        value : 30   , address : 0x7ffe914de914
After freeing both pointers pointing to heap memory address
global_ptr value : 784511671    , address : 0x56284c4676b0
*/
// It can noted from addresses of global_ptr, local_ptr and ptr that ptr is in different location.(not heap)