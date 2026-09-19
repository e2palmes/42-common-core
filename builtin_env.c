/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                 +#+             +#+        */
/*   Created: 2026/09/18 16:55:11 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/18 16:55:11 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_env(t_shell *shell)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (shell->env[i])
	{
		j = 0;
		while (shell->env[i][j] && shell->env[i][j] != '=')
			j++;
		if (shell->env[i][j] == '=')
		{
			if (write_string(1, shell->env[i]) != 0
				|| write_string(1, "\n") != 0)
				return (1);
		}
		i++;
	}
	return (0);
}