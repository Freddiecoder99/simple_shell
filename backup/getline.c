#include <stdio.h>

int main()
{
        ssize_t result;
        char *line = NULL;
        size_t n = 0;

        printf("Enter a line: \n");
        result = getline(&line, &n, stdin);
        if (result == -1)
        {
                printf("ERROR\n");
        }
        else
        {
                printf("%s\n", line);
        }
        return 0;
}
