#include "minishell.h"

static int	start_process(t_cmd *command, t_pipeline *pipeline)
{
	pipeline->pipefd[0] = -1;
	pipeline->pipefd[1] = -1;
	if (command->next && pipe(pipeline->pipefd) == -1)
	{
		perror("minishell: pipe");
		return (1);
	}
	command->pid = fork();
	if (command->pid == -1)
	{
		perror("minishell: fork");
		return (1);
	}
	return (0);
}

static void	parent_advance(t_pipeline *pipeline)
{
	if (pipeline->input != -1)
		close(pipeline->input);
	if (pipeline->pipefd[1] != -1)
		close(pipeline->pipefd[1]);
	pipeline->input = pipeline->pipefd[0];
	pipeline->pipefd[0] = -1;
	pipeline->pipefd[1] = -1;
}

int	execute_pipeline(t_cmd *commands, t_shell *shell)
{
	t_pipeline	pipeline;
	t_cmd		*current;

	pipeline.commands = commands;
	pipeline.input = -1;
	pipeline.pipefd[0] = -1;
	pipeline.pipefd[1] = -1;
	current = commands;
	while (current)
	{
		if (start_process(current, &pipeline) != 0)
		{
			pipeline_close(&pipeline);
			return (pipeline_wait(commands, 1));
		}
		if (current->pid == 0)
			return (pipeline_child(current, shell, &pipeline));
		parent_advance(&pipeline);
		current = current->next;
	}
	return (pipeline_wait(commands, 0));
}
