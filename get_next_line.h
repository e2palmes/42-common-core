#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>

#ifndef BUFFER_SIZE
	# define BUFFER_SIZE 5
#endif

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*set_stash(int fd, char *stash);
char	*_get_line(char *stash);
char	*update_stash(char *stash);
char	*get_next_line(int fd);

#endif