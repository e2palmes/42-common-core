#include "minishell.h"

const char	*env_value(char **env, const char *name, size_t len)
{
	size_t	i;
	size_t	j;

	if (len == 0)
		return ("");
	i = 0;
	while (env && env[i])
	{
		j = 0;
		while (j < len && env[i][j] && env[i][j] == name[j])
			j++;
		if (j == len && env[i][j] == '=')
			return (env[i] + j + 1);
		i++;
	}
	return ("");
}