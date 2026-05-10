/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:17:29 by ediba-de          #+#    #+#             */
/*   Updated: 2025/12/01 20:07:56 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_blank(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *nb)
{
	int	index;
	int	res;
	int	sign;

	index = 0;
	res = 0;
	sign = 1;
	while (is_blank(nb[index]))
		index++;
	if (nb[index] == '-')
	{
		sign = -1;
		index++;
	}
	else if (nb[index] == '+')
		index++;
	while (nb[index] >= '0' && nb[index] <= '9')
	{
		res = res * 10 + nb[index] - 48;
		index++;
	}
	return (sign * res);
}
/*
#include <stdlib.h>
#include <stdio.h>

int main()
{
	const char *nb = "\t\v\f\r\n \f-06050";
	printf("ft_atoi: %d\n", ft_atoi(nb));
	printf("atoi: %d\n", atoi(nb));
}*/
