#include "minishell.h"

t_token	*token_new(char *str, size_t len, t_token_type type)
{
	t_token	*token;
	size_t	i;

	token = malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	token->value = malloc(sizeof(char) * (len + 1));
	if (token->value == NULL)
	{
		free(token);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		token->value[i] = str[i];
		i++;
	}
	token->value[i] = '\0';
	token->type = type;
	token->next = NULL;
	return (token);
}

void	token_add(t_token **tokens, t_token *new)
{
	t_token	*last;

	if (*tokens == NULL)
	{
		*tokens = new;
		return ;
	}
	last = *tokens;
	while (last->next)
		last = last->next;
	last->next = new;
}

void	tokens_free(t_token *tokens)
{
	t_token	*next;

	while (tokens)
	{
		next = tokens->next;
		free(tokens->value);
		free(tokens);
		tokens = next;
	}
}