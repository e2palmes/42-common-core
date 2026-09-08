#include "minishell.h"

static void	print_command_content(t_cmd *command)
{
	t_token	*token;

	token = command->words;
	while (token)
	{
		printf("  word=[%s]\n", token->value);
		token = token->next;
	}
	token = command->redirs;
	while (token)
	{
		printf("  redir type=%d target=[%s]\n",
			(int)token->type, token->value);
		token = token->next;
	}
}

void	print_commands(t_cmd *commands)
{
	int	i;

	i = 1;
	while (commands)
	{
		printf("command %d\n", i);
		print_command_content(commands);
		commands = commands->next;
		i++;
	}
}