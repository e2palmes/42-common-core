/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                 +#+             +#+        */
/*   Created: 2026/09/18 16:55:11 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/18 16:55:11 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	test_variable(t_shell *shell, const char *input)
{
	char	*value;
	size_t	consumed;

	value = expand_variable(shell, input, &consumed);
	if (value == NULL)
	{
		perror("test expansion");
		return ;
	}
	printf("%s -> [%s], consumed=%zu\n", input, value, consumed);
	free(value);
}

int	main(void)
{
	t_shell	shell;
	char	*env[4];

	env[0] = "USERNAME=autre";
	env[1] = "USER=manu";
	env[2] = "EMPTY=";
	env[3] = NULL;
	shell.env = env;
	shell.exit_status = 2;
	test_variable(&shell, "$USER");
	test_variable(&shell, "$USER/test");
	test_variable(&shell, "$EMPTY");
	test_variable(&shell, "$INCONNUE");
	test_variable(&shell, "$?");
	test_variable(&shell, "$");
	return (0);
}