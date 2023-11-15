#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *_getenv(const char *name)
{
        extern char **environ;
        int i;
        char *token;

        i = 0;
        while (environ[i])
        {
                token = strtok(environ[i], "=");
                if (strcmp(token, name) == 0)
                {
                        return strtok(NULL, "=");
                }
                i++;
        }
        return NULL;

}

int main(void)
{
    char *homevalue = _getenv("HOME");

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

