/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                 +#+             +#+        */
/*   Created: 2026/09/18 16:55:11 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/18 16:55:11 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_value(const char *value)
{
	char	one[2];

	one[1] = '\0';
	while (*value)
	{
		if (*value == '"' || *value == '\\'
			|| *value == '$' || *value == '`')
		{
			if (write_string(1, "\\") != 0)
				return (1);
		}
		one[0] = *value++;
		if (write_string(1, one) != 0)
			return (1);
	}
	return (0);
}

static int	print_entry(char *entry)
{
	size_t	len;
	int		has_value;

	len = env_key_len(entry);
	has_value = (entry[len] == '=');
	entry[len] = '\0';
	if (write_string(1, "declare -x ") || write_string(1, entry))
		return (1);
	if (has_value)
	{
		if (write_string(1, "=\"") || print_value(entry + len + 1)
			|| write_string(1, "\""))
			return (1);
	}
	return (write_string(1, "\n"));
}

int	export_list(t_shell *shell)
{
	char	**copy;
	size_t	i;
	int		status;

	copy = env_sorted(shell->env);
	if (copy == NULL)
	{
		perror("minishell: export");
		return (1);
	}
	i = 0;
	status = 0;
	while (copy[i] && status == 0)
		status = print_entry(copy[i++]);
	env_free(copy);
	return (status);
}