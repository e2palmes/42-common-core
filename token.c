/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                 +#+             +#+        */
/*   Created: 2026/09/18 16:55:11 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/18 16:55:11 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*token_slice(char *str, size_t len)
{
	char	*copy;
	size_t	i;

	copy = malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

t_token	*token_new(char *str, size_t len, t_token_type type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	token->value = token_slice(str, len);
	if (token->value == NULL)
	{
		free(token);
		return (NULL);
	}
	token->type = type;
	token->flags = 0;
	token->heredoc_fd = -1;
	token->next = NULL;
	return (token);
}

void	token_add(t_token **tokens, t_token *new)
{
	t_token	*last;

	if (*tokens == NULL)
	{
		*tokens = new;
		return ;
	}
	last = *tokens;
	while (last->next)
		last = last->next;
	last->next = new;
}

void	tokens_free(t_token *tokens)
{
	t_token	*next;

	while (tokens)
	{
		next = tokens->next;
		if (tokens->heredoc_fd != -1)
			close(tokens->heredoc_fd);
		free(tokens->value);
		free(tokens);
		tokens = next;
	}
}