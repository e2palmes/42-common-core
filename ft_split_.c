/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:46:52 by ediba-de          #+#    #+#             */
/*   Updated: 2025/11/28 21:22:07 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	word_count(const char *str, char c)
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

static char	*fill_word(char **array, int index, const char *s, int start, int end)
{
	int	i;

	array[index] = malloc(sizeof(char) * (end - start));
	if(!array[index])
		return ('\0');
	i = 0;
	while (start < end)
	{
		array[index][i++] = s[start++];
	}
	array[index][i] = '\0';
	return (array[index]);
}

/*static void	init_vars(int *i; int *start, int *count)
{
	*i = 0;
	*start = -1;
	*count = 0;
}
*/
static void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	int	i;
	int	start;
	int	count;
	char	**array;
	char	*res;

	//init_vars(&i, &start, &count);

	i = 0;
	start = -1;
	count = 0;
	array = malloc((word_count(s, c)) * sizeof(char *) + 1);
	if (!array)
		return ('\0');
	while (s[i])
	{
		if (s[i] != c && start < 0)
			start = i;
		if (start >= 0 && s[i] == c)
		{
			res = fill_word(array, count, s, start, i);
			if(!res)
				free_array(array);
			count++;
			start = -1;
		}
		i++;
	}
	return (array);
}
/*
#include <stdio.h>

int main(void)
{
	char str[] = ",Bonjour,tout,le,,monde,,";
	char **arr = ft_split(str, ',');

	int	i = 0;
	while (arr[i])
	{
		printf("%s-", arr[i]);
		i++;
	}
}*/
