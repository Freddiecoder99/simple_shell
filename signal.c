#include <signal.h>
#include <stdio.h>
#include <unistd.h>

/*creation of handler function*/
void signalHandler(int signal)
{
        printf("Received signal is: %d\n", signal);
}

int main()
{
        signal(SIGINT, signalHandler);

        printf("Running ... pres ctrl_z to exit\n");

        while(1)
        {
                sleep(2);
        }
        return 0;
}
