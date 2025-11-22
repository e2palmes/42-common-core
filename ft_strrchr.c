/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:03:23 by ediba-de          #+#    #+#             */
/*   Updated: 2025/11/22 10:46:03 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*strrchr(const char *str, int c)
{
	int		index;
	char	*s;

	s = (char *)str;
	index = ft_strlen((char *)str) - 1;
	while (index >= 0)
	{
		if (s[index] == c)
			return (s);
		index--;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    const char * source = "The C Language";
    char * destination;
    char * pointer;
    int length = strlen( source );

    // We clone the inital string
    destination = (char *) malloc( sizeof( char) * (length+1) );
    strcpy( destination, source );

    // We replace all 'a' characters
    pointer = ft_strchr( destination, 'a' );
    *pointer = 'A';

    // Display result : The C LAnguAge
    printf( "Result : %s\n", destination );

    // Release dynamicly allocated memory
    free( destination );

    return 0;
}*/
