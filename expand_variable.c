#include "minishell.h"

static int	name_start(char c)
{
	return ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z') || c == '_');
}

static size_t	variable_len(const char *str)
{
	size_t	i;

	if (!name_start(str[0]))
		return (0);
	i = 1;
	while (name_start(str[i]) || (str[i] >= '0' && str[i] <= '9'))
		i++;
	return (i);
}

static char	*status_string(int status)
{
	char	buffer[4];
	int		i;

	i = 3;
	buffer[i] = '\0';
	if (status == 0)
		buffer[--i] = '0';
	while (status > 0)
	{
		buffer[--i] = '0' + status % 10;
		status /= 10;
	}
	return (env_strdup(buffer + i));
}

char	*expand_variable(t_shell *shell, const char *str,
		size_t *consumed)
{
	size_t	len;

	*consumed = 1;
	if (str[1] == '?')
	{
		*consumed = 2;
		return (status_string(shell->exit_status));
	}
	len = variable_len(str + 1);
	if (len == 0)
		return (env_strdup("$"));
	*consumed = len + 1;
	return (env_strdup(env_value(shell->env, str + 1, len)));
}