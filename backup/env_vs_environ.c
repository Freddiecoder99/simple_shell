#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

        printf("%p\n %p\n", (void *)environ, (void *)env);
        return (0);
}
