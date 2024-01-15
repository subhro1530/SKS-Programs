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
    int s = 0;
    for (int i = 0; i < 5555555000; ++i)  
    {
        s = s + i;
        printf("Iteration %d\n", i);
    }

    

    return 0;
}
