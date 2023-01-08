#include<stdio.h>

int main()
{
    // pointer addition
    int x1 = 4223;
    int *int_ptr = &x1;
    char *char_ptr = &x1;                  // this line gives compile time warning : incompatiple pointer type, but can still be executed
    printf("int_ptr address : %p, value : %d\n",int_ptr,*int_ptr);
    printf("Printing data stored at each byte in the memory\n");
    for(int i = 0; i < sizeof(int);i++)
    {
        printf("Mem address : %p, value : %d\n",char_ptr,*char_ptr);
        char_ptr++;
    }
    // pointer subtraction 
    int arr[5] = {1,2,3,4,5};
    int *ptr = &arr[4];
    printf("Array in reverse order\n");
    for(int i = 0; i < 5;i++)
    {
        printf("Mem address : %p, value : %d\n",ptr,*ptr);
        ptr--;
    }
    // comparing two pointers
    if(ptr == int_ptr)
    {
        printf("ptr and int_ptr point to same location\n");
    }
    else
    {
        printf("ptr and int_ptr point to different locations\n");
    }

    return 0;
}
/*
Expected output:
int_ptr address : 0x7ffda0e8301c, value : 4223
Printing data stored at each byte in the memory
Mem address : 0x7ffda0e8301c, value : 127
Mem address : 0x7ffda0e8301d, value : 16
Mem address : 0x7ffda0e8301e, value : 0
Mem address : 0x7ffda0e8301f, value : 0
Array in reverse order
Mem address : 0x7ffda0e83054, value : 5
Mem address : 0x7ffda0e83050, value : 4
Mem address : 0x7ffda0e8304c, value : 3
Mem address : 0x7ffda0e83048, value : 2
Mem address : 0x7ffda0e83044, value : 1
ptr and int_ptr point to different locations
*/