/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:57:45 by ediba-de          #+#    #+#             */
/*   Updated: 2025/12/23 00:36:20 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdecimal(int nb)
{
	char	*str;
	int		len;

	str = ft_itoa(nb);
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}
