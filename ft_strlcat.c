/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:03:54 by ediba-de          #+#    #+#             */
/*   Updated: 2025/11/22 00:59:10 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int	index;
	int	srclen;
	int	destlen;
	size_t	offset;

	index = 0;
	srclen = 0;
	destlen = 0;
	while (dest[destlen])
		destlen++;
	while (src[srclen])
		srclen++;
	offset = destlen;
	while (*(src + index) != '\0')
	{
		dest[offset] = *(src + index);
		offset++;
		index++;
		if (offset == size - 1)
			break ;
	}
	dest[offset] = '\0';
	return (srclen + destlen);
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
