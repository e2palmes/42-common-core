/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:08:50 by ediba-de          #+#    #+#             */
/*   Updated: 2025/12/02 14:54:46 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *searched, size_t len)
{
	size_t	i;
	size_t	j;

	if (*searched == '\0')
		return ((char *)str);
	i = 0;
	if (len > ft_strlen(str))
		len = ft_strlen(str);
	while ((i < len) && str[i] != '\0')
	{
		if (str[i] == searched[0])
		{
			j = 0;
			while (str[i + j] == searched[j] && i + j < len)
				j++;
			if (searched[j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>

int main() {
    char *str = "chapeau bas mon fils";
    char *substr = "bas";
    size_t max = strlen(str) + 1;
    char *res1 = ft_strnstr(str, substr, max);
    char *res2 = strnstr(str, substr, max);

    printf("ft_strnstr: '%s'\n", res1);
    printf("strnstr: '%s'\n", res2);

    return 0;
}*/
