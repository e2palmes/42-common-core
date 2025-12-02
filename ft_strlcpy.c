/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:33:10 by ediba-de          #+#    #+#             */
/*   Updated: 2025/12/02 15:20:40 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;

	if (size == 0)
		return (ft_strlen(src));
	index = 0;
	while (index < size - 1 && src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (ft_strlen((char *)src));
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
