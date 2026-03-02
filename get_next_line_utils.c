#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	total_len;
	size_t	index;
	char	*str;

	len1 = ft_strlen((char *)s1);
	total_len = len1 + ft_strlen((char *)s2);
	index = 0;
	str = malloc(total_len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (s1[index] && index < len1)
	{
		str[index] = s1[index];
		index++;
	}
	index = 0;
	while (s2[index] && index + len1 < total_len)
	{
		str[len1 + index] = s2[index];
		index++;
	}
	str[index + len1] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}
