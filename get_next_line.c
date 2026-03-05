#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = set_stash(fd, stash);
	if (!stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = _get_line(stash);
	if (!line) // Si la création de la ligne échoue, on clean tout
    {
        free(stash);
        stash = NULL;
        return (NULL);
    }
	stash = update_stash(stash);
	return (line);
}

char    *set_stash(int fd, char *stash)
{
    char    *buf;
    int     bytes_read;

    buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buf)
        return (free(stash), NULL);
    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, buf, BUFFER_SIZE);
        if (bytes_read == -1)
            return (free(buf), free(stash), NULL);
        if (bytes_read == 0)
            break ;
        buf[bytes_read] = '\0';
        stash = ft_strjoin(stash, buf);
        if (!stash) // Si strjoin échoue (malloc NULL_CHECK)
            return (free(buf), NULL);
        if (ft_strchr(buf, '\n')) // OPTIMISATION : on ne cherche que dans le buffer lu
            break ;
    }
    free(buf);
    return (stash);
}

char	*_get_line(char *stash)
{
	char	*line;
	size_t	i;

	if (stash == NULL || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_stash(char *stash)
{
	char	*new_stash;
	size_t	i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_strdup(stash + i + 1);
	free(stash);
	return (new_stash);
}

// #include <stdio.h>
// int main()
// {
// 	int fd;
// 	fd = open("giant_line.txt", O_RDONLY);
// 	char *line = get_next_line(fd);
// 	char *line2 = get_next_line(fd);
// 	char *line3 = get_next_line(fd);
// 	char *line4 = get_next_line(fd);
// 	printf("line 1: %s", line);
// 	printf("line 2: %s", line2);
// 	printf("line 3: %s", line3);
// 	printf("line 4: %s", line4);
// 	return (0);
// }
