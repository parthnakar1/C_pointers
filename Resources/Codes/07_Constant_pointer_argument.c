#include<stdio.h>

void func1(const int *ptr_const, int * ptr)
{
    // *ptr_const = 10;     invalid, gives compilation error upon exection
    *ptr += 10;
}

int main()

{
    int data = 0;
    const int data_const = 1;

    printf("data = %d,data_const = %d \n",data,data_const);
    printf("Executing func1(&data, &data_const)\n");
    func1(&data_const, &data);
    printf("data = %d,data_const = %d \n",data,data_const);
    printf("Executing func1(&data, &data)\n");
    func1(&data, &data);
    printf("data = %d,data_const = %d \n",data,data_const);
    printf("Executing func1(&data_const, &data_const)\n");
    func1(&data_const, &data_const);                        // this line will give a warning but can still be executed
    printf("data = %d,data_const = %d \n",data,data_const);

    return 0;
}
/*
Expected output:
data = 0,data_const = 1 
Executing func1(&data, &data_const)
data = 10,data_const = 1 
Executing func1(&data, &data_const)
data = 20,data_const = 1 
Executing func1(&data_const, &data_const)
data = 20,data_const = 11
*/
// The const defined for data_const is applicaple only in its scope. When its addressed is passed, the compiler gives a warning
// but it can still be executed.