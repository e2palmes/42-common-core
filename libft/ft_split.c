/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:08:10 by ediba-de          #+#    #+#             */
/*   Updated: 2025/12/01 18:14:32 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	get_next_word(char **nextword, size_t *nextword_len, char c)
{
	size_t	i;

	*nextword += *nextword_len;
	*nextword_len = 0;
	i = 0;
	while (**nextword && **nextword == c)
			(*nextword)++;
	while ((*nextword)[i])
	{
		if ((*nextword)[i] == c)
			return ;
		(*nextword_len)++;
		i++;
	}
}

static char	**free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static size_t	word_count(const char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && !(str[i] == c))
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	*nextword;
	size_t	nextword_len;
	size_t	i;

	if (!s)
		return (NULL);
	array = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!array)
		return (NULL);
	i = 0;
	nextword = (char *)s;
	nextword_len = 0;
	while (i < word_count(s, c))
	{
		get_next_word(&nextword, &nextword_len, c);
		array[i] = malloc((nextword_len + 1) * sizeof(char));
		if (!array[i])
			return (free_array(array));
		ft_strlcpy(array[i], nextword, nextword_len + 1);
		i++;
	}
	array[i] = 0;
	return (array);
}
/*
#include <stdio.h>

int main(void)
{
        char str[] = ",Bonjour,tout,le,,monde,,";
        char **arr = ft_split(str, ',');

        int     i = 0;
        while (arr[i])
        {
                printf("%s-", arr[i]);
                i++;
        }
}*/
