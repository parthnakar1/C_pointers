# Pointer Basics
The basic concept of pointer is that it is a variable that stores the address of a memory location. Since pointers are closely associated with memory, it is important to know about the 3 types of memory a program deals with when compiled.<br>
1. Static / Global :<br>
Statically declared variables are allocated to this type of memory. Global variables also use this region of memory. They are allocated when the program starts and remain in existence until the program terminates. While all functions have access to global variables, the scope of static variables is restricted to their defining function.<br>
2. Automatic : <br>
These variables are declared within a function and are created when a function is called. Their scope is restricted to the function, and their lifetime is limited to the time the function is executing.<br>
3. Dynamic :<br>
Memory is allocated from the heap and can be released as necessary. A pointer references the allocated memory. The scope is limited to the pointer or pointers that reference the memory. It exists until it is released.<br>
![Variable scope](/Resources/Images/variable_scope.jpg)<br>
*image source: fig 9.1, Practical C Programming (O'Reilly)*
## Pointer Declaration and Assignment :
Pointer declaration is as follows : datatype *var_name; All the following are valid pointer declarations. The whitespaces around asterisk doesn't matter. Pointer variables point to nothing when initialized.They can be assigned later or even during intialization. It is important to make sure that a pointer points to a valid address before dereferencing, otherwise segmentation fault error occurs.
```
int x = 10;
int y = 20;
int * ptr1;         
int* ptr2 = &y;        
int *ptr3;
int*ptr4; 
ptr1 = &x;
```
### Address of Operator (&)
The Address of operator, an unary operator, returns the memory address of the operand. 
```
x = 10;
printf("Value of x = %d stored at location = %p\n",x,&x);
```
The output of above code snippet is :
```
Value of x = 10 stored at location = 0x7ffc3c757860
```

### Dereference Operator (*)
The asterisk (*) , an unary operator, is overloaded in c / c++ programming language. It is called dereference / indirection operator that returns the value stored at the memory address pointed by the pointer. (The pointer stores address of a variable. The value at that address can be accessed by * operator.)
```
ptr1 = &x;
printf("ptr1 points at value = %d, stores (address of variable x) = %p and itself is stored at location = %p\n",*ptr1,ptr1,&ptr1);
```
The output of above code snippet is :
```
ptr1 points at value = 10, stores (address of variable x) = 0x7ffc3c757860 and itself is stored at location = 0x7ffc3c757868
```
### NULL
The concept of NULL is context specific and can at times cause errors if not used properly. When NULL is assigned to a pointer, it means the pointer does not point to anything. The null concept refers to the idea that a pointer can hold a special value that does not point to any area of memory. Two null pointers will always be equal to each other, however they are not equal to any other pointer (which is not assigned NULL). There can be a null pointer type for each pointer type, such as a pointer to a character or a pointer to an integer. The null concept is an abstraction supported by the null pointer constant. This constant may or may not be a constant zero.<br>
The NULL macro is basically a constant integer 0 cast to a void pointer. ASCII NULL is byte containing all bits 0 and is not equal to NULL pointer. A NULL pointer is used for evaluting logical expreesion.
```
int *ptr = NULL;
if(ptr)
{
    printf("pointer is NULL");
}
else
{
    printf("pointer is not NULL");
}
```
The output of above code snippet is :
```
pointer is not NULL
```
### Pointer to void
A pointer to void is general purpose pointer used to hold references of any data type. It has same representation and memory alignment as a pointer to a char. Any pointer can be assigned to a pointer to void and then cast back to its original type<br>
Syntax : ` void *void_ptr;`<br>
*Refer to code [01_Pointer_basics.c](https://github.com/parthnakar1/C_pointers/blob/master/Resources/Codes/01_Pointers_basic.c) in /Resources/Codes/ folder for example code*
## Poniter Sizes :
The size of a pointer variable is constant (4 bytes for 32 bit machines and 8 bytes for 64 bit machines) irrespective of the data type it is pointing to. Although pointer can be declared as unsigned int / long int type (depending on size of primary memory) since addresses can only be positive integers, there are four predefined types available in C when working with pointers. They are as follows :<br>
1. size_t    : to read sizes of variables. (sizeof in general returns long unsigned int)<br>
2. ptrdiff_t : to handle pointer arithmetic<br>
3. intptr_t  : to store pointer addresses<br>
Syntax : `intptr_t *ptr = &var`<br>
4. uintptr_t : to store pointer addresses<br>
Syntax : `uintptr_t *ptr = &var`<br>
The benefit of using intptr_t and uintptr_t is that there is no specific need to declare the data type the pointer is pointing to. However intptr_t is more flexible than uintptr_t as latter requires casting during use.
```
intptr_t *ptr1 = &a1;
printf("\nPointer of type 'intptr_t' points to address  : %p. Value = %c\n",ptr1,*ptr1);
uintptr_t *ptr2 = (uintptr_t *)&a2;
printf("Pointer of type 'uintptr_t' points to address : %p. Value = %d\n",ptr2,*ptr2);
```
The output of above code snippet is:
```
Pointer of type 'intptr_t' points to address  : 0x7ffc86b1d757. Value = c
Pointer of type 'uintptr_t' points to address : 0x7ffc86b1d758. Value = 10
```
*Refer to code [02_Pointer_sizes.c](https://github.com/parthnakar1/C_pointers/blob/master/Resources/Codes/02_Pointer_sizes.c) in /Resources/Codes/ folder for example code*
## Pointers and Constants :
A normal variable declared using keyword **'const'** cannot change the value assigned during initialization throughout its lifetime of the scope. But when used with pointers a different set of combination results in different usages.
### Constant Pointer Variable -
This is a constant pointer that can point to only one address throughout the entire lifetime of its scope. i.e. the address stored in the constant pointer cannot be changed. However the value at that address can be modified through another non constant pointer or variable itself. Such types of constant pointers are used in applications where users can only access specific data for read-only operations but cannot change their values. However those values can be modified by the person maintaining the records.<br>
Syntax : `int *const ptr_const = &a1;`
### Pointer to Constant Variable -
A pointer to constant variable is special type of pointer where the address stored by the pointer can be changed however the value at those addresses cannot be changed. Such pointers can point to non constant variables but still they are considered constant when dereferenced i.e. its value cannot be changed using the pointer.(but can be changed directly by non constant variable or through another pointer). Such pointers can be used to provide user read-only services for efficient memory use since same pointer can be used throughout saving some memory as compared to different pointers for different data fields.<br>
Syntax : `const int *ptr_to_const = &a1;`<br>
| Type | address modifiable | data modifiable by that pointer | data modifiable by variable / other pointer |
| ---- | ------------------ | ------------------------------- | ------------------------------------------- |
| Constant Pointer to a Non Constant Variable |  N  |  N  |  Y  |
| Constant Pointer to a Constant Variable |  N |  N  |  N  |
| Pointer to Constant to a Non Constant variable |  Y  |  N  |  Y  |
| Pointer to Constant to a Constant Variable |  Y  |  N  |  N  |

(*Eventhough the term **constant variable** sounds oxymoronic :sweat_smile: , that's how the terminology is*)<br>
*Refer to code [03_Pointer_and_constants.c](https://github.com/parthnakar1/C_pointers/blob/master/Resources/Codes/03_Pointer_and_constants.c) in /Resources/Codes/ folder for example code*
