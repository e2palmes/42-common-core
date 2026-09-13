#include "minishell.h"

static void	error_putstr(const char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
}

int	exec_message(const char *name, const char *message, int status)
{
	error_putstr("minishell: ");
	error_putstr(name);
	error_putstr(": ");
	error_putstr(message);
	error_putstr("\n");
	return (status);
}

int	exec_error(const char *name, int error)
{
	int	status;

	status = 126;
	if (error == ENOENT || error == ENOTDIR)
		status = 127;
	else if (error == ENOMEM)
		status = 1;
	return (exec_message(name, strerror(error), status));
}