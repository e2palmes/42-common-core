/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 16:55:11 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/20 01:04:54 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	expand_command(t_cmd *command, t_shell *shell)
{
	t_token	*word;
	t_token	*fields;
	t_token	*result;

	word = command->words;
	result = NULL;
	while (word)
	{
		if (expand_word(word->value, shell, &fields) != 0)
		{
			tokens_free(result);
			return (1);
		}
		if (fields)
			token_add(&result, fields);
		word = word->next;
	}
	tokens_free(command->words);
	command->words = result;
	return (0);
}

int	expand_words(t_cmd *commands, t_shell *shell)
{
	while (commands)
	{
		if (expand_command(commands, shell) != 0)
			return (1);
		commands = commands->next;
	}
	return (0);
}
