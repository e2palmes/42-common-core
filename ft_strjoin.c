/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 22:40:55 by ediba-de          #+#    #+#             */
/*   Updated: 2025/12/02 17:45:13 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	total_len;
	size_t	index;
	char	*str;

	len1 = ft_strlen((char *)s1);
	total_len = len1 + ft_strlen((char *)s2);
	index = 0;
	str = malloc(total_len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (s1[index] && index < len1)
	{
		str[index] = s1[index];
		index++;
	}
	index = 0;
	while (s2[index] && index + len1 < total_len)
	{
		str[len1 + index] = s2[index];
		index++;
	}
	str[index + len1] = '\0';
	return (str);
}
