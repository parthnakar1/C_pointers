# Pointers and Functions
When working with functions, pointers can be passed as arguments to the function. This allows the function to modify the data referenced by the pointer and pass blocks more efficiently. Passing pointers allows the referenced object to be accessed by multiple functions without being declared global. This also prevents duplication of data which happens otherwise. An other interesting feature of pointers in C is function pointers where pointers point to functions.
## Passing data using Pointer
The memory address of the variable / stored in the pointer is passed as argument and that address is dereferenced using a pointer.
Syntax : 
```
data_type function(data_type *ptr);      // function declaration
...
function(&variable);                     // functional call
``` 
If pointers weren't used then modifying the data would be a tedious task. The argument passed would be copied, then modified and need to be returned. However this isn't feasible when working with large number of data elements.<br>
*Refer to code [06_Swap_values.c](https://github.com/parthnakar1/C_pointers/blob/master/Resources/Codes/06_Swap_values.c) in /Resources/Codes/ folder for example code*
### Passing a Pointer to a Constant
A pointer to constant is used when we want the data to only be read but not modified by a function.<br>
Syntax : `data_type function(const data_type *ptr1, data_type * ptr2);  // function declaration`<br>
Care should be taken of while passing arguments in function call to avoid type mismatch syntax errors.<br>
*Refer to code [07_Constant_pointer_argument.c](https://github.com/parthnakar1/C_pointers/blob/master/Resources/Codes/07_Constant_pointer_argument.c) in /Resources/Codes/ folder for example code*
### Returning a Pointer
The return type is declared a pointer of appropriate data type. The object can be returned in following two ways : <br>
1. Allocate memory within the function using malloc and return its address. The caller is responsible for deallocating the memory returned.<br>
2. Pass an object to the function where it is modified. This makes the allocation and deallocation of the object's memory the caller's responsibility.<br>
Syntax : 
```
data_type * function(arguments)
{
    ...
    return ptr;
}
```
The problems a programmer can face while using functions that returns a pointer are as follows:
1. Returning uninitialized pointer.<br>
2. Returning pointer to invalid address.<br>
3. Returning a pointer that points to local variable / whose scope is less than that of the caller.<br>
4. The allocated memory is not freed (inefficient memory use problem)<br>

*Refer to code [08_Returning_pointer.c](https://github.com/parthnakar1/C_pointers/blob/master/Resources/Codes/08_Returning_pointer.c) in /Resources/Codes/ folder for example code*
### Passing Pointer to a Pointer (multilevel indirection)
When passing the pointer it is possible to change the value pointed by that pointer, however to change the address stored in that pointer, we require to pass pointer to pointer. This is called multilevel indirection of pointers in C. The number of asterisks define the level of indirection.<br>
![Multilevel indirection](/Resources/Images/multilevel_indirection.jpg)<br>
*image source: GeeksforGeeks*<br>
Syntax for 2 level indirection of pointers:
```
data_type * ptr1 = &variable;
data_type ** ptr2 = &ptr1;
```
The pointer passed as an argument to the function is actually copied into stack frame of the function, i.e. the address stored in the pointer is copied and so value can be modified. But when a pointer to a pointer is passed the address of the pointer is copied so that the address stored by the pointer can be modified.<br>
Syntax :
```
data_type function(data_type **ptr,...);    // function declaration
...
function(&vector,...);                      // function call
```
This is largely used in data structures like linked lists, trees, etc.<br>
*Refer to code [09_Multilevel_indirection.c](https://github.com/parthnakar1/C_pointers/blob/master/Resources/Codes/09_Multilevel_indirection.c) in /Resources/Codes/ folder for example code*
## Function Pointers
Function pointers are pointer variables that point to the start address of a function this can then be used to invoke a function in runtime (late binding) rather than at compile time. This gives flexibilty as a programmer can change the code behaviour by simply changing the address the function pointer is pointing to.<br>
Syntax :
```
data_type function(arguments);                          // function to be pointed
return_data_type (*func_ptr)(arguments);                // function pointer declaration
func_ptr = function;                                    // function assignment to function pointer
// func_ptr = &function is also valid
func_ptr(variable);                                     //  function called using function pointer
```
Assume the following code snippet 1 : `add(10,20);`<br>
The assembler output of this function call is somewhat as follows <br>
![Assembly level code for function call add(20,10)](/Resources/Images/assembly_code_1.jpg)<br>
*image source: page no. 116, Pointers in C, A hands on approach*<br>
Now consider code snippet 2 :<br>
```
int (*funcptr)(int x1,int x2);
funcptr = add;
funcptr(10,20);
```
The assembler output of this function call is somewhat as follows<br>
![Assembly level code for function call using function pointer](/Resources/Images/assembly_code_2.jpg)<br>
*image source: page no. 117, Pointers in C, A hands on approach*<br>
Comparing the above two assembly codes, it is evident that using function pointers makes it possible to decide which function to be called during runtime depending on the address the pointer is pointing to. But this comes at an aaded cost of slower execution speed due to late binding.<br>
A programmer should be careful while using function pointers and function returning pointer together.
```
data_type *function(arguments);                      // function to be pointed that returns a pointer
return_data_type *(*func_ptr)(arguments);            // function pointer declaration
func_ptr = function;                                 // function assignment to function pointer
*func_ptr(arguments);                                // function called using function pointer
```
*Refer to code [10_Function_pointers_1.c](https://github.com/parthnakar1/C_pointers/blob/master/Resources/Codes/10_Function_pointers_1.c) in /Resources/Codes/ folder for example code*
### Passing Function Pointer as Arguments
It is not allowed to paas a function to another function as an argument in C. However function pointers can be passed as arguments of a function.<br>
Syntax `data_type function(return_data_type (*func_ptr)(arguments), argumnets)`<br>
A common example is sort() function that can be used for all data types by passing a custom compare function for different data types. Example
```
bool int_compare(int data1, int data2);                               // function declaration
bool float_compare(float data1, float data2);                         // function decalration
...
int sort(bool (*func_ptr)(arguments), void * arr, int size)           // passing function pointer as an argument
// compare is returning int for following assumption : return value < 0 --> x1 smaller than x2
//                                                     return value = 0 --> x1 equal to x2
//                                                     return value > 0 --> x1 greater than x2
```
### Using Array of Function Pointers
An array of function pointerscan be created for functions that have the same return data type and number of input arguments are equal and of same type. Such arrays can be useful for selecting functions based on some criteria (like compare() in sort() based on data type of two input arguments).<br>
Syntax : `return_data_type (*arr[size])(arguments) = {values};`<br>

*Refer to code [11_Function_pointers_2.c](https://github.com/parthnakar1/C_pointers/blob/master/Resources/Codes/11_Function_pointers_2.c) in /Resources/Codes/ folder for example code*