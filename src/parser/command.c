/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 16:55:11 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/20 03:21:58 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*command_new(void)
{
	t_cmd	*command;

	command = malloc(sizeof(t_cmd));
	if (command == NULL)
		return (NULL);
	command->words = NULL;
	command->redirs = NULL;
	command->argv = NULL;
	command->pid = 0;
	command->next = NULL;
	return (command);
}

void	commands_free(t_cmd *commands)
{
	t_cmd	*next;

	while (commands)
	{
		next = commands->next;
		free(commands->argv);
		tokens_free(commands->words);
		tokens_free(commands->redirs);
		free(commands);
		commands = next;
	}
}

t_token	*token_copy(t_token *source, t_token_type type)
{
	size_t	len;

	len = 0;
	while (source->value[len])
		len++;
	return (token_new(source->value, len, type));
}
