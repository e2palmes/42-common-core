#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
//stdio is not needed, just let him for test with main
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*ret = malloc(9999);
	char	c;
	int		i = 0;
	int		bytes_read = 0;

	if (fd < 0)
		return (NULL);
	while ((bytes_read = read(fd, &c, 1)) > 0)
	{
		ret[i] = c;
		i++;
		if (c == '\n')
			break ;
	}
	if (i == 0 || bytes_read < 0)
	{
		free(ret);
		return (NULL);
	}
	ret[i] = '\0';
	return (ret);
}