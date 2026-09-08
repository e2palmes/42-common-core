#include "minishell.h"

static int	expand_grow(t_expand *exp)
{
	char	*new;
	size_t	i;

	new = malloc(exp->capacity * 2);
	if (new == NULL)
		return (1);
	i = 0;
	while (i <= exp->len)
	{
		new[i] = exp->buffer[i];
		i++;
	}
	free(exp->buffer);
	exp->buffer = new;
	exp->capacity *= 2;
	return (0);
}

int	expand_append(t_expand *exp, char c)
{
	if (exp->len + 1 >= exp->capacity)
	{
		if (expand_grow(exp) != 0)
			return (1);
	}
	exp->buffer[exp->len++] = c;
	exp->buffer[exp->len] = '\0';
	exp->active = 1;
	return (0);
}

int	expand_flush(t_expand *exp)
{
	t_token	*new;

	if (exp->active == 0)
		return (0);
	new = token_new(exp->buffer, exp->len, TOKEN_WORD);
	if (new == NULL)
		return (1);
	token_add(&exp->fields, new);
	exp->len = 0;
	exp->buffer[0] = '\0';
	exp->active = 0;
	return (0);
}