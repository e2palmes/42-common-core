/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:46:31 by ediba-de          #+#    #+#             */
/*   Updated: 2025/12/23 22:46:31 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
#include <stdlib.h>

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int		i;
	int		n;

	va_start(params, str);
	i = 0;
	n = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			n = n + ft_format_arg(params, str[i + 1]);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			n++;
		}
		i++;
	}
	va_end(params);
	return (n);
}
