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

int	wait_child(pid_t pid)
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

int	execute_commands(t_cmd *commands, t_shell *shell)
{
	t_cmd	*current;

	if (commands == NULL)
		return (shell->exit_status);
	current = commands;
	while (current)
	{
		if (has_heredoc(current->redirs))
			return (exec_message("heredoc", "not implemented yet", 2));
		current = current->next;
	}
	if (commands->next == NULL && (commands->argv[0] == NULL
			|| is_builtin(commands->argv[0])))
		return (execute_parent(commands, shell));
	return (execute_pipeline(commands, shell));
}