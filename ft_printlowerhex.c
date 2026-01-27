/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlowerhex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:08:16 by ediba-de          #+#    #+#             */
/*   Updated: 2025/12/23 00:37:34 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printlowerhex(unsigned long nb)
{
	char	*hex;
	int		n;

	n = 1;
	hex = "0123456789abcdef";
	if (nb >= 16)
		n = n + ft_printlowerhex(nb / 16);
	write(1, &hex[nb % 16], 1);
	return (n);
}
