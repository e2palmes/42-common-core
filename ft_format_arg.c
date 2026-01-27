/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:46:47 by ediba-de          #+#    #+#             */
/*   Updated: 2025/12/28 00:04:45 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_arg(va_list args, char flag)
{
	if (flag == '%')
		return (ft_printchar('%'));
	else if (flag == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (flag == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (flag == 'p')
		return (ft_printpointer(va_arg(args, void *)));
	else if (flag == 'd' || flag == 'i')
		return (ft_printdecimal(va_arg(args, int)));
	else if (flag == 'u')
		return (ft_printunsigneddecimal(va_arg(args, unsigned int)));
	else if (flag == 'x')
		return (ft_printlowerhex(va_arg(args, unsigned int)));
	else if (flag == 'X')
		return (ft_printupperhex(va_arg(args, unsigned int)));
	return (-1);
}
