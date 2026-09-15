#include "minishell.h"

static int	name_equal(const char *a, const char *b)
{
	size_t	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (a[i] == b[i]);
}

int	run_builtin(t_cmd *command, t_shell *shell)
{
	char	**argv;

	argv = command->argv;
	if (name_equal(argv[0], "echo"))
		return (builtin_echo(argv));
	if (name_equal(argv[0], "pwd"))
		return (builtin_pwd());
	if (name_equal(argv[0], "env"))
	{
		if (argv[1])
			return (exec_message("env", "too many arguments", 1));
		return (builtin_env(shell));
	}
	return (-1);
}