#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
        pid_t pid = getpid();
        int result;

        printf("MY PID is: %d\n", pid);
        printf("sending SIGTERM to myself....\n");

        result = kill(pid, SIGTERM);
        if (result == 0)
        {
                printf("Signal sent successfully\n");
        }
        else
        {
                perror("ERROR");
                exit(EXIT_FAILURE);
        }
        return 0;
}
