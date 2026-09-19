#include "minishell.h"

static int	name_equal(const char *a, const char *b)
{
	size_t	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (a[i] == b[i]);
}
static int	run_env_builtin(char **argv, t_shell *shell)
{
	if (name_equal(argv[0], "env"))
	{
		if (argv[1])
			return (exec_message("env", "too many arguments", 1));
		return (builtin_env(shell));
	}
	if (name_equal(argv[0], "export"))
		return (builtin_export(argv, shell));
	if (name_equal(argv[0], "unset"))
		return (builtin_unset(argv, shell));
	return (-1);
}

int	run_builtin(t_cmd *command, t_shell *shell)
{
	char	**argv;

	argv = command->argv;
	if (name_equal(argv[0], "echo"))
		return (builtin_echo(argv));
	if (name_equal(argv[0], "pwd"))
		return (builtin_pwd());
	if (name_equal(argv[0], "cd"))
		return (builtin_cd(argv, shell));
	if (name_equal(argv[0], "exit"))
		return (builtin_exit(argv, shell));
	return (run_env_builtin(argv, shell));
}
