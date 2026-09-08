#include "minishell.h"

static int	append_value(t_expand *exp, char *value)
{
	size_t	i;

	i = 0;
	while (value[i])
	{
		if (exp->quote == 0 && (value[i] == ' '
				|| value[i] == '\t' || value[i] == '\n'))
		{
			if (expand_flush(exp) != 0)
				return (1);
		}
		else if (expand_append(exp, value[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

static int	expand_dollar(t_expand *exp, const char **str,
		t_shell *shell)
{
	char	*value;
	size_t	consumed;
	int		status;

	value = expand_variable(shell, *str, &consumed);
	if (value == NULL)
		return (1);
	status = append_value(exp, value);
	free(value);
	*str += consumed;
	return (status);
}

int	expand_step(t_expand *exp, const char **str, t_shell *shell)
{
	char	c;

	c = **str;
	if ((c == '\'' || c == '"')
		&& (exp->quote == 0 || exp->quote == c))
	{
		if (exp->quote == 0)
			exp->quote = c;
		else
			exp->quote = 0;
		exp->active = 1;
		(*str)++;
		return (0);
	}
	if (c == '$' && exp->quote != '\'')
		return (expand_dollar(exp, str, shell));
	if (expand_append(exp, c) != 0)
		return (1);
	(*str)++;
	return (0);
}