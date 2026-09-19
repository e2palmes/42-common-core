#include "minishell.h"

static int	heredoc_equal(const char *a, const char *b)
{
	size_t	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (a[i] == b[i]);
}

static int	heredoc_eof(const char *delimiter)
{
	write_string(2, "minishell: warning: heredoc ended by EOF (wanted `");
	write_string(2, delimiter);
	write_string(2, "')\n");
	return (0);
}

static int	heredoc_write(t_token *redir, t_shell *shell, int fd,
		const char *line)
{
	char	*text;
	int		status;

	if (redir->flags & REDIR_QUOTED)
		text = env_strdup(line);
	else
		text = heredoc_expand(line, shell);
	if (text == NULL)
	{
		perror("minishell: heredoc");
		return (1);
	}
	status = (write_string(fd, text) || write_string(fd, "\n"));
	if (status != 0)
		perror("minishell: heredoc");
	free(text);
	return (status);
}

int	heredoc_read(t_token *redir, t_shell *shell, int fd)
{
	char	*line;
	int		status;

	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			return (heredoc_eof(redir->value));
		if (heredoc_equal(line, redir->value))
		{
			free(line);
			return (0);
		}
		status = heredoc_write(redir, shell, fd, line);
		free(line);
		if (status != 0)
			return (status);
	}
}
