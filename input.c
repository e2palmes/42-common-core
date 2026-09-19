#include "minishell.h"

char	*read_prompt(t_shell *shell)
{
	char	*line;

	signals_prompt();
	line = readline("minishell$ ");
	signals_wait();
	if (g_signal == SIGINT)
		shell->exit_status = 130;
	g_signal = 0;
	return (line);
}

void	signals_finish(t_shell *shell)
{
	if (g_signal == SIGINT)
		write(STDOUT_FILENO, "\n", 1);
	else if (g_signal == SIGQUIT && shell->exit_status == 131)
		write(STDERR_FILENO, "Quit\n", 5);
	g_signal = 0;
}
