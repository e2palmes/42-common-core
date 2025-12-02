/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 21:10:50 by ediba-de          #+#    #+#             */
/*   Updated: 2025/12/02 17:39:32 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	index;
	size_t	s_len;

	s_len = ft_strlen((char *)s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc(len + 1);
	if (!sub || !s)
		return (NULL);
	index = 0;
	while (index < len)
	{
		sub[index] = s[start + index];
		index++;
	}
	sub[index] = '\0';
	return (sub);
}
/*
#include <stdio.h>

int main(void)
{
    char *s = "Bonjour le monde !";
    char *sub;

    printf("=== Tests ft_substr ===\n\n");

    // Test 1 : normal
    sub = ft_substr(s, 0, 7);
    printf("Test 1 (0,7): '%s'\n", sub);
    free(sub);

    // Test 2 : substring au milieu
    sub = ft_substr(s, 8, 2);
    printf("Test 2 (8,2): '%s'\n", sub);
    free(sub);

    // Test 3 : start > longueur de s
    sub = ft_substr(s, 100, 5);
    printf("Test 3 (start trop grand): '%s'\n", sub);
    free(sub);

    // Test 4 : len plus grand que la fin de s
    sub = ft_substr(s, 5, 100);
    printf("Test 4 (len trop grand): '%s'\n", sub);
    free(sub);

    // Test 5 : len = 0
    sub = ft_substr(s, 3, 0);
    printf("Test 5 (len=0): '%s'\n", sub);
    free(sub);

    return 0;
}
*/
