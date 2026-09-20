/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 01:36:23 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/20 01:36:27 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_heredoc(t_token *redirs)
{
	while (redirs)
	{
		if (redirs->type == TOKEN_HEREDOC)
			return (1);
		redirs = redirs->next;
	}
	return (0);
}

static int	open_redirection(t_token *redir)
{
	if (redir->type == TOKEN_HEREDOC)
		return (dup(redir->heredoc_fd));
	if (redir->type == TOKEN_IN)
		return (open(redir->value, O_RDONLY));
	if (redir->type == TOKEN_OUT)
		return (open(redir->value, O_WRONLY | O_CREAT | O_TRUNC, 0666));
	return (open(redir->value, O_WRONLY | O_CREAT | O_APPEND, 0666));
}

static int	apply_one(t_token *redir)
{
	int	fd;
	int	target;
	int	status;

	if (redir->flags & REDIR_AMBIGUOUS)
		return (exec_message(redir->value, "ambiguous redirect", 1));
	fd = open_redirection(redir);
	if (fd == -1)
		return (exec_message(redir->value, strerror(errno), 1));
	target = 1;
	if (redir->type == TOKEN_IN || redir->type == TOKEN_HEREDOC)
		target = 0;
	status = fd_redirect(fd, target);
	if (fd != target)
		close(fd);
	return (status);
}

int	apply_redirections(t_token *redirs)
{
	while (redirs)
	{
		if (apply_one(redirs) != 0)
			return (1);
		redirs = redirs->next;
	}
	return (0);
}
