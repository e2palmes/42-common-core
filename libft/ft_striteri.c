/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:38:03 by ediba-de          #+#    #+#             */
/*   Updated: 2026/01/30 02:13:41 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	index = 0;
	while (s[index])
	{
		f(index, (s + index));
		index++;
	}
}
/*
#include <stdio.h>

// Fonction de test : met chaque char en majuscule + son index en préfixe modifié
void to_upper_test(unsigned int i, char *c)
{
    (void)i; // l’index ne sert pas ici
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

int main(void)
{
    char input[] = "abcdef";
    ft_striteri(input, to_upper_test);

    printf("Input:  %s\n", input);

    return 0;
}*/
