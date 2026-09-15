#include "minishell.h"

static int	is_n_option(const char *str)
{
	size_t	i;

	if (str[0] != '-' || str[1] != 'n')
		return (0);
	i = 2;
	while (str[i] == 'n')
		i++;
	return (str[i] == '\0');
}

int	builtin_echo(char **argv)
{
	size_t	i;
	int		newline;

	i = 1;
	newline = 1;
	while (argv[i] && is_n_option(argv[i]))
	{
		newline = 0;
		i++;
	}
	while (argv[i])
	{
		if (write_string(1, argv[i]) != 0)
			return (1);
		if (argv[i + 1] && write_string(1, " ") != 0)
			return (1);
		i++;
	}
	if (newline && write_string(1, "\n") != 0)
		return (1);
	return (0);
}