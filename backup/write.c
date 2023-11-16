#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

int main ()
{
        int fd;
        char *buff = "Hello world from c";
        size_t count = strlen(buff);
        ssize_t bytes_written;

        fd = open("exa.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1)
        {
                perror("cant open");

                return 1;
        }

        bytes_written = write(fd, buff, count);
        if (bytes_written == -1)
        {
                perror("can't write");
                close(fd);
                return 1;
        }

        printf("Bytes written: %ld\n", bytes_written);

        close(fd);
        return 0;
}
