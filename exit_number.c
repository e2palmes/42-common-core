#include "minishell.h"

static int	exit_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

static int	read_magnitude(const char **str, unsigned long long limit,
		unsigned long long *number)
{
	unsigned int	digit;

	*number = 0;
	if (**str < '0' || **str > '9')
		return (1);
	while (**str >= '0' && **str <= '9')
	{
		digit = **str - '0';
		if (*number > (limit - digit) / 10)
			return (1);
		*number = *number * 10 + digit;
		(*str)++;
	}
	return (0);
}

int	exit_number(const char *str, int *status)
{
	unsigned long long	number;
	int					negative;

	while (exit_space(*str))
		str++;
	negative = (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	if (read_magnitude(&str, (unsigned long long)LLONG_MAX + negative,
			&number) != 0)
		return (1);
	while (exit_space(*str))
		str++;
	if (*str != '\0')
		return (1);
	*status = number % 256;
	if (negative)
		*status = (256 - *status) % 256;
	return (0);
}