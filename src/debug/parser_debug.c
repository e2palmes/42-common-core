/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 16:55:11 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/20 01:08:42 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_command_content(t_cmd *command)
{
	size_t	i;
	t_token	*redir;

	i = 0;
	while (command->argv[i])
	{
		printf("  argv[%zu]=[%s]\n", i, command->argv[i]);
		i++;
	}
	printf("  argv[%zu]=NULL\n", i);
	redir = command->redirs;
	while (redir)
	{
		printf("  redir type=%d target=[%s] flags=%d\n",
			(int)redir->type, redir->value, redir->flags);
		redir = redir->next;
	}
}

void	print_commands(t_cmd *commands)
{
	int	i;

	i = 1;
	while (commands)
	{
		printf("command %d\n", i);
		print_command_content(commands);
		commands = commands->next;
		i++;
	}
}
