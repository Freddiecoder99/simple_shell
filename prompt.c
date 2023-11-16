#include "shell.h"
/**
 * ge_prompt - function that print the shell prompt
 * @agv: argument vector
 * @env: environment virables
 *
 * Return: void
 */
void ge_prompt(char **agv, char **env)
{
	char *strg = NULL, *argv[] = {NULL, NULL};
	size_t n = 0;
	int status = 0, j;
	pid_t c_pid;
	ssize_t num_c;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("cisfun$ ");
			fflush(stdout);
		}
		num_c = getline(&strg, &n, stdin);
		if (num_c == -1)
		{
			free(strg);
			exit(EXIT_FAILURE);
		}
		for (j = 0; strg[j]; j++)
		{
			if (strg[j] == '\n')
				strg[j] = 0;
		}
		argv[0] = strg;
		c_pid = fork();
		if (c_pid == -1)
		{
			free(strg);
			exit(EXIT_FAILURE);
		}
		if (c_pid == 0)
		{  
			if (execve(argv[0], agv, env) == -1)
				printf("%s: No such file or directory\n", agv[0]);
			free(strg);
				exit(EXIT_FAILURE);
		}
		else
			wait(&status);
	}
}
