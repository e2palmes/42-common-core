#include <stdio.h>

char	*str;

void	solve(int index, int balance, int rm_open, int rm_close)
{
	char	save;

	if (str[index] == '\0')
	{
		if (balance == 0 && rm_open == 0 && rm_close == 0)
			puts(str);
		return ;
	}

	save = str[index];

	if (str[index] == '(')
	{
		/* supprimer '(' */
		if (rm_open > 0)
		{
			str[index] = ' ';
			solve(index + 1, balance, rm_open - 1, rm_close);
			str[index] = save;
		}

		/* garder '(' */
		solve(index + 1, balance + 1, rm_open, rm_close);
	}
	else if (str[index] == ')')
	{
		/* supprimer ')' */
		if (rm_close > 0)
		{
			str[index] = ' ';
			solve(index + 1, balance, rm_open, rm_close - 1);
			str[index] = save;
		}

		/* garder ')' seulement si un '(' est ouvert */
		if (balance > 0)
			solve(index + 1, balance - 1, rm_open, rm_close);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	open;
	int	rm_close;

	if (argc != 2)
		return (1);

	str = argv[1];
	i = 0;
	open = 0;
	rm_close = 0;

	while (str[i])
	{
		if (str[i] == '(')
			open++;
		else if (str[i] == ')')
		{
			if (open > 0)
				open--;
			else
				rm_close++;
		}
		i++;
	}

	solve(0, 0, open, rm_close);
	return (0);
}
