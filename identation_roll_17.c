#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

void indentCode(FILE *inputFile, FILE *outputFile, int indentationLevel)
{
    char line[MAX_LINE_LENGTH];
    int currentIndentation = 0;

    while (fgets(line, sizeof(line), inputFile) != NULL)
    {
        // Trim leading and trailing whitespaces
        char *start = line;
        while (*start == ' ' || *start == '\t')
        {
            start++;
        }

        char *end = start + strlen(start) - 1;
        while (end > start && (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r'))
        {
            end--;
        }
        *(end + 1) = '\0';
        
        // Handle opening and closing braces to adjust indentation
        for (int i = 0; i < strlen(start); i++)
        {
            if (start[i] == '{')
            {
                currentIndentation += indentationLevel;
            }
            else if (start[i] == '}')
            {
                currentIndentation -= indentationLevel;
            }
        }

        // Print the indented line
        for (int i = 0; i < currentIndentation; i++)
        {
            fputc(' ', outputFile);
        }
        fputs(start, outputFile);
        fputc('\n', outputFile);
    }
}

int main()
{
    char inputFileName[MAX_LINE_LENGTH];
    char outputFileName[MAX_LINE_LENGTH];
    int indentationLevel;

    // Get input file name
    printf("Enter the input C file name: ");
    scanf("%s", inputFileName);

    // Get output file name
    printf("Enter the output C file name: ");
    scanf("%s", outputFileName);

    // Get indentation level
    printf("Enter the desired indentation level: ");
    scanf("%d", &indentationLevel);

    // Open input file
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL)
    {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    // Open output file
    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL)
    {
        perror("Error opening output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    // Perform indentation
    indentCode(inputFile, outputFile, indentationLevel);

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    printf("Code indentation completed successfully.\n");

    return EXIT_SUCCESS;
}
