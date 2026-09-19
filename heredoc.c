#include "minishell.h"

static int	collect_heredoc(t_token *redir, t_shell *shell)
{
	int	fd;
	int	status;

	fd = heredoc_open(&redir->heredoc_fd);
	if (fd == -1)
	{
		perror("minishell: heredoc");
		return (1);
	}
	status = heredoc_read(redir, shell, fd);
	close(fd);
	return (status);
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