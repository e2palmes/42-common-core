#include "minishell.h"

int	lexer_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	lexer_operator(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

size_t	lexer_word_len(char *str)
{
	size_t	i;
	char	quote;

	i = 0;
	quote = 0;
	while (str[i])
	{
		if (quote == 0 && (lexer_space(str[i])
				|| lexer_operator(str[i])))
			break ;
		if (str[i] == '\'' || str[i] == '"')
		{
			if (quote == 0)
				quote = str[i];
			else if (quote == str[i])
				quote = 0;
		}
		i++;
	}
	if (quote != 0)
		return (0);
	return (i);
}