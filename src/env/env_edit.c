/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_edit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 16:55:11 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/20 01:02:55 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	env_key_len(const char *entry)
{
	size_t	len;

	len = 0;
	while (entry[len] && entry[len] != '=')
		len++;
	return (len);
}

int	env_index(char **env, const char *name, size_t len)
{
	int		i;
	size_t	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (j < len && env[i][j] && env[i][j] == name[j])
			j++;
		if (j == len && (env[i][j] == '=' || env[i][j] == '\0'))
			return (i);
		i++;
	}
	return (-1);
}

static int	env_append(t_shell *shell, char *entry)
{
	char	**new;
	size_t	i;

	i = 0;
	while (shell->env[i])
		i++;
	new = malloc(sizeof(char *) * (i + 2));
	if (new == NULL)
		return (1);
	i = 0;
	while (shell->env[i])
	{
		new[i] = shell->env[i];
		i++;
	}
	new[i++] = entry;
	new[i] = NULL;
	free(shell->env);
	shell->env = new;
	return (0);
}

int	env_set(t_shell *shell, const char *entry)
{
	size_t	len;
	int		index;
	char	*copy;

	len = env_key_len(entry);
	index = env_index(shell->env, entry, len);
	if (index >= 0 && entry[len] == '\0')
		return (0);
	copy = env_strdup(entry);
	if (copy == NULL)
		return (1);
	if (index >= 0)
	{
		free(shell->env[index]);
		shell->env[index] = copy;
		return (0);
	}
	if (env_append(shell, copy) == 0)
		return (0);
	free(copy);
	return (1);
}
