/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                 +#+             +#+        */
/*   Created: 2026/09/18 16:55:11 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/18 16:55:11 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*path_join(const char *dir, size_t len, const char *name)
{
	char	*path;
	size_t	i;
	size_t	j;

	if (len == 0)
		return (env_strdup(name));
	i = 0;
	while (name[i])
		i++;
	path = malloc(len + i + 2);
	if (path == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		path[i] = dir[i];
		i++;
	}
	path[i++] = '/';
	j = 0;
	while (name[j])
		path[i++] = name[j++];
	path[i] = '\0';
	return (path);
}

static int	try_directory(t_cmd *command, t_shell *shell,
		const char **path)
{
	size_t	len;
	char	*candidate;
	int		error;

	len = 0;
	while ((*path)[len] && (*path)[len] != ':')
		len++;
	candidate = path_join(*path, len, command->argv[0]);
	if (candidate == NULL)
		return (ENOMEM);
	execve(candidate, command->argv, shell->env);
	error = errno;
	free(candidate);
	*path += len;
	return (error);
}

int	exec_search(t_cmd *command, t_shell *shell)
{
	const char	*path;
	int			error;
	int			denied;

	path = env_value(shell->env, "PATH", 4);
	denied = 0;
	while (1)
	{
		error = try_directory(command, shell, &path);
		if (error == EACCES)
			denied = 1;
		else if (error != ENOENT && error != ENOTDIR)
			return (exec_error(command->argv[0], error));
		if (*path == '\0')
			break ;
		path++;
	}
	if (denied)
		return (exec_error(command->argv[0], EACCES));
	return (exec_message(command->argv[0], "command not found", 127));
}
