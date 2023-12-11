#include <stdio.h>
#include <gmp.h>

void calculate_factorial(int n, mpz_t result)
{
    mpz_set_ui(result, 1); // Initialize result to 1

    for (int i = 1; i <= n; i++)
    {
        mpz_mul_ui(result, result, i); // result *= i
    }
}

int main()
{
    int n = 10;
    mpz_t result;
    mpz_init(result); // Initialize the result variable

    calculate_factorial(n, result);

    // Print the result
    gmp_printf("Factorial of %d is: %Zd\n", n, result);

    // Free the memory used by result
    mpz_clear(result);

    return 0;
}
