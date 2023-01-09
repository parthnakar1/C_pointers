#include<stdio.h>
#include<string.h>

int main()
{
    char arr1[] = "STRING1";
    char arr2[8];
    arr2[0] = 'S';
    arr2[1] = 'T';
    arr2[2] = 'R';
    arr2[3] = 'I';
    arr2[4] = 'N';
    arr2[5] = 'G';
    arr2[6] = '2';
    arr2[7] = '\0';
    char arr3[10];
    printf("Enter a string : ");
    scanf("%s",arr3);
    printf("Array 1 : %s\n",arr1);
    printf("Array 2 : %s\n",arr2);
    printf("Array 3 : %s\n",arr3);
    printf("The length of the string is : %lu\n",strlen(arr3));
    printf("strcmp(arr1, arr2) : %d\n",strcmp(arr1,arr2));
    char arr4[15];
    strcpy(arr4,arr1);
    strcat(arr4,arr2);
    printf("Array 4 : %s\n",arr4);

    return 0;
}
/*
Expected output:
Enter a string : STRING3
Array 1 : STRING1
Array 2 : STRING2
Array 3 : STRING3
The length of the string is : 7
strcmp(arr1, arr2) : -1
Array 4 : STRING1STRING2
*/