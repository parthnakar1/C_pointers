# Pointers and Strings
A string by definition is a sequence of characters. It is stored as an array of bytes. A special string terminating character (NUL / escape character : '\0') is used to mark the end of a string. Strings are commonly stored in arrays or in memory allocated from the heap. However, a character array not containing the NUL character is not a string. When strings are defined, the compiler automatically concatenates an escape sequence of '\0' at the end of the string. There exist two types of strings in C :<br>
**1. byte string :** consisting of a sequence of char data type. The supporting functions are declared in *string.h* .<br>
**2. wide string :** consisting of a sequence of wchar_t data type. They are 16 or 32 bits in size and used for having multiple langauage symbols. The supporting functions are declared in *wchar.h* .<br>
The string length is the number of characters, terminating character although occupies space is excluded.<br>
## String Declaration and Initialization
String declaration is possible in three ways :<br>
**1. As a Literal :**<br>
The string literal is a sequence of characters enclosed in double quotes. They are used for initialization and are stored in separate Read-Only section in the memory also called as *literal pool*.<br>
Syntax : `char *str = "STRING";`<br>
The lifespan of data stored in these section is the complete lifetime of a program being executed. When a literal is used more than once, the compiler normally makes a single copy of that literal to increase space efficiency. Some compilers treat a string literal as a constant and so modification of its charater is not permitted.<br>
**2. As an Array of characters :**<br>
When an array of characters is used, the memory is allocated and start address is returned by array_name. The array can be initialized using a string literal or by initialization of characters at each memory location. Another way is to use strcp() function and copy a string literal into the character array.<br>
Syntax :
```
char str_arr1[] = "STRING";          // using a string literal

char str_arr2[7];                    // one extra location is required to store escape character
str_arr2[0] = 'S';
str_arr2[1] = 'T';
...
str_arr2[2] = '\0';

str_arr3[7];
strcpy(str_arr3,"STRING");           // using strcpy function
```
**3. A Pointer to char :**<br>
A dynamically allocated memory location is pointed using a pointer to char. The string can be initialized in same way as an array with help of a pointer.<br>
Syntax : 
```
char *str_arr = (char *) malloc(7 * sizeof(char));
strcpy(str_arr, "STRING");
```
## Standard String Operations
### Handling string inputs
Strings can also be initialized from user inputs during runtime. To handle this, we need to first allocate sufficient memory for that string to be stored. The *%s* format is used in the scanf() function to store a string variable.
Syntax :
```
char str_arr[10];               // declaration that allocates memory
printf("Enter string\n");
scanf("%s",str_arr);            // reading from user input
```
The following functions that are commonly used are part of *string.h*<br>
#### strlen()
input argument : pointer to the start of the string<br>
return value   : length of the string
This function excludes '\0' when counting the length of the string.
#### strcmp()
input argument : 2 pointers to the start of the strings to be compared<br>
return value   : integer
if returned value is<br>
negative -> 1<sup>st</sup> precedes 2<sup>nd</sup> lexicographically.<br>
zero -> both strings are equal<br>
positive -> 2<sup>nd</sup> precedes 1<sup>st</sup> lexicographically.<br>
#### strcpy()
input argument : pointer to destination string and pointer to source string.<br>
return value   : pointer to copied string.<br>
#### strcat()
input argument : 2 pointers to the start of the strings to be concatenated.<br>
return value   : pointer to concatenated string.
The 2<sup>nd</sup> string is concatenated at the end of the 2<sup>nd</sup> string.<br>
