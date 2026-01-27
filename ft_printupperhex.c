/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printupperhex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:08:16 by ediba-de          #+#    #+#             */
/*   Updated: 2025/12/23 00:16:43 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printupperhex(unsigned long nb)
{
	char	*hex;
	int		n;

	n = 1;
	hex = "0123456789ABCDEF";
	if (nb >= 16)
		n = n + ft_printupperhex(nb / 16);
	write(1, &hex[nb % 16], 1);
	return (n);
}
