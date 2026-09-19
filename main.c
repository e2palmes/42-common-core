/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                 +#+             +#+        */
/*   Created: 2026/09/18 16:55:11 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/18 16:55:11 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



static void	lexer_error(int status, t_shell *shell)
{
	shell->exit_status = status;
	if (status == 2)
	write(2, "minishell: unclosed quote\n", 26);
	else
	perror("minishell");
}

static void	process_tokens(t_token *tokens, t_shell *shell)
{
	t_cmd	*commands;

	if (parser(tokens, &commands) != 0)
	{
		perror("minishell");
		shell->exit_status = 1;
		return ;
	}
	if (prepare_commands(commands, shell) != 0)
	{
		perror("minishell");
		shell->exit_status = 1;
	}
	else
		shell->exit_status = execute_commands(commands, shell);
	commands_free(commands);
}

static void	execute_line(char *line, t_shell *shell)
{
	t_token	*tokens;
	int		status;

	status = lexer(line, &tokens);
	if (status != 0)
	{
		lexer_error(status, shell);
		return ;
	}
	status = syntax_check(tokens);
	if (status != 0)
		shell->exit_status = status;
	else
		process_tokens(tokens, shell);
	tokens_free(tokens);
}

static void	shell_loop(t_shell *shell)
{
	char	*line;

	while (shell->should_exit == 0)
	{
		line = readline("minishell$ ");
		if (line == NULL)
		{
			printf("exit\n");
			break ;
		}
		if (line[0] != '\0')
		{
			add_history(line);
			execute_line(line, shell);
		}
		free(line);
	}
	rl_clear_history();
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argc;
	(void)argv;
	shell.exit_status = 0;
	shell.should_exit = 0;
	shell.env = env_copy(envp);
	if (shell.env == NULL)
	{
		perror("minishell");
		return (1);
	}
	shell_loop(&shell);
	env_free(shell.env);
	return (shell.exit_status);
}
