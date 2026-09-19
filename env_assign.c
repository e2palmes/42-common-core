/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_assign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                 +#+             +#+        */
/*   Created: 2026/09/18 16:55:11 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/18 16:55:11 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*make_assignment(const char *name, const char *value)
{
	char	*entry;
	size_t	len;
	size_t	i;
	size_t	j;

	len = env_key_len(name);
	j = 0;
	while (value[j])
		j++;
	entry = malloc(len + j + 2);
	if (entry == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		entry[i] = name[i];
		i++;
	}
	entry[i++] = '=';
	j = 0;
	while (value[j])
		entry[i++] = value[j++];
	entry[i] = '\0';
	return (entry);
}

int	env_set_value(t_shell *shell, const char *name, const char *value)
{
	char	*entry;
	int		status;

	entry = make_assignment(name, value);
	if (entry == NULL)
		return (1);
	status = env_set(shell, entry);
	free(entry);
	return (status);
}