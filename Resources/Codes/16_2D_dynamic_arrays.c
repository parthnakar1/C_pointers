#include<stdio.h>
#include<stdlib.h>

int main()
{
    int row = 3, col = 3;
    // Contiguous memory alloation
    int *arr1 = (int *) malloc(row * col * sizeof(int));            // declaration 
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            *(arr1 + i*(col) + j) = i + j;                          // accessing dynamically allocated memory
        }
    }
    printf("Contiguous memory allocation\n");
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("array element at index (%d, %d) address : %p, value : %d\n",i,j,(arr1 + i*(col) + j),*(arr1 + i*(col) + j));
        }
    }
    free(arr1);

    return 0;
}
/*
Expected output:
Contiguous memory allocation
array element at index (0, 0) address : 0x5602067692a0, value : 0
array element at index (0, 1) address : 0x5602067692a4, value : 1
array element at index (0, 2) address : 0x5602067692a8, value : 2
array element at index (1, 0) address : 0x5602067692ac, value : 1
array element at index (1, 1) address : 0x5602067692b0, value : 2
array element at index (1, 2) address : 0x5602067692b4, value : 3
array element at index (2, 0) address : 0x5602067692b8, value : 2
array element at index (2, 1) address : 0x5602067692bc, value : 3
array element at index (2, 2) address : 0x5602067692c0, value : 4
*/