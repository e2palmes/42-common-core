#include <stdlib.h>
#include <stdio.h>

int *subset;
int *set;
int target;
int size;
int subset_size;

void print_subset()
{
	int i = 0;
	while (i < subset_size)
	{
		if (i > 0)
			printf(" ");
		printf("%d", subset[i]);
		i++;
	}
	printf("\n");
}

void solve(int index, int sum)
{
	if (index == size && subset_size > 0)
	{
		if (sum == target)
			print_subset();
		return;
	}

	subset[subset_size] = set[index];
	subset_size++;
	solve(index + 1, set[index] + sum);
	subset_size--;
	solve(index + 1, sum);
}

int main (int argc, char **argv)
{
	int i;
	if (argc < 2)
		return (1);
	size = argc - 2;
	if (size <= 0)
		return (0);
	set = malloc(size * sizeof(int));
	if (!set)
		return (1);
	i = 0;
	while (i < size)
	{
		set[i] = atoi(argv[i + 2]);
		i++;
	}
	target = atoi(argv[1]);
	subset = malloc(size * sizeof(int));
	if (!subset)
	{
		free(set);
		return (1);
	}
	subset_size = 0;
	solve(0, 0);
	free(subset);
	free(set);
	return (0);
}
