#include "minishell.h"

static void	syntax_putstr(char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
}

static int	syntax_error(t_token *token)
{
	syntax_putstr("minishell: syntax error near unexpected token `");
	if (token == NULL)
		syntax_putstr("newline");
	else
		syntax_putstr(token->value);
	syntax_putstr("'\n");
	return (2);
}

int	syntax_check(t_token *tokens)
{
	t_token	*previous;

	previous = NULL;
	while (tokens)
	{
		if (tokens->type == TOKEN_PIPE)
		{
			if (previous == NULL || previous->type == TOKEN_PIPE)
				return (syntax_error(tokens));
			if (tokens->next == NULL)
				return (syntax_error(NULL));
		}
		else if (tokens->type != TOKEN_WORD)
		{
			if (tokens->next == NULL
				|| tokens->next->type != TOKEN_WORD)
				return (syntax_error(tokens->next));
		}
		previous = tokens;
		tokens = tokens->next;
	}
	return (0);
}