#include <stdio.h>
#include <unistd.h>

int main()
{
        int result;
        char *path = "/root/alx-low_level_programming";

        result = chdir(path);
        if (result == -1)
        {
                printf("I can't move to the dir\n");
        }
        else
        {
                printf("Moved successfully\n");
        }
        return 0;
}
