/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                 +#+             +#+        */
/*   Created: 2026/09/18 16:55:11 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/18 16:55:11 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	name_equal(const char *a, const char *b)
{
	size_t	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (a[i] == b[i]);
}
static int	run_env_builtin(char **argv, t_shell *shell)
{
	if (name_equal(argv[0], "env"))
	{
		if (argv[1])
			return (exec_message("env", "too many arguments", 1));
		return (builtin_env(shell));
	}
	if (name_equal(argv[0], "export"))
		return (builtin_export(argv, shell));
	if (name_equal(argv[0], "unset"))
		return (builtin_unset(argv, shell));
	return (-1);
}

int	is_builtin(const char *name)
{
	return (name_equal(name, "echo")
		|| name_equal(name, "pwd")
		|| name_equal(name, "env")
		|| name_equal(name, "export")
		|| name_equal(name, "unset")
		|| name_equal(name, "cd")
		|| name_equal(name, "exit"));
}

int	run_builtin(t_cmd *command, t_shell *shell)
{
	char	**argv;

	argv = command->argv;
	if (name_equal(argv[0], "echo"))
		return (builtin_echo(argv));
	if (name_equal(argv[0], "pwd"))
		return (builtin_pwd());
	if (name_equal(argv[0], "cd"))
		return (builtin_cd(argv, shell));
	if (name_equal(argv[0], "exit"))
		return (builtin_exit(argv, shell));
	return (run_env_builtin(argv, shell));
}
