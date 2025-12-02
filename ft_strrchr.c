/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:03:23 by ediba-de          #+#    #+#             */
/*   Updated: 2025/12/02 17:41:34 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		index;

	index = ft_strlen(str);
	while (index >= 0)
	{
		if ((unsigned char)str[index] == (unsigned char)c)
			return ((char *)&str[index]);
		index--;
	}
	return (NULL);
}
/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() {

    char *src = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
    char *d1 = strrchr(src, '\0');
    char *d2 = ft_strrchr(src, '\0');

    // Display result : The C LAnguAge
    printf( "strrchr : %s\n", d1 );
    printf( "ft_strrchr : %s\n", d2 );

    return 0;
}*/
