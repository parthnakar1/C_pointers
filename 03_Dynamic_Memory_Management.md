# Dynamic Memory Management in C
Pointers have the ability to track dynamically allocated memory. The management of this memory through pointers forms an important part of operation. A C program being executed, during its runtime has stack and heap along with other structures provided by the OS. Dynamic allocation and deallocation helps in efficient use of memory. (eg. when fixed size arrays are created for storing data items whose total number is not known, we tend up using extra space than required by creating sufficiently large array). The process of dynamic memory management is done manually using *malloc(), realloc(), calloc()* and *free()* functions.
| Function | Description |
| -------- | ----------- |
| malloc() | Allocates memory from heap |
| calloc() | Allocates and zeros memory from heap |
| realloc() | Reallocates memory of large / small size |
| free() | returns block to heap |
### 1. malloc():
Syntax : `data_type *ptr = (data_type *) malloc(size);`<br>
**NOTE :** The type casting before malloc() (data_type *) is optional and helps in better readability. If pointer is intialized first then dereference operator shouldn't  be used.
```
int *ptr;
// *ptr = (int *) malloc(sizeof(int)); is incorrect way
ptr = (int *) malloc()(sizeof(int));
if (ptr != NULL)
{
    // memory allocated, proceed further
}
else
{
    // memory not available
}
```
The malloc() function takes a single argument that specifies *number of bytes* to be allocated from the heap. If space is available, it returns a pointer to the start address of the allocated memory else a NULL pointer. The function doesn't clear the memory before allocating so any data present should be considered as garbage. Using sizeof() function while passing size argument makes the code portable. When memory is allocated, additional information is stored by heap manager which includes size of block, type of data, etc and placed adjacent to allocated block. If an application writes data outside the allocated block this information gets corrupted. It is optional to check whether malloc() returns NULL or not, however advisable when working with small memory devices.
#### Using malloc() with staic and global pointers
A function call cannot initialize a static or global variable. (Refer [memory layout](/Resources/Images/memory_layout.jpg))<br>
`static int *ptr = malloc(sizeof(int));` generates compilation error<br>
`int *ptr = (int *) malloc(sizeof(int));` declared global also generates error.<br>
However this can be overcomed through global / static decalartion first and assignment later.
### 2. calloc():
Syntax : `data_type *ptr = (data_type *) calloc(number_of_elements, sizeof(data_type));`<br>
This function allocates memory determined by number_of_elements * sizeof(data_type) in bytes. The pointer to start of the block is returned if memory space available in heap or NULL is returned. All the values in the block are set to 0 value.<br>
An alternative to calloc() is as follows:
```
data_type *ptr = (data_type *) malloc(number_of_elements * sizeof(data_type));
memset(ptr,0,number_of_elements * sizeof(data_type));
```
memset() Syntax : `memset(start_address, value, block_size_in_bytes);`<br>
memset() provides flexibility in setting the values other than 0.
### 3. realloc():
Syntax : `data_type *ptr = (data_type *) realloc(ptr_original, new_size);` (new_size is in bytes)<br>
This function reallocates memory when a previously assigned memory block size is to be changed. The first argument is pointer to start address of original block while second argument is new size in bytes. The return value is pointer to new block if memory space is available, otherwise old block is retained, errno is set to ENOMEM and NULL pointer is returned. When new_size is larger than current size, first it is checked if immediately following memory space can be assigned. If that is not possible then all elements are copied to new location with larger block size. For the smaller new_size case, there is no guarantee that excess memory will be cleared.<br>
If the 1<sup>st</sup> argument is null the realloc() functions same as malloc(). If the 2<sup>nd</sup> argument is 0 then the original block is freed. (somewhat similar to free())
### 4. free():
Syntax : `free(ptr);`<br>
The argument passed to free() is the start address(stored in pointer) returned by the malloc() / calloc() / realloc(). The heap manager then frees that space and it is available to be allocated to other requests if any. The pointer may still point to that location but data there is to be considered as garbage.<br>
It is advisable to assign NULL to freed pointers to avoid problems of pointing to garbage data.<br>
*NOTE :* The problem of double free due to aliases explained in dangling pointers.<br>
*Refer to code [04_Dynamic_memory_functions_1.c](https://github.com/parthnakar1/C_pointers/blob/master/Resources/Codes/04_Dynamic_memory_functions_1.c) and [05_Dynamic_memory_functions_2.c](https://github.com/parthnakar1/C_pointers/blob/master/Resources/Codes/05_Dynamic_memory_functions_2.c) in /Resources/Codes/ folder for example code*
## Memory Leaks
The memory leak refers to phenomenon where allocated memory is never used again but not freed. Such occurences uses space thus reducing available memory in the heap. This can happen due to two reasons:<br>
**1. Memory address is lost :** This occurs when a pointer storing the address of dynamic memory is assigned a new address or pointer storing start address of the block is further used to access next element of that block. (common mistake when handling dynamic arrays / linked lists / queues / trees / etc)<br>
example for case 1:<br>
```
int *ptr = (int *) malloc(sizeof(int));
*ptr = 10;
...
ptr = (int *) malloc(sizeof(int));
```
example for case 2:
```
int *ptr = (int *) malloc(5*sizeof(int));
for(int i = 0; i < 5; i++)
{
    printf("%d element : %d", i, *ptr);
    ptr++;
}
```
**2. Hidden Memory Leaks :** This occurs when the user doesn't release the memory that is no longer needed. The free() is not called thinking this data may be required somewhere else and reaches at point where heap is full.(Heaps can grow / shrink in size based on requirements / other factors controlled by the OS.)
## Dangling Pointers
If the pointer still points to old memory address in the heap after it has been freed it is called the dangling pointer. Using the dangling pointer may result in some unpredictable behaviour, segmentation fault or pose some security risk. This problem also arises when aliases of a pointer exist(two or more pointers pointing to same location), one of the pointer is freed and then its alias is used. Such conditions give rise to double free error at runtime. It may also happen that scope of pointer storing the address is different and once the function / block execution is complete, that pointer becomes a dangling pointer.<br>
No standard general solution to this problem exist. It has to be application specific.