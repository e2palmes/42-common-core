/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                 +#+             +#+        */
/*   Created: 2026/09/18 16:55:11 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/18 16:55:11 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	has_slash(const char *str)
{
	while (*str)
	{
		if (*str == '/')
			return (1);
		str++;
	}
	return (0);
}

static int	exec_direct(t_cmd *command, t_shell *shell)
{
	struct stat	info;

	if (stat(command->argv[0], &info) == 0 && S_ISDIR(info.st_mode))
		return (exec_message(command->argv[0], "Is a directory", 126));
	execve(command->argv[0], command->argv, shell->env);
	return (exec_error(command->argv[0], errno));
}

int	exec_external(t_cmd *command, t_shell *shell)
{
	t_shell	child;
	int		status;

	if (command->argv[0][0] == '\0')
		return (exec_message("", "command not found", 127));
	child = *shell;
	child.env = env_for_exec(shell->env);
	if (child.env == NULL)
	{
		perror("minishell");
		return (1);
	}
	if (has_slash(command->argv[0]))
		status = exec_direct(command, &child);
	else
		status = exec_search(command, &child);
	free(child.env);
	return (status);
}