/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:33:10 by ediba-de          #+#    #+#             */
/*   Updated: 2025/11/14 17:58:18 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int	index;

	if (size == 0)
		return (ft_strlen(src));
	index = 0;
	while (index < size - 1)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char string[] = "Hello there, Venus";
	char buffer[19];
	int r;
	
	r = ft_strlcpy(buffer,string,0);
	printf("Copied '%s' into '%s', length %d\n", string, buffer, r);
}*/
