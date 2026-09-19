#include "minishell.h"

static int	exit_invalid(const char *arg, t_shell *shell)
{
	write_string(2, "minishell: exit: ");
	write_string(2, arg);
	write_string(2, ": numeric argument required\n");
	shell->should_exit = 1;
	return (2);
}

int	builtin_exit(char **argv, t_shell *shell)
{
	int	status;

	if (isatty(0) && shell->should_exit == 0)
		write_string(2, "exit\n");
	status = shell->exit_status;
	if (argv[1])
	{
		if (exit_number(argv[1], &status) != 0)
			return (exit_invalid(argv[1], shell));
		if (argv[2])
			return (exec_message("exit", "too many arguments", 1));
	}
	shell->should_exit = 1;
	return (status);
}