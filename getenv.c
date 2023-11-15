#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *homevalue = getenv("HOME");


    if (homevalue != NULL)
    {
        printf("%s\n", homevalue);
    }
    else
    {
        printf("HOME environment variable not found.\n");
    }
    return 0;
}
