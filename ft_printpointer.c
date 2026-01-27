/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:26:13 by ediba-de          #+#    #+#             */
/*   Updated: 2025/12/27 23:42:25 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printpointer(void *s)
{
	int				n;
	unsigned long	addr;

	if (s == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	addr = (unsigned long)s;
	write(1, "0x", 2);
	n = ft_printlowerhex(addr);
	return (n + 2);
}
