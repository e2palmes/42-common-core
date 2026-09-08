#include "minishell.h"

static int	expand_init(t_expand *exp)
{
	exp->buffer = env_strdup("");
	exp->len = 0;
	exp->capacity = 1;
	exp->active = 0;
	exp->quote = 0;
	exp->fields = NULL;
	return (exp->buffer == NULL);
}

int	expand_word(const char *str, t_shell *shell, t_token **fields)
{
	t_expand	exp;
	int			status;

	*fields = NULL;
	if (expand_init(&exp) != 0)
		return (1);
	status = 0;
	while (*str && status == 0)
		status = expand_step(&exp, &str, shell);
	if (status == 0)
		status = expand_flush(&exp);
	free(exp.buffer);
	if (status != 0)
	{
		tokens_free(exp.fields);
		return (1);
	}
	*fields = exp.fields;
	return (0);
}