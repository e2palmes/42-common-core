/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                 +#+             +#+        */
/*   Created: 2026/09/18 16:55:11 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/18 16:55:11 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	valid_identifier(const char *str)
{
	size_t	i;

	if (!((str[0] >= 'a' && str[0] <= 'z')
			|| (str[0] >= 'A' && str[0] <= 'Z') || str[0] == '_'))
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= '0' && str[i] <= '9') || str[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

static int	export_invalid(const char *arg)
{
	write_string(2, "minishell: export: `");
	write_string(2, arg);
	write_string(2, "': not a valid identifier\n");
	return (1);
}

int	builtin_export(char **argv, t_shell *shell)
{
	size_t	i;
	int		status;

	if (argv[1] == NULL)
		return (export_list(shell));
	i = 1;
	status = 0;
	while (argv[i])
	{
		if (!valid_identifier(argv[i]))
			status = export_invalid(argv[i]);
		else if (env_set(shell, argv[i]) != 0)
		{
			perror("minishell: export");
			return (1);
		}
		i++;
	}
	return (status);
}