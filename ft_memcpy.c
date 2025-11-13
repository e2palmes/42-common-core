/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:30:58 by ediba-de          #+#    #+#             */
/*   Updated: 2025/11/13 17:18:14 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	int	index;
	char	*dest;
	
	dest = (char  *)destination;
	index = 0;
	while (index < size)
	{
		dest[index] = ((char *)source)[index];
		index++;
	}
	return (destination);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int array [] = { 54, 85, 20, 63, 21 };
    int * copy = NULL;
    int length = sizeof( int ) * 5;
       
    // Memory allocation and copy
    copy = (int *) malloc( length );
    void *res = ft_memcpy( copy, array, length );
        
    printf("res: %p\n", res);
    // Display the copied values
    for( length=0; length<5; length++ ) {
        printf( "%d ", copy[ length ] );
    }
    printf( "\n" );
        
    free( copy );
    
    return EXIT_SUCCESS;
}*/
