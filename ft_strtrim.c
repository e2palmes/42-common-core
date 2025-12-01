/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:15:35 by ediba-de          #+#    #+#             */
/*   Updated: 2025/11/27 14:31:28 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_no_set_chars(const char *s, const char *set)
{
	int		n;
	char	*str;

	n = 0;
	str = (char *)s;
	while (*str)
	{
		if (!ft_strchr(set, *str))
			n++;
		str++;
	}
	return (n);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*trimmed;
	char	*str;
	int		index;

	len = count_no_set_chars(s1, set);
	trimmed = malloc(len * sizeof(char) + 1);
	if (!trimmed)
		return ('\0');
	str = (char *)s1;
	index = 0;
	while (*str)
	{
		if (!ft_strchr(set, *str))
			trimmed[index++] = *s1++;
	}
	trimmed[index] = '\0';
	return (trimmed);
}
/*
#include <stdio.h>

int main()
{
	char *str = "Ceci, n'est, pas, un test";
	char *set = ",'";
	char *res = ft_strtrim(str, set);
	printf("%s\n", res);
}*/
