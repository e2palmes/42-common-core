/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 23:46:40 by ediba-de          #+#    #+#             */
/*   Updated: 2025/12/02 15:55:51 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	size_t	len;
	char	*str;

	len = ft_strlen((char *)s);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	index = 0;
	while (s[index] && index < len)
	{
		str[index] = f(index, s[index]);
		index++;
	}
	str[index] = '\0';
	return (str);
}
/*
#include <stdio.h>

// Fonction de test : met chaque char en majuscule + son index en préfixe modifié
char to_upper_test(unsigned int i, char c)
{
    (void)i; // l’index ne sert pas ici
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

int main(void)
{
    const char *input = "abcdef";
    char *result = ft_strmapi(input, to_upper_test);

    if (!result)
    {
        printf("Malloc failed or function returned NULL\n");
        return (1);
    }

    printf("Input:  %s\n", input);
    printf("Output: %s\n", result);

    free(result);

    return 0;
}
*/
