#include<stdio.h>

void assign_values(int *ptr, int size)              // passing array in pointer notation
{
    for(int i = 0; i < size; i++)
    {
        *ptr = i*10;                    
        ptr++;
    }
}

void print_output(int arr[], int size)              // passing array in array notaion
{
    for(int i = 0;i < 5; i++)
    {
        printf("arr index %d address: %p, value : %d\n",i,&arr[i],arr[i]);
    }
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    printf("Start location of arr : %p\n",arr);
    int *ptr = &arr[0];
    assign_values(ptr,sizeof(arr)/sizeof(int));
    print_output(arr,sizeof(arr)/sizeof(int));

    return 0;
}
/*
Expected output:
Start location of arr : 0x7ffedab30460
arr index 0 address: 0x7ffedab30460, value : 0
arr index 1 address: 0x7ffedab30464, value : 10
arr index 2 address: 0x7ffedab30468, value : 20
arr index 3 address: 0x7ffedab3046c, value : 30
arr index 4 address: 0x7ffedab30470, value : 40
*/