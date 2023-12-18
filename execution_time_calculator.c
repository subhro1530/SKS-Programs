#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void measureExecutionTime(const char *programPath)
{
    // Record the starting time
    clock_t start_time = clock();

    // Run the specified program
    int result = system(programPath);

    // Record the ending time
    clock_t end_time = clock();

    // Check if the specified program ran successfully
    if (result == 0)
    {
        // Calculate the execution time in seconds
        double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        // Print the execution time
        printf("Execution Time for %s: %f seconds\n", programPath, execution_time);
    }
    else
    {
        printf("Error running %s\n", programPath);
    }
}

int main()
{
    // Get the program path from the user
    char programPath[100];
    printf("Enter the program path to measure execution time: ");
    scanf("%s", programPath);

    // Measure the execution time of the specified program
    measureExecutionTime(programPath);

    return 0;
}
