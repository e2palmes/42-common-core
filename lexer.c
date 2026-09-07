#include "minishell.h"

static t_token_type	operator_type(char *str, size_t *len)
{
	*len = 1;
	if (str[0] == '|')
		return (TOKEN_PIPE);
	if (str[0] == '<' && str[1] == '<')
	{
		*len = 2;
		return (TOKEN_HEREDOC);
	}
	if (str[0] == '>' && str[1] == '>')
	{
		*len = 2;
		return (TOKEN_APPEND);
	}
	if (str[0] == '<')
		return (TOKEN_IN);
	return (TOKEN_OUT);
}

static int	read_token(char *str, size_t *len, t_token **tokens)
{
	t_token_type	type;
	t_token			*new;

	type = TOKEN_WORD;
	if (lexer_operator(str[0]))
		type = operator_type(str, len);
	else
	{
		*len = lexer_word_len(str);
		if (*len == 0)
			return (2);
	}
	new = token_new(str, *len, type);
	if (new == NULL)
		return (1);
	token_add(tokens, new);
	return (0);
}

int	lexer(char *line, t_token **tokens)
{
	size_t	i;
	size_t	len;
	int		status;

	*tokens = NULL;
	i = 0;
	while (line[i])
	{
		if (lexer_space(line[i]))
			i++;
		else
		{
			status = read_token(line + i, &len, tokens);
			if (status != 0)
			{
				tokens_free(*tokens);
				*tokens = NULL;
				return (status);
			}
			i += len;
		}
	}
	return (0);
}