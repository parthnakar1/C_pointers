#include<stdio.h>

void assign_values(int arr[][3],int rows)               // passing 2d array using array notation
{                                                       // size of col should be known beforehand to detrmine offset value
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arr[i][j] = i*10 + j;
        }
    }
}

void print_output(int *ptr, int rows, int cols)         // passing 2d array using pointer notation
{                                                       // size of row and col both can be passed as argument 
    for(int i = 0; i < rows; i++)                       // since offset value = sizeof(ptr_data_type).
    {
        for(int j = 0; j < cols; j++)
        {
            printf("array element at index (%d, %d) address : %p, value : %d\n",i,j,ptr,*ptr);
            ptr++;
        }
    }
}

int main()
{
    int arr[3][3];                  // declaration
    assign_values(arr,3);
    printf("Start location of array                         : %p\n",arr);
    printf("Address returned on evaluating (arr + 1)        : %p\n",arr + 1);
    printf("Address returned on evaluating (&arr[0][0] + 1) : %p\n",&arr[0][0] + 1);
    print_output(&arr[0][0],3,3);

    return 0;
}
/*
Expected output:
Start location of array                         : 0x7ffccf0fe4a0
Address returned on evaluating (arr + 1)        : 0x7ffccf0fe4ac       <----- This points to next row, i.e. offset = col_size
Address returned on evaluating (&arr[0][0] + 1) : 0x7ffccf0fe4a4       <----- This points to 2nd element.
array element at index (0, 0) address : 0x7ffccf0fe4a0, value : 0      <----- 1st row
array element at index (0, 1) address : 0x7ffccf0fe4a4, value : 1
array element at index (0, 2) address : 0x7ffccf0fe4a8, value : 2
array element at index (1, 0) address : 0x7ffccf0fe4ac, value : 10     <----- 2nd row
array element at index (1, 1) address : 0x7ffccf0fe4b0, value : 11
array element at index (1, 2) address : 0x7ffccf0fe4b4, value : 12
array element at index (2, 0) address : 0x7ffccf0fe4b8, value : 20     <----- 3rd row
array element at index (2, 1) address : 0x7ffccf0fe4bc, value : 21
array element at index (2, 2) address : 0x7ffccf0fe4c0, value : 22
*/