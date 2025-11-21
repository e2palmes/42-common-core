/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 02:13:34 by ediba-de          #+#    #+#             */
/*   Updated: 2025/11/17 18:44:14 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t size)
{
	unsigned long	index;
	unsigned char	*p1_;
	unsigned char	*p2_;

	index = 0;
	p1_ = (unsigned char *)p1;
	p2_ = (unsigned char *)p2;
	while (index < size)
	{
		if (p1_[index] != p2_[index])
			return (p1_[index] - p2_[index]);
		index++;
	}
	return (0);
}
/*
 *
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main() {

    int array1 [] = { 54, 85, 20, 63, 21 };
    int array2 [] = { 54, 85, 19, 63, 21 };
    size_t size = sizeof( int ) * 5;

    printf("memcmp: %d\n", memcmp( array2, array1, size));
    printf("ft_memcmp: %d\n", ft_memcmp( array2, array1, size));

    // assert( memcmp( array1, array2, size) == ft_memcmp( array1, array2, size) );
    // assert( memcmp( array1, array1, size) == ft_memcmp( array1, array1, size) );
    // assert( memcmp( array2, array1, size) == ft_memcmp( array2, array1, size) );

    printf( "Test is ok\n" );

    return 0;
}*/
