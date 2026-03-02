#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>

#ifndef BUFFER_SIZE
	# define BUFFER_SIZE 5
#endif

int		append_stash_to_line(char *line, char *stash);
char	*append_buf_to_stash(char *buf, char *stash, int bytes_read);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
char	*get_next_line(int fd);

#endif