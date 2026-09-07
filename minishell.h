#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_shell
{
	char	**env;
	int		exit_status;
}	t_shell;

char	**env_copy(char **envp);
void	env_free(char **env);
int		builtin_env(t_shell *shell);


#endif