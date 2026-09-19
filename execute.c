/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                 +#+             +#+        */
/*   Created: 2026/09/18 16:55:11 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/18 16:55:11 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	wait_child(pid_t pid)
{
	int	status;

	while (waitpid(pid, &status, 0) == -1)
	{
		if (errno != EINTR)
		{
			perror("minishell: waitpid");
			return (1);
		}
	}
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (1);
}

static int	run_command(t_cmd *command, t_shell *shell)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("minishell: fork");
		return (1);
	}
	if (pid == 0)
	{
		shell->should_exit = 1;
		return (exec_external(command, shell));
	}
	return (wait_child(pid));
}

int	execute_commands(t_cmd *commands, t_shell *shell)
{
	int	status;

	if (commands == NULL)
		return (shell->exit_status);
	if (commands->next || commands->redirs)
		return (exec_message("execution",
				"pipes and redirections not implemented yet", 2));
	if (commands->argv[0] == NULL)
		return (0);
	status = run_builtin(commands, shell);
	if (status != -1)
		return (status);
	return (run_command(commands, shell));
}