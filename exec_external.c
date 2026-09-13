#include "minishell.h"

static int	has_slash(const char *str)
{
	while (*str)
	{
		if (*str == '/')
			return (1);
		str++;
	}
	return (0);
}

static int	exec_direct(t_cmd *command, t_shell *shell)
{
	struct stat	info;

	if (stat(command->argv[0], &info) == 0 && S_ISDIR(info.st_mode))
		return (exec_message(command->argv[0], "Is a directory", 126));
	execve(command->argv[0], command->argv, shell->env);
	return (exec_error(command->argv[0], errno));
}

int	exec_external(t_cmd *command, t_shell *shell)
{
	if (command->argv[0][0] == '\0')
		return (exec_message("", "command not found", 127));
	if (has_slash(command->argv[0]))
		return (exec_direct(command, shell));
	return (exec_search(command, shell));
}