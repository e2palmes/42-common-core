/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 16:55:11 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/20 01:02:58 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_for_exec(char **env)
{
	char	**result;
	size_t	i;
	size_t	j;

	i = 0;
	while (env[i])
		i++;
	result = malloc(sizeof(char *) * (i + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (env[i])
	{
		if (env[i][env_key_len(env[i])] == '=')
			result[j++] = env[i];
		i++;
	}
	result[j] = NULL;
	return (result);
}
