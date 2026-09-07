#include "minishell.h"

static char	*env_strdup(const char *str)
{
	char	*copy;
	size_t	len;
	size_t	i;

	len = 0;
	while (str[len])
		len++;
	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	env_free(char **env)
{
	size_t	i;

	if (env == NULL)
		return ;
	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}

char	**env_copy(char **envp)
{
	char	**env;
	size_t	i;

	i = 0;
	while (envp && envp[i])
		i++;
	env = malloc(sizeof(char *) * (i + 1));
	if (env == NULL)
		return (NULL);
	i = 0;
	while (envp && envp[i])
	{
		env[i] = env_strdup(envp[i]);
		if (env[i] == NULL)
		{
			env_free(env);
			return (NULL);
		}
		i++;
	}
	env[i] = NULL;
	return (env);
}