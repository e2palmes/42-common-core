/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                 +#+             +#+        */
/*   Created: 2026/09/18 16:55:11 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/18 16:55:11 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	name_order(const char *a, const char *b)
{
	while (*a && *a != '=' && *a == *b)
	{
		a++;
		b++;
	}
	if (*a == '\0' || *a == '=')
	{
		if (*b == '\0' || *b == '=')
			return (0);
		return (-1);
	}
	if (*b == '\0' || *b == '=')
		return (1);
	return ((unsigned char)*a - (unsigned char)*b);
}

static void	swap_entries(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char	**env_sorted(char **env)
{
	char	**copy;
	size_t	i;
	size_t	j;

	copy = env_copy(env);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (copy[i])
	{
		j = i + 1;
		while (copy[j])
		{
			if (name_order(copy[i], copy[j]) > 0)
				swap_entries(&copy[i], &copy[j]);
			j++;
		}
		i++;
	}
	return (copy);
}