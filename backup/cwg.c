#include <unistd.h>
#include <stdio.h>

int main()
{
        char *result;
        char buff[100];
        size_t size;

        size = sizeof(buff);

        result = getcwd(buff, size);
        if (result == NULL)
        {
                perror("ERROR");
        }
        else
        {
                printf("Current working directory is: %s\n", buff);
        }
        return 0;
}
