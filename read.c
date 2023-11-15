#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
        int fd;
        char *path = "example.txt";
        ssize_t result;
        size_t count;
        char *buff;

        fd = open(path, O_RDONLY);
        if (fd == -1)
        {
                printf("ERROR");
        }
        else
        {
                count = 100;
                buff = malloc(count);
                result = read(fd, buff, count);
                if (result == -1)
                {
                        printf("I can't read\n");
                }
                else
                {
                        printf("I can read successfully and the content is %s\n", buff);
                }
        }
        close(fd);
	return 0;
}
