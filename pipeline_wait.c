#include "minishell.h"

static void	stop_started(t_cmd *commands)
{
	while (commands)
	{
		if (commands->pid > 0)
			kill(commands->pid, SIGKILL);
		commands = commands->next;
	}
}

int	pipeline_wait(t_cmd *commands, int failed)
{
	int	status;

	if (failed)
		stop_started(commands);
	status = 0;
	while (commands)
	{
		if (commands->pid > 0)
			status = wait_child(commands->pid);
		commands = commands->next;
	}
	if (failed)
		return (1);
	return (status);
}
