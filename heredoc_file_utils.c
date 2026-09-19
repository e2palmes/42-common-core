#include "minishell.h"

void	copy_hd_template(char *path)
{
	const char	*template;
	size_t		i;

	template = "/tmp/minishell_hd_00000000";
	i = 0;
	while (template[i])
	{
		path[i] = template[i];
		i++;
	}
	path[i] = '\0';
}

int	heredoc_open_error(int *read_fd, int write_fd)
{
	int	error;

	error = errno;
	close(*read_fd);
	close(write_fd);
	*read_fd = -1;
	errno = error;
	return (-1);
}