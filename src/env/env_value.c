/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 16:55:11 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/20 01:03:02 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

const char	*env_value(char **env, const char *name, size_t len)
{
	size_t	i;
	size_t	j;

	if (len == 0)
		return ("");
	i = 0;
	while (env && env[i])
	{
		j = 0;
		while (j < len && env[i][j] && env[i][j] == name[j])
			j++;
		if (j == len && env[i][j] == '=')
			return (env[i] + j + 1);
		i++;
	}
	return ("");
}
