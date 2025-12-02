/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:03:54 by ediba-de          #+#    #+#             */
/*   Updated: 2025/12/02 15:50:51 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	index;
	size_t	slen;
	size_t	dlen;

	index = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen(dest);
	if (size <= dlen)
		return (slen + size);
	while (src[index] && dlen + index < size - 1)
	{
		dest[dlen + index] = *(src + index);
		index++;
	}
	dest[dlen + index] = '\0';
	return (slen + dlen);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char first[] = "This is ";
    char last[] = "a potentially long string";
    int r;
    int size = 16;
    char buffer[size];

    strcpy(buffer,first);
    r = ft_strlcat(buffer,last,size);

    puts(buffer);
    printf("Value returned: %d\n",r);
    if( r > size )
        puts("String truncated");
    else
        puts("String was fully copied");

    return(0);
}*/
