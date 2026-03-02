#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *buf;
	char *line;
	static char *stash;
	int bytes_read;
	int line_complete;

	line = NULL;
	line_complete = 0;
	while (!line_complete && (stash == NULL || ft_strchr(stash, '\n') == NULL))
	{
		// read from fd into buf
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buf == NULL)
				return (NULL);
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		// set buffer in stash
		stash = append_buf_to_stash(buf, stash, bytes_read);
		// copier le contenu de stash dans line
		line = append_stash_to_line(line, stash);
		if (ft_strchr(stash, '\n') != NULL)
			line_complete = 1;
		// sinon, vider buffer et continuer à lire
	}
	return (line);
}

char	*append_buf_to_stash(char *buf, char *stash, int bytes_read)
{
	int i;
	int j;
	int	stash_len;
	char *new_stash;

	i = 0;
	stash_len = 0;
	if (stash != NULL)
		stash_len = ft_strlen(stash);
	new_stash = malloc((stash_len + bytes_read + 1) * sizeof(char));
	if (new_stash == NULL)
	{
		free(stash);
		return (NULL);
	}
	while (i < stash_len)
	{
		new_stash[i] = stash[i];
		i++;
	}
	
	j = 0;
	while (j < bytes_read)
	{
		new_stash[i + j] = buf[j];
		j++;
	}
	new_stash[i + j] = '\0';
	free(buf);
	free(stash);
	return (new_stash);
}

char	*append_stash_to_line(char *line, char *stash)
{
	int i;
	char *new_line;

	i = 0;
	new_line = malloc((ft_strlen(stash) + 1) * sizeof(char));
	if (new_line == NULL)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
	{
		new_line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		new_line[i] = stash[i];
		i++;
		new_line[i] = '\0';
	}
	else
		new_line[i] = '\0';
	free(line);
	return (new_line);
}

#include <stdio.h>
int main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	char *line = get_next_line(fd);
	char *line2 = get_next_line(fd);
	printf("line 1: %s\n", line);
	printf("line 2: %s\n", line2);
	return (0);
}
