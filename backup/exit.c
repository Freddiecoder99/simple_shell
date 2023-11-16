#include <stdlib.h>
#include <stdio.h>

int main()
{
        int x = 5;

        if (x > 0)
        {
                printf("program executed\n");
                exit(0);
        }
        else
        {
                printf("Error");
                exit(1);
        }
}
