#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
char    *ft_strjoin(char *s1, char *s2)
{
    size_t  i;
    size_t  j;
    char    *str;

    if (!s1) // Si s1 est vide, on crée une base vide pour strjoin
    {
        s1 = malloc(1);
        if (!s1)
            return (NULL);
        s1[0] = '\0';
    }
    if (!s2)
        return (NULL);
    str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
    if (str == NULL)
        return (free(s1), NULL); // Très important : libérer s1 si le malloc échoue
    i = -1;
    j = 0;
    while (s1[++i])
        str[i] = s1[i];
    while (s2[j])
        str[i++] = s2[j++];
    str[i] = '\0';
    free(s1); // On libère s1 ici pour simplifier le code de set_stash
    return (str);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	if (!s) // Protection ajoutée
        return (NULL);
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