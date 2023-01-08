#include<stdio.h>
#include<stdlib.h>

int * insert_data(int *arr, int *ptr_size, int data)
{
    (*ptr_size)++;                                          // increment value of array size
    int *ptr;                                               // initialize a pointer
    ptr = (int *) realloc(arr,(*ptr_size)*sizeof(int));     // realloc memory
    *(ptr + (*ptr_size) - 1) = data;                        // store data at last memory location
    
    return ptr;                                             // return the start address of the pointer
}

void print_array(int *ptr,int *ptr_size)
{
    if(ptr != NULL)                                         // print only if ptr points to valid memory location
    {
        for(int i = 0; i < *ptr_size; i++)
        {
            printf("Array element at index %d address: %p, value : %d\n",i,(ptr+i),*(ptr+i));
        }
    }
}

int main()
{
    int *arr = NULL;                            // Initialize a pointer to NUL
    int size = 0;                               // Variable storing the size of the array
    int *ptr_size = &size;                      // Pointer pointing to size variable
    int option;                                 // Variable to store selected option
    int data;                                   // Variable to store data to be inserted
    printf("Option 1. Insert new data\nOption 2. Show Array\nOption 3. Quit\n");
    do
    {
        printf("Enter the option number: ");
        scanf("%d",&option);
        if(option == 1)                         // insert option
        {
            printf("Enter data : ");
            scanf("%d",&data);
            arr = insert_data(arr,ptr_size,data);
        }
        else if(option == 2)                    // print option
        {
            print_array(arr,ptr_size);
        }
    }
    while(option != 3);
    free(arr);                                  // freeing dynamically allocated memory.

    return 0;
}
/*
Expected output:
Option 1. Insert new data
Option 2. Show Array
Option 3. Quit
Enter the option number: 2
Enter the option number: 1
Enter data : 1
Enter the option number: 2
Array element at index 0 address: 0x55fd14f38ac0, value : 1
Enter the option number: 1
Enter data : 2
Enter the option number: 1
Enter data : 3
Enter the option number: 1
Enter data : 4 
Enter the option number: 2
Array element at index 0 address: 0x55fd14f38ac0, value : 1
Array element at index 1 address: 0x55fd14f38ac4, value : 2
Array element at index 2 address: 0x55fd14f38ac8, value : 3
Array element at index 3 address: 0x55fd14f38acc, value : 4
Enter the option number: 3
*/