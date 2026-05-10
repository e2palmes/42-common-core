/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:35:30 by ediba-de          #+#    #+#             */
/*   Updated: 2025/12/02 17:21:42 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	int_len(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		len;
	char	*str;

	nbr = n;
	len = int_len(nbr);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
		nbr = -nbr;
	while (len--)
	{
		if (n < 0 && len == 0)
		{
			str[0] = '-';
			break ;
		}
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}

/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int nb = -2147483647;
	char *s1 = ft_itoa(nb);
	//char *s2 = itoa(nb);

	printf("ft_itoa: %s\n", s1);
	//printf("itoa: %s\n", s2);
}*/
