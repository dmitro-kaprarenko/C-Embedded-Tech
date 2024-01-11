#include <stdio.h>

int main()
{
    // Array to store the input string
    char str[100];

    // Read a string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Variable to count non-digit characters
    int nonDigitsCount = 0;

    // Iterate through each character in the string
    for (int i = 0; str[i] != '\0'; i++)
    {
        // Check if the current character is not a digit
        if (str[i] != '\n' && !(str[i] >= '0' && str[i] <= '9'))
        {
            nonDigitsCount++;
        }
    }

    // Print the result
    printf("Number of non-digit characters: %d\n", nonDigitsCount);

    return 0;
}
