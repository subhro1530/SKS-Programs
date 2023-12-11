/*
Program 2:
Take a series of ‘n’ number of characters and generate all permutations 
Problem Statement:
Generate all permutations of a given series of 'n' characters, exploring the entire solution space to produce unique combinations. The problem involves efficiently generating and displaying these permutations, considering the factorial growth in possibilities as 'n' increases and optimizing the algorithm for performance and clarity.

Algorithm:	
1.	Accept the number of characters ‘n’ from the user
2.	Initialize a character array with the number of words entered by the user and take input the string from the user.
3.	Use start as a variable to store the starting point and end to store the ending point
4.	If start is equal to end then return nothing
5.	If step 4 is false, for each index i from start to end swap characters at positions ‘start’ and ‘i’
6.	Go to step 3 while incrementing start and keeping end as it is.
7.	Set the start and end variables to what it was before after recursive call to explore other possibilities.
8.	Print all possible permutations of the entered characters in step 4.
9.	Stop the execution
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Swap characters at positions i and j in the array
void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Check if the character at position 'pos' is already used in the current permutation
int isUsed(char *str, int start, int pos)
{
    for (int i = start; i < pos; ++i)
    {
        if (str[i] == str[pos])
        {
            return 1; // Character is already used
        }
    }
    return 0; // Character is not used
}

// Recursive function to generate permutations without repetition
void generatePermutations(char *str, int start, int end)
{
    if (start == end)
    {
        printf("%s\n", str); // Print the current permutation
    }
    else
    {
        for (int i = start; i <= end; ++i)
        {
            // Check if the character at index 'i' is already used
            if (!isUsed(str, start, i))
            {
                // Swap the current element with the element at index 'i'
                swap(&str[start], &str[i]);
                // Recursively generate permutations for the remaining elements
                generatePermutations(str, start + 1, end);
                // Undo the swap to explore other possibilities
                swap(&str[start], &str[i]);
            }
        }
    }
}

int main()
{
    char input[20];

    // Get input from the user
    printf("Enter a series of characters: ");
    scanf("%s", input);

    int n = strlen(input);

    // Check if input is empty
    if (n == 0)
    {
        printf("No characters entered.\n");
        return 1;
    }

    printf("Permutations without repetition:\n");
    generatePermutations(input, 0, n - 1);

    return 0;
}
