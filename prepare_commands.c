#include "minishell.h"

static int	build_argv(t_cmd *command)
{
	t_token	*word;
	size_t	i;

	i = 0;
	word = command->words;
	while (word)
	{
		i++;
		word = word->next;
	}
	command->argv = malloc(sizeof(char *) * (i + 1));
	if (command->argv == NULL)
		return (1);
	i = 0;
	word = command->words;
	while (word)
	{
		command->argv[i++] = word->value;
		word = word->next;
	}
	command->argv[i] = NULL;
	return (0);
}

int	prepare_commands(t_cmd *commands, t_shell *shell)
{
	if (expand_words(commands, shell) != 0)
		return (1);
	while (commands)
	{
		if (expand_redirs(commands->redirs, shell) != 0)
			return (1);
		if (build_argv(commands) != 0)
			return (1);
		commands = commands->next;
	}
	return (0);
}