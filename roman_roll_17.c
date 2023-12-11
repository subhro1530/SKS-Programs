/*
Program 3:
Take a 10 digit number and convert it to equivalent ROMAN representation
Problem Statement:
Convert a given 10-digit number into its equivalent Roman numeral representation. Develop an algorithm to handle the decimal number's conversion, considering the Roman numeral system's rules. Ensure accuracy in the transformation process, accounting for various digit positions and adhering to the conventions of Roman numeral notation.
Algorithm:
1.	Accept the 10 digit number from the user
2.	Check if the number entered by the user is greater than 1 and less than 9999999999
3.	If step 2 is false print “Out of range” and exit from the program
4.	If step 2 is true go to step 5.
5.	Create two arrays, romanNumerals and values, to store the Roman numeral symbols and their corresponding values.
6.	Loop through the values array from the highest value to the smallest.
7.	Inside the loop, check if the input number is greater than or equal to the current value.
8.	If step 7 is true, subtract the value from the input number and print the corresponding Roman numeral.
9.	Go to step 6 till input number becomes 0
10.	Exit from the program.
*/

#include <stdio.h>
#include <string.h>

// Function to convert a digit to Roman numeral representation
void digitToRoman(int digit, char one, char five, char ten, char result[])
{
    switch (digit)
    {
    case 1:
    case 2:
    case 3:
        for (int i = 0; i < digit; ++i)
        {
            strcat(result, &one);
        }
        break;
    case 4:
        strcat(result, &one);
        strcat(result, &five);
        break;
    case 5:
    case 6:
    case 7:
    case 8:
        strcat(result, &five);
        for (int i = 0; i < digit - 5; ++i)
        {
            strcat(result, &one);
        }
        break;
    case 9:
        strcat(result, &one);
        strcat(result, &ten);
        break;
    }
}

// Function to convert a 10-digit number to Roman numeral
void convertToRoman(long long int number, char result[])
{
    const char romanThousands[] = "M";
    const char romanHundreds[] = "CDM";
    const char romanTens[] = "XLC";
    const char romanOnes[] = "IVX";

    result[0] = '\0';

    // Convert billions digit
    int billions = number / 1000000000;
    if (billions > 0)
    {
        digitToRoman(billions, romanThousands[0], romanThousands[0], romanThousands[0], result);
    }
    number %= 1000000000;

    // Convert millions digit
    int millions = number / 1000000;
    if (millions > 0)
    {
        digitToRoman(millions, romanHundreds[0], romanHundreds[1], romanHundreds[2], result);
    }
    number %= 1000000;

    // Convert thousands digit
    int thousands = number / 1000;
    if (thousands > 0)
    {
        digitToRoman(thousands, romanTens[0], romanTens[1], romanTens[2], result);
    }
    number %= 1000;

    // Convert ones digit
    digitToRoman(number, romanOnes[0], romanOnes[1], romanOnes[2], result);
}

int main()
{
    long long int number;

    // Get the 10-digit number from the user
    printf("Enter a 10-digit number: ");
    scanf("%lld", &number);

    // Check if the number is a 10-digit number
    if (number < 1000000000LL || number > 9999999999LL)
    {
        printf("Invalid input. Please enter a 10-digit number.\n");
        return 1;
    }

    // Convert the number to Roman numeral representation
    char romanNumeral[50]; // Assuming the result won't exceed 50 characters
    romanNumeral[0] = '\0';
    convertToRoman(number, romanNumeral);

    // Display the Roman numeral representation
    printf("Roman Numeral: %s\n", romanNumeral);

    return 0;
}
