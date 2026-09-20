/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 01:05:21 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/20 01:05:22 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_redirect(int source, int target)
{
	while (dup2(source, target) == -1)
	{
		if (errno != EINTR)
		{
			perror("minishell: dup2");
			return (1);
		}
	}
	return (0);
}

int	save_stdio(int saved[2])
{
	saved[0] = dup(0);
	if (saved[0] == -1)
	{
		perror("minishell: dup");
		return (1);
	}
	saved[1] = dup(1);
	if (saved[1] == -1)
	{
		perror("minishell: dup");
		close(saved[0]);
		return (1);
	}
	return (0);
}

int	restore_stdio(int saved[2])
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < 2)
	{
		if (fd_redirect(saved[i], i) != 0)
			status = 1;
		close(saved[i]);
		i++;
	}
	return (status);
}
