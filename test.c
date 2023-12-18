#include <stdio.h>

int main()
{
    int x = 5;

    if (x > 0)
    {
        printf("Positive\n");
    }
    else
    {
        printf("Non-positive\n");
    }

    for (int i = 0; i < 5; ++i)
    {
        printf("Iteration %d\n", i);
    }

    return 0;
}
