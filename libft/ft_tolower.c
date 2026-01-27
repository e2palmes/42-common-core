/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:32:29 by ediba-de          #+#    #+#             */
/*   Updated: 2025/11/14 16:39:38 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*
#include<stdio.h>

int     main()
{
        char *str = "Mi Nombre M1guel";
        while(*str)
        {
                printf("%c", ft_tolower(*str));
                *str++;
        }
}*/
