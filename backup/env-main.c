#include <stdio.h>

/**
 * main - prints the environment
 * @ac: argument count
 * @av: argument vector
 * @env: environment variables
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;

    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wdeclaration-after-statement"

    unsigned int i = 0;

    #pragma GCC diagnostic pop

    while (env[i] != NULL)
    {
        printf("%s\n", env[i]);
        i++;
    }
    return (0);
}
