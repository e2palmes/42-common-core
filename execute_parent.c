#include "minishell.h"

int	execute_parent(t_cmd *command, t_shell *shell)
{
	int	saved[2];
	int	status;

	if (command->redirs == NULL)
	{
		if (command->argv[0] == NULL)
			return (0);
		return (run_builtin(command, shell));
	}
	if (save_stdio(saved) != 0)
		return (1);
	status = apply_redirections(command->redirs);
	if (status == 0 && command->argv[0])
		status = run_builtin(command, shell);
	if (restore_stdio(saved) != 0)
	{
		shell->should_exit = 1;
		return (1);
	}
	return (status);
}
