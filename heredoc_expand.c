#include "minishell.h"

static int	heredoc_append(t_expand *exp, const char *value)
{
	while (*value)
	{
		if (expand_append(exp, *value) != 0)
			return (1);
		value++;
	}
	return (0);
}

static int	heredoc_step(t_expand *exp, const char **line, t_shell *shell)
{
	char	*value;
	size_t	consumed;
	int		status;

	if (**line != '$')
	{
		status = expand_append(exp, **line);
		(*line)++;
		return (status);
	}
	value = expand_variable(shell, *line, &consumed);
	if (value == NULL)
		return (1);
	status = heredoc_append(exp, value);
	free(value);
	*line += consumed;
	return (status);
}

char	*heredoc_expand(const char *line, t_shell *shell)
{
	t_expand	exp;

	if (expand_init(&exp) != 0)
		return (NULL);
	while (*line)
	{
		if (heredoc_step(&exp, &line, shell) != 0)
		{
			free(exp.buffer);
			return (NULL);
		}
	}
	return (exp.buffer);
}
