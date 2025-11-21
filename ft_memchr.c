/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 00:59:29 by ediba-de          #+#    #+#             */
/*   Updated: 2025/11/15 02:06:28 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	int					index;
	const unsigned char	*str;

	index = 0;
	str = (const unsigned char *)s;
	while (index < size)
	{
		if (str[index] == (unsigned char)c)
			return (&(s[index]));
		index++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[] = "Hello world!";
    
    void *real = memchr(str, 'o', 12);
    void *mine = ft_memchr(str, 'o', 12);

    printf("real memchr: %s\n", real);
    printf("ft_memchr  : %s\n", mine);

    // Test for character not found
    real = memchr(str, 'x', 12);
    mine = ft_memchr(str, 'x', 12);

    printf("real memchr (not found): %p\n", real);
    printf("ft_memchr  (not found): %p\n", mine);

    return 0;
}
*/
