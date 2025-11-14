/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:15:25 by ediba-de          #+#    #+#             */
/*   Updated: 2025/11/14 17:59:46 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
/*
#include<stdio.h>

int	main()
{
	char *str = "Mi Nombre M1guel";
	while(*str)
	{
		printf("%c", ft_toupper(*str));
		*str++;
	}
}*/
