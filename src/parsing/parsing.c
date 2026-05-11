#include "../headers/so_long.h"

char	*read_map_file(char *path)
{
	int		fd;
	char	*line;
	char	*all;
	char	*tmp;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	all = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		tmp = all;
		all = ft_strjoin(all, line);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (all);
}