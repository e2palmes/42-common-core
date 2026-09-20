/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 01:06:20 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/20 01:06:22 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	heredoc_child(t_token *redir, t_shell *shell, int fd)
{
	int	status;

	shell->should_exit = 1;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	status = heredoc_read(redir, shell, fd);
	close(fd);
	return (status);
}

static int	collect_heredoc(t_token *redir, t_shell *shell)
{
	int		fd;
	pid_t	pid;

	fd = heredoc_open(&redir->heredoc_fd);
	if (fd == -1)
	{
		perror("minishell: heredoc");
		return (1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("minishell: fork");
		close(fd);
		return (1);
	}
	if (pid == 0)
		return (heredoc_child(redir, shell, fd));
	close(fd);
	return (wait_child(pid));
}

int	prepare_heredocs(t_cmd *commands, t_shell *shell)
{
	t_token	*redir;
	int		status;

	while (commands)
	{
		redir = commands->redirs;
		while (redir)
		{
			if (redir->type == TOKEN_HEREDOC)
			{
				status = collect_heredoc(redir, shell);
				if (status != 0 || shell->should_exit)
					return (status);
			}
			redir = redir->next;
		}
		commands = commands->next;
	}
	return (0);
}

void	close_heredocs(t_cmd *commands)
{
	t_token	*redir;

	while (commands)
	{
		redir = commands->redirs;
		while (redir)
		{
			if (redir->heredoc_fd != -1)
			{
				close(redir->heredoc_fd);
				redir->heredoc_fd = -1;
			}
			redir = redir->next;
		}
		commands = commands->next;
	}
}
