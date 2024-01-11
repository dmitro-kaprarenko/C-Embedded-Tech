#include <stdio.h>

// Function declarations
typedef int (*func_t)(int, int);

int add(int a, int b)
{
    return a + b;
}

int divide(int a, int b)
{
    if (b != 0)
    {
        return a / b;
    }
    else
    {
        printf("Error: Division by zero\n");
        return 0;
    }
}

int multiply(int a, int b)
{
    return a * b;
}

int subtract(int a, int b)
{
    return a - b;
}

// Structure declaration
struct operation_t
{
    char operation;
    func_t func;
};

// Initialization of the structure array
struct operation_t operations[] = {
    {'+', add},
    {'/', divide},
    {'*', multiply},
    {'-', subtract}};

int main()
{
    int a, b;

    // Input operands from the console
    printf("Enter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);

    // Iterating through the array of structures and calling functions
    for (int i = 0; i < sizeof(operations) / sizeof(operations[0]); ++i)
    {
        char operation = operations[i].operation;
        func_t func = operations[i].func;

        int result = func(a, b);

        // Check DivisionByZero
        if (!(operation == '/' && b == 0))
        {
            printf("%d %c %d = %d\n", a, operation, b, result);
        }
    }

    return 0;
}
