#include "shell.h"
/**
 *  main - function that run the shell tasks
 *  @argc: argument count
 *  @argv: argument vector
 *  @env: environment variable of command
 *
 *  Return: Always (0) on success
 */
int main(int argc, char **argv, char **env)
{
	if (argc == 1)
		ge_prompt(argv, env);
	return (0);
}
