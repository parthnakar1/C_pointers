#include<stdio.h>
#include<stdlib.h>

int main()
{
    // calloc() example
    printf("Creating dynamic array using calloc()\n");
    int *ptr1 = (int *) calloc(5,sizeof(int));
    // creating another pointer for traversal otherwise start address would be lost and memory leak would take place
    int *ptr_traversal =  ptr1;
    // setting values in dynamic array
    for(int i = 0; i < 5; i++)
    {
        *ptr_traversal = i;
        ptr_traversal++;
    }
    
    ptr_traversal = ptr1;              // pointing ptr_traversal to start address again
    // reading values from dynamic array
    for(int i = 0; i < 5; i++)
    {
        printf("%d element : %d, address : %p\n",i+1, *ptr_traversal, ptr_traversal);
        ptr_traversal++;
    }

    // realloc() to smaller size
    printf("Dynamic array reallocated to smaller size\n");
    int *ptr2 = (int *) realloc(ptr1,3*sizeof(int));
    ptr_traversal = ptr2;
    for(int i = 0; i < 3; i++)
    {
        printf("%d element : %d, address : %p\n",i+1, *ptr_traversal, ptr_traversal);
        ptr_traversal++;
    }
    // reading extra data to check if we can find old data that existed before shrinking the size
    printf("Reading extra data after block size\n");
    for(int i = 0; i < 2; i++)
    {
        printf("%d element : %d, address : %p\n",i+1, *ptr_traversal, ptr_traversal);
        ptr_traversal++;
    }

    // realloc() to larger size
    printf("Dynamic array reallocated to larger size\n");
    int *ptr3 = (int *) realloc(ptr1,8*sizeof(int));
    ptr_traversal = ptr3;
    for(int i = 0; i < 8; i++)
    {
        printf("%d element : %d, address : %p\n",i+1, *ptr_traversal, ptr_traversal);
        ptr_traversal++;
    }
    
    // freeing the heap memory space
    // free(ptr1);              this line on execution gives runtime error double free detected.(as realloc() frees previous pointer)
    // free(ptr2);              since ptr2 was pointing to small realloc() it would be same address as ptr1 which is already freed.
    // free(ptr_traversal);     invalid, dangling pointer problem. A safe approach is to only free primary pointers and not any aliases.
    free(ptr3);

    return 0;
}

/*
Expected output:
Creating dynamic array using calloc()
1 element : 0, address : 0x5623f79876b0
2 element : 1, address : 0x5623f79876b4
3 element : 2, address : 0x5623f79876b8
4 element : 3, address : 0x5623f79876bc
5 element : 4, address : 0x5623f79876c0
Dynamic array reallocated to smaller size
1 element : 0, address : 0x5623f79876b0
2 element : 1, address : 0x5623f79876b4
3 element : 2, address : 0x5623f79876b8
Reading extra data after block size
1 element : 3, address : 0x5623f79876bc
2 element : 4, address : 0x5623f79876c0
Dynamic array reallocated to larger size
1 element : 0, address : 0x5623f79876b0
2 element : 1, address : 0x5623f79876b4
3 element : 2, address : 0x5623f79876b8
4 element : 3, address : 0x5623f79876bc
5 element : 4, address : 0x5623f79876c0
6 element : 0, address : 0x5623f79876c4
7 element : 133441, address : 0x5623f79876c8
8 element : 0, address : 0x5623f79876cc
*/
// when realloc() to small size the previous data could be read as expected due to same start address of block
// when realloc() to large size, newly added memory has garbage values (since they weren't initialized)