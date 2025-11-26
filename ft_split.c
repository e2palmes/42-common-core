/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:46:52 by ediba-de          #+#    #+#             */
/*   Updated: 2025/11/25 15:06:46 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char *str, char c)
{
	int	count;
	int	index;
	int	is_word;

	index = 0;
	count = 0;
	is_word = 0;
	while (str[index])
	{
		if (str[index] != c && !is_word)
		{
			count++;
			is_word = 1;
		}
		else if (str[index] == c)
			is_word = 0;
		index++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	int	index;
	int	strlen;
	char	**array;

	index = 0;
	str = (char *)str;
	strlen = ft_strlen(s);
	str = ft_calloc((word_count(str, c) + 1), sizeof(char *));
	if (!str)
		return ('\0');
	while (index < strlen)
	{
		str = '';
		index++;
	}
}
