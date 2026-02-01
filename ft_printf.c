/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:46:31 by ediba-de          #+#    #+#             */
/*   Updated: 2026/02/01 15:16:50 by ediba-de         ###   ########.fr       */
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
	int		ret;

	if (!str)
		return (-1);
	va_start(params, str);
	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] && ++i)
		{
			ret = ft_format_arg(params, str[i]);
			if (ret == -1)
				return (va_end(params), -1);
			n += ret;
		}
		else
			n += write(1, &str[i], 1);
		i++;
	}
	va_end(params);
	return (n);
}
