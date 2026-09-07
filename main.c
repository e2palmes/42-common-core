#include "minishell.h"

static void	execute_line(char *line, t_shell *shell)
{
	if (line[0] == 'e' && line[1] == 'n'
		&& line[2] == 'v' && line[3] == '\0')
		shell->exit_status = builtin_env(shell);
}

static void	shell_loop(t_shell *shell)
{
	char	*line;

	while (1)
	{
		line = readline("minishell$ ");
		if (line == NULL)
		{
			printf("exit\n");
			break ;
		}
		if (line[0] != '\0')
		{
			add_history(line);
			execute_line(line, shell);
		}
		free(line);
	}
	rl_clear_history();
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argc;
	(void)argv;
	shell.exit_status = 0;
	shell.env = env_copy(envp);
	if (shell.env == NULL)
	{
		perror("minishell");
		return (1);
	}
	shell_loop(&shell);
	env_free(shell.env);
	return (shell.exit_status);
}
