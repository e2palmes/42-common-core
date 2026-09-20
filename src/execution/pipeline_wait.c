/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_wait.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 01:09:45 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/20 01:09:55 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	stop_started(t_cmd *commands)
{
	while (commands)
	{
		if (commands->pid > 0)
			kill(commands->pid, SIGKILL);
		commands = commands->next;
	}
}

int	pipeline_wait(t_cmd *commands, int failed)
{
	int	status;

	if (failed)
		stop_started(commands);
	status = 0;
	while (commands)
	{
		if (commands->pid > 0)
			status = wait_child(commands->pid);
		commands = commands->next;
	}
	if (failed)
		return (1);
	return (status);
}
