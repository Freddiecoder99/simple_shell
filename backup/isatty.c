#include <unistd.h>
#include <stdio.h>

int main()
{
        if (isatty(STDOUT_FILENO))
        {
                printf("connected\n");
        }
        else
        {
                printf("Not connected\n");
        }
        return 0;
}
