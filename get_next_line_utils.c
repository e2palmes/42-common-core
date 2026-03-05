#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
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
	str = malloc((total_len + 1) * sizeof(char));
	if (!str || (!s1 && !s2))
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

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	if (str == NULL)
		return (NULL);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	index;
	size_t	s_len;

	s_len = ft_strlen((char *)s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc(len + 1);
	if (!sub || !s)
		return (NULL);
	index = 0;
	while (index < len)
	{
		sub[index] = s[start + index];
		index++;
	}
	sub[index] = '\0';
	return (sub);
}