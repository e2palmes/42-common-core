/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:35:30 by ediba-de          #+#    #+#             */
/*   Updated: 2025/11/26 17:26:18 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_int_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char *alloc_str(int n, int len)
{
	char	*str;

	str = malloc((len) * sizeof(char));
	if (!len)
		return (0);
	str[len - 1] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int	len;
	int	index;
	char	*str;

	nbr = (long)n;
	len = get_int_len(n) + 1;
	str = alloc_str(n, len);
	if (!str)
		return (0);
	index = len - 2;
	nbr = -nbr;
	while (nbr != 0)
	{
		str[index] = (nbr % 10) + 48;
		nbr /= 10;
		index--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
/*
#include <stdio.h>

int main(void)
{
	int nb = -4284;
	char *str = ft_itoa(nb);

	printf("str: %s\n", str);
}*/
