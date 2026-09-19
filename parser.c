/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                 +#+             +#+        */
/*   Created: 2026/09/18 16:55:11 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/18 16:55:11 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	fill_command(t_token **tokens, t_cmd *command)
{
	t_token			*source;
	t_token			*new;
	t_token_type	type;

	while (*tokens && (*tokens)->type != TOKEN_PIPE)
	{
		type = (*tokens)->type;
		source = *tokens;
		if (type != TOKEN_WORD)
			source = source->next;
		new = token_copy(source, type);
		if (new == NULL)
			return (1);
		if (type == TOKEN_WORD)
			token_add(&command->words, new);
		else
			token_add(&command->redirs, new);
		*tokens = source->next;
	}
	return (0);
}

int	parser(t_token *tokens, t_cmd **commands)
{
	t_cmd	*current;

	*commands = NULL;
	if (tokens == NULL)
		return (0);
	current = command_new();
	*commands = current;
	while (current)
	{
		if (fill_command(&tokens, current) != 0)
			break ;
		if (tokens == NULL)
			return (0);
		tokens = tokens->next;
		current->next = command_new();
		current = current->next;
	}
	commands_free(*commands);
	*commands = NULL;
	return (1);
}