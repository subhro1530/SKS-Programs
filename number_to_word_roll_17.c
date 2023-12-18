#include <stdio.h>

// Function to convert a number to words
void convertLessThanThousand(long long int number)
{
    char *units[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    char *teens[] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    char *tens[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    if (number / 100)
    {
        printf("%s Hundred", units[number / 100]);
        number %= 100;

        if (number != 0)
        {
            printf(" and ");
        }
    }

    if (number / 10)
    {
        if (number / 10 == 1 && number % 10)
        {
            printf("%s", teens[number % 10]);
            return;
        }
        else
        {
            printf("%s", tens[number / 10]);
            number %= 10;

            if (number != 0)
            {
                printf(" ");
            }
        }
    }

    if (number % 10)
    {
        printf("%s", units[number % 10]);
    }
}

// Function to convert a number to words
void convertNumberToWords(long long int number)
{
    if (number == 0)
    {
        printf("Zero\n");
        return;
    }

    char *thousands[] = {"", "Thousand", "Lakh", "Crore"};

    int count = 0;
    while (number > 0)
    {
        if (number % 1000 != 0 || (count == 0 && number < 1000))
        {
            if (count > 0)
                printf(" ");
            convertLessThanThousand(number % 1000);
            if (number % 1000 != 0)
            {
                printf(" %s", thousands[count]);
            }
        }
        number /= 1000;
        count++;
    }
}

// Main function
int main()
{
    long long int number;

    // Example number
    printf("Enter a number: ");
    scanf("%lld", &number);

    if (number < 0)
    {
        printf("Please enter a non-negative number.\n");
        return 1;
    }

    convertNumberToWords(number);
    printf("\n");

    return 0;
}
