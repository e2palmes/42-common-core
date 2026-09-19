#include "minishell.h"

char	**env_for_exec(char **env)
{
	char	**result;
	size_t	i;
	size_t	j;

	i = 0;
	while (env[i])
		i++;
	result = malloc(sizeof(char *) * (i + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (env[i])
	{
		if (env[i][env_key_len(env[i])] == '=')
			result[j++] = env[i];
		i++;
	}
	result[j] = NULL;
	return (result);
}