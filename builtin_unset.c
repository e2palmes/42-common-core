#include "minishell.h"

int	builtin_unset(char **argv, t_shell *shell)
{
	size_t	i;
	size_t	len;
	int		index;

	i = 1;
	while (argv[i])
	{
		len = env_key_len(argv[i]);
		index = -1;
		if (len > 0 && argv[i][len] == '\0')
			index = env_index(shell->env, argv[i], len);
		if (index >= 0)
		{
			free(shell->env[index]);
			while (shell->env[index + 1])
			{
				shell->env[index] = shell->env[index + 1];
				index++;
			}
			shell->env[index] = NULL;
		}
		i++;
	}
	return (0);
}