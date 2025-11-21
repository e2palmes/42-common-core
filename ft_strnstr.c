/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:08:50 by ediba-de          #+#    #+#             */
/*   Updated: 2025/11/18 16:48:49 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *searched, size_t len)
{
	int	i;
	int	j;
	char	*s;
	char	*l;

	s = (char *)str;
	l = (char *)searched;
	if (!(*l))
		return (s);
	i = 0;
	while ((i < len) && *s != '\0')
	{
		if(*s == *l)
		{
			j = 0;
			while (s[j] == l[j])
				j++;
			if (j == ft_strlen(l) + 1)
				return (s);
		}
		s++;
		i++;
	}
	return ('\0');
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *str = "loyer bas";
    const char *substr = "bas";
    char *res1 = ft_strnstr(str, substr, 9);
    // char *res2 = strnstr(str, substr, 5);

    printf("ft_strnstr: %s", res1);
    // printf("strnstr: %s", res2);

    return 0;
}*/
