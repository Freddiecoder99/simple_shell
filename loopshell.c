#include "shell.h"
/**
 * scell - main shell function
 * @info: struct parameter
 * @av: argument vector
 *
 * Return: Always (0) on success, (1) on error, or error code
 */
int scell(info_t *info, char **av)
{
	int builtin_ret = 0;
	ssize_t r = 0;

	do {
		initiate_info(info);

		if (interactive(info))
		{
			_myputs("$ ");
			_eputchar(BUF_FLUSH);
		}
		r = get_input(info);
		if (r != -1)
		{
			set_info(info, av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_myputchar('\n');
		free_fields(info, 0);
	} while (r != -1 && builtin_ret != -2);
	write_history(info);
	free_fields(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}
/**
 * find_builtin - finds a builtin command
 * @info: the parameter & return info struct
 *
 * Return: -1 if builtin not found,
 * 0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int find_builtin(info_t *info)
{
	int i = 0;
	int builtin_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", ge_myexit},
		{"env", ge_environ},
		{"help", ge_myhelp},
		{"setenv", ge_psetenv},
		{"unsetenv", ge_punsetenv},
		{"history", ge_history},
		{"cd", ge_mycd},
		{"alias", ge_alias},
		{NULL, NULL}
	};

	while (builtintbl[i].type != NULL)
	{
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			builtin_ret = builtintbl[i].func(info);
			break;
		}
		i++;
	}
	return (builtin_ret);
}

/**
 * find_cmd - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!is_delim(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = ge_getpath(info, ge_getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || ge_getenv(info, "PATH=")
					|| info->argv[0][0] == '/') && ge_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_errors(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - forks a an exec thread to run cmd
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_fields(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_errors(info, "Permission denied\n");
		}
	}
}

