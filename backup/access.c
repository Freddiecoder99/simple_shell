#include <stdio.h>
#include <unistd.h>

int main()
{
        int result;
        char *pathname = "example.txt";

        result = access(pathname, R_OK);
        if (result == -1)
        {
                printf("can't access the file\n");
        }
        else
        {
                printf("I can access the file and the content is %s\n", pathname);
        }
        return 0;
}
