/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:39:33 by ediba-de          #+#    #+#             */
/*   Updated: 2025/11/21 23:47:50 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int value, size_t size)
{
	size_t		index;
	unsigned char	*dest_;

	dest_ = (unsigned char *)dest;
	index = 0;
	while (index < size)
	{
		dest_[index] = (unsigned char)value;
		index++;
	}
	return (dest);
}
