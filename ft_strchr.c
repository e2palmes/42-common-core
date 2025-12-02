/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:41:21 by ediba-de          #+#    #+#             */
/*   Updated: 2025/12/02 13:24:23 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
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
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char *src = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
    char *d1 = strchr(src, 'e');
    char *d2 = ft_strchr(src, 'e');

    // Display result : The C LAnguAge
    printf( "strchr : %s\n", d1 );
    printf( "ft_strchr : %s\n", d2 );

    return 0;
}*/
