#include "minishell.h"

int	builtin_pwd(void)
{
	char	*cwd;
	int		status;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		perror("minishell: pwd");
		return (1);
	}
	status = write_string(1, cwd);
	if (status == 0)
		status = write_string(1, "\n");
	free(cwd);
	return (status);
}