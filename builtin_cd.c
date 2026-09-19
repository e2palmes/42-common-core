/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                 +#+             +#+        */
/*   Created: 2026/09/18 16:55:11 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/18 16:55:11 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static const char	*cd_target(char **argv, t_shell *shell)
{
	const char	*name;
	int			index;
	size_t		len;

	if (argv[1] && !(argv[1][0] == '-' && argv[1][1] == '\0'))
		return (argv[1]);
	name = "HOME";
	if (argv[1])
		name = "OLDPWD";
	len = env_key_len(name);
	index = env_index(shell->env, name, len);
	if (index < 0 || shell->env[index][len] != '=')
	{
		write_string(2, "minishell: cd: ");
		write_string(2, name);
		write_string(2, " not set\n");
		return (NULL);
	}
	return (shell->env[index] + len + 1);
}

static int	cd_update(t_shell *shell, char *oldpwd, int display)
{
	char	*newpwd;
	int		status;

	newpwd = getcwd(NULL, 0);
	if (newpwd == NULL)
	{
		perror("minishell: cd: getcwd");
		return (1);
	}
	status = env_set_value(shell, "OLDPWD", oldpwd);
	if (status == 0)
		status = env_set_value(shell, "PWD", newpwd);
	if (status != 0)
		perror("minishell: cd");
	else if (display)
		status = (write_string(1, newpwd) || write_string(1, "\n"));
	free(newpwd);
	return (status);
}

int	builtin_cd(char **argv, t_shell *shell)
{
	const char	*target;
	char		*oldpwd;
	int			status;

	if (argv[1] && argv[2])
		return (exec_message("cd", "too many arguments", 1));
	target = cd_target(argv, shell);
	if (target == NULL)
		return (1);
	oldpwd = getcwd(NULL, 0);
	if (oldpwd == NULL)
		oldpwd = env_strdup(env_value(shell->env, "PWD", 3));
	if (oldpwd == NULL)
		return (exec_message("cd", "allocation failed", 1));
	if (chdir(target) == -1)
	{
		perror("minishell: cd");
		free(oldpwd);
		return (1);
	}
	status = cd_update(shell, oldpwd, argv[1] && argv[1][0] == '-'
			&& argv[1][1] == '\0');
	free(oldpwd);
	return (status);
}