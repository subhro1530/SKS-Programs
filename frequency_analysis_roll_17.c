/*
Program 1:
Take an extensive program written by others in C language. Perform the frequency analysis of characters, reserved words.
Problem Statement:
Conducting a comprehensive frequency analysis of characters and reserved words in a given C language program while addressing challenges inherent in comprehending and analyzing externally written code.
Algorithm:
1.	Start the program
2.	Take the file path, whether in the present directory or relative path to the file as input from the user.
3.	Store the reserved words in an array named “reservedwords”
4.	Make another array of the same length ‘wordcount’ to store the number of times a particular reserved word is appearing in the file.
5.	Check whether the file path entered by the user is readable or not by checking if the file pointer points to some value or NULL.
6.	If step 5 is false, print an error message “File not found”
7.	If step 5 is true, run a while loop to read the lines of the file,
8.	Use string function ‘strtok’ to get tokens out of the line using delimeter as ‘\t’,’\n’,’(‘,’)’ and some others
9.	For the frequency of characters, run a for loop from character ‘a’ to ‘z’ and count the number of special characters occurring in the file and print it along with its name.
10.	Compare the tokens of step 8 with the elements of the ‘reservedwords’ array.
11.	If step 10 is true increment the wordcount array at those respective positions.
12.	Print the step 10 results side by side having the character and the count.
13.	Close the file and exit.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256
#define MAX_WORDS 100

// Define reserved words globally
char *reservedWords[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double",
                         "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register",
                         "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef",
                         "union", "unsigned", "void", "volatile", "while", "#include"};

// Function to check if a word is a reserved word
int isReservedWord(char *word)
{
    int numReservedWords = sizeof(reservedWords) / sizeof(reservedWords[0]);

    for (int i = 0; i < numReservedWords; ++i)
    {
        if (strcmp(word, reservedWords[i]) == 0)
        {
            return i; // Return the index of the reserved word
        }
    }

    return -1; // It's not a reserved word
}

int main()
{
    FILE *file;
    char filename[100];
    char c;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file
    file = fopen(filename, "r");

    // Check if the file exists
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    // Initialize variables for frequency analysis
    int reservedWordCount = 0;
    int charFrequency[MAX_CHAR] = {0};
    int reservedWordFrequency[MAX_WORDS] = {0};

    // Read the file character by character
    while ((c = fgetc(file)) != EOF)
    {
        // Update character frequency
        charFrequency[(unsigned char)c]++;

        // Check if the current word is a reserved word
        if (c == ' ' || c == '\n' || c == '\t' || c == '\r')
        {
            // Word boundary reached, reset word buffer
        }
        else
        {
            char word[100];
            int i = 0;
            while (c != ' ' && c != '\n' && c != '\t' && c != '\r' && c != EOF)
            {
                word[i++] = c;
                c = fgetc(file);
            }
            word[i] = '\0';

            // Check if the word is a reserved word
            int reservedIndex = isReservedWord(word);
            if (reservedIndex != -1)
            {
                reservedWordCount++;
                reservedWordFrequency[reservedIndex]++;
            }
        }
    }

    // Close the file
    fclose(file);

    // Print the count of each character
    printf("Character Frequencies:\n");
    for (int i = 0; i < MAX_CHAR; ++i)
    {
        if (charFrequency[i] > 0)
        {
            printf("%c: %d\n", i, charFrequency[i]);
        }
    }

    // Print the count of each reserved word
    printf("\nReserved Word Frequencies:\n");
    for (int i = 0; i < MAX_WORDS; ++i)
    {
        if (reservedWordFrequency[i] > 0)
        {
            printf("%s: %d\n", reservedWords[i], reservedWordFrequency[i]);
        }
    }

    return 0;
}
