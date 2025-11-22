/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:26:48 by ediba-de          #+#    #+#             */
/*   Updated: 2025/11/22 11:01:32 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char 	*temp;
	size_t			i;

	temp = malloc(nmemb * size);
	if (!temp)
		return ('\0');
	i = 0;
	while(i < nmemb * size)
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
