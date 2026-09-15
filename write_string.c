#include "minishell.h"

int	write_string(int fd, const char *str)
{
	size_t	len;
	ssize_t	written;

	len = 0;
	while (str[len])
		len++;
	while (len > 0)
	{
		written = write(fd, str, len);
		if (written < 0 && errno == EINTR)
			continue ;
		if (written <= 0)
			return (1);
		str += written;
		len -= written;
	}
	return (0);
}