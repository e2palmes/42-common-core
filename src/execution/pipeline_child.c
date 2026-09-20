/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 01:09:21 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/20 01:09:23 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipeline_close(t_pipeline *pipeline)
{
	if (pipeline->input != -1)
		close(pipeline->input);
	if (pipeline->pipefd[0] != -1)
		close(pipeline->pipefd[0]);
	if (pipeline->pipefd[1] != -1)
		close(pipeline->pipefd[1]);
	pipeline->input = -1;
	pipeline->pipefd[0] = -1;
	pipeline->pipefd[1] = -1;
}

static int	connect_pipes(t_pipeline *pipeline)
{
	int	status;

	status = 0;
	if (pipeline->input != -1)
		status = fd_redirect(pipeline->input, 0);
	if (status == 0 && pipeline->pipefd[1] != -1)
		status = fd_redirect(pipeline->pipefd[1], 1);
	pipeline_close(pipeline);
	return (status);
}

int	pipeline_child(t_cmd *command, t_shell *shell, t_pipeline *pipeline)
{
	int	status;

	shell->should_exit = 1;
	signals_child();
	status = connect_pipes(pipeline);
	if (status == 0)
		status = apply_redirections(command->redirs);
	close_heredocs(pipeline->commands);
	if (status != 0)
		return (status);
	if (command->argv[0] == NULL)
		return (0);
	status = run_builtin(command, shell);
	if (status != -1)
		return (status);
	return (exec_external(command, shell));
}
