#include "minishell.h"

static void	print_command_content(t_cmd *command)
{
	size_t	i;
	t_token	*redir;

	i = 0;
	while (command->argv[i])
	{
		printf("  argv[%zu]=[%s]\n", i, command->argv[i]);
		i++;
	}
	printf("  argv[%zu]=NULL\n", i);
	redir = command->redirs;
	while (redir)
	{
		printf("  redir type=%d target=[%s] flags=%d\n",
			(int)redir->type, redir->value, redir->flags);
		redir = redir->next;
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