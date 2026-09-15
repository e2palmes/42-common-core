#include "minishell.h"

int	builtin_env(t_shell *shell)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (shell->env[i])
	{
		j = 0;
		while (shell->env[i][j] && shell->env[i][j] != '=')
			j++;
		if (shell->env[i][j] == '=')
		{
			if (write_string(1, shell->env[i]) != 0
				|| write_string(1, "\n") != 0)
				return (1);
		}
		i++;
	}
	return (0);
}