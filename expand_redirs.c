#include "minishell.h"

static int	delimiter_quote(char c, char *quote)
{
	if ((c != '\'' && c != '"') || (*quote != 0 && *quote != c))
		return (0);
	if (*quote == 0)
		*quote = c;
	else
		*quote = 0;
	return (1);
}

static void	prepare_heredoc(t_token *redir)
{
	size_t	i;
	size_t	j;
	char	quote;

	i = 0;
	j = 0;
	quote = 0;
	while (redir->value[i])
	{
		if (delimiter_quote(redir->value[i], &quote))
			redir->flags |= REDIR_QUOTED;
		else
			redir->value[j++] = redir->value[i];
		i++;
	}
	redir->value[j] = '\0';
}

static int	expand_redirect(t_token *redir, t_shell *shell)
{
	t_token	*fields;

	if (expand_word(redir->value, shell, &fields) != 0)
		return (1);
	if (fields == NULL || fields->next != NULL)
	{
		redir->flags |= REDIR_AMBIGUOUS;
		tokens_free(fields);
		return (0);
	}
	free(redir->value);
	redir->value = fields->value;
	free(fields);
	return (0);
}

int	expand_redirs(t_token *redirs, t_shell *shell)
{
	while (redirs)
	{
		if (redirs->type == TOKEN_HEREDOC)
			prepare_heredoc(redirs);
		else if (expand_redirect(redirs, shell) != 0)
			return (1);
		redirs = redirs->next;
	}
	return (0);
}