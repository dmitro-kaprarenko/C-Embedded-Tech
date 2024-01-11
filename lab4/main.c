#include <stdio.h>
#include <string.h>
#include <windows.h>

// Function to determine if a character is a delimiter
int isDelimiter(char c)
{
    return (c == ',' || c == ';' || c == ':');
}

// Function to compare two strings
int compareStrings(const char *str1, const char *str2)
{
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
    {
        str1++;
        str2++;
    }

    // Return the difference in ASCII values
    return *str1 - *str2;
}

// Function to copy a string
void copyString(char *dest, const char *src)
{
    while ((*dest++ = *src++))
        ;
}

// Function to compare two strings
void swapStrings(char str1[], char str2[])
{
    char temp[50];
    copyString(temp, str1);
    copyString(str1, str2);
    copyString(str2, temp);
}

// Function to sort an array of strings
void sortStrings(char arr[][50], int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (compareStrings(arr[j], arr[j + 1]) > 0)
            {
                swapStrings(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to process a string and output the result
void processString(const char *input)
{
    char entities[50][50]; // Array to store entities
    int entityCount = 0;   // Entity counter

    // Check and remove the newline
    char *newline = strchr(input, '\n');
    if (newline != NULL)
    {
        *newline = '\0';
    }

    // Parse the string and find enumeration constructs
    while (*input != '\0')
    {
        if (*input == ':' && *(input + 1) == ' ')
        {
            input += 2; // Skip ": "
            while (*input != ';' && *input != '\0')
            {
                // Read the entity until a comma or the end of the construct
                int j = 0;
                while (!isDelimiter(*input) && *input != '\0')
                {
                    entities[entityCount][j] = *input;
                    input++;
                    j++;
                }
                // Add the null-terminating character
                entities[entityCount][j] = '\0';
                entityCount++;

                // Skip comma and space if present
                while (*input == ',' || *input == ' ')
                {
                    input++;
                }
            }
        }
        else
        {
            input++;
        }
    }

    // Sort entities
    sortStrings(entities, entityCount);

    // Output sorted entities
    for (int i = 0; i < entityCount; i++)
    {
        printf("%s", entities[i]);

        // Check if it is not the last entity to add a separator
        if (i < entityCount - 1)
        {
            printf(", ");
        }
    }
    printf("\n");
}

int main()
{
    char input[512];

    // Input a sentence
    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);

    // Process and output the result
    processString(input);

    return 0;
}
