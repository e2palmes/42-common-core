#include "minishell.h"

static void	print_tokens(t_token *token)
{
	while (token)
	{
		printf("type=%d value=[%s]\n", (int)token->type,
			token->value);
		token = token->next;
	}
}

static void	lexer_error(int status, t_shell *shell)
{
	shell->exit_status = status;
	if (status == 2)
		write(2, "minishell: unclosed quote\n", 26);
	else
		perror("minishell");
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
		print_tokens(tokens);
	tokens_free(tokens);
}

static void	shell_loop(t_shell *shell)
{
	char	*line;

	while (1)
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
