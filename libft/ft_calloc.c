/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:26:48 by ediba-de          #+#    #+#             */
/*   Updated: 2025/12/02 18:00:19 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*temp;
	size_t			i;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	temp = malloc(nmemb * size);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		temp[i] = '\0';
		i++;
	}
	return (temp);
}

/*
int main()
{
    int *students;
    int numStudents = 12;
    students = ft_calloc(numStudents, sizeof(*students));
    printf("%d", numStudents * sizeof(*students));
}*/
