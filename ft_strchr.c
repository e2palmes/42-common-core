/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:41:21 by ediba-de          #+#    #+#             */
/*   Updated: 2025/11/22 17:57:25 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	char	*s;
	int		index;

	s = (char *)str;
	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			return (&s[index]);
		index++;
	}
	return ('\0');
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
    while (pointer = ft_strchr( destination, 'a' ) ) {
	    printf("found char: %c\n", *pointer);
	    *pointer = 'A';
    }

    // Display result : The C LAnguAge
    printf( "Result : %s\n", destination );

    // Release dynamicly allocated memory
    free( destination );

    return 0;
}*/
