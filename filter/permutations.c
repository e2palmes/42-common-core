#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char    *str;
char    *result;
int     *used;
int     len;

size_t ft_strlen (char *str)
{
	size_t i;

	if (!str)
		return (0);
	i = 0;
	while(str[i])
		i++;
	return i;
}

void swap (char *c1, char *c2)
{
	char tmp;
	tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

char *sort(char *str, int len)
{
	int i = 0;
	int j = 0;

	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (str[i] > str[j])
				swap(&str[i], &str[j]);
			j++;
		}
		i++;
	}
	return (str);
}

void solve(int pos)
{
	int i;

	if (pos == len)
	{
		puts(result);
		return;
	}
	i = 0;
	while (i < len)
	{
		if (!used[i])
		{
			result[pos] = str[i];
			used[i] = 1;
			solve(pos + 1);
			used[i] = 0;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (-1);
	str = argv[1];
	if (str == NULL)
		return (0);
	len = strlen(argv[1]);
	str = sort(argv[1], len);
	
	result = malloc(len + 1);
	if (!result)
		return (-1);
	result[len] = '\0';

    used = calloc(len, sizeof(int));
    if (!used)
    {
        free(result);
        return (-1);
    }

	solve(0);
	free(result);
	free(used);
	return (0);
}
