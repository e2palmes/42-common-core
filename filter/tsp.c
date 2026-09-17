#include <math.h>

typedef struct s_city
{
	float	x;
	float	y;
}	t_city;

float	dist(t_city a, t_city b)
{
	float	dx;
	float	dy;

	dx = a.x - b.x;
	dy = a.y - b.y;
	return (sqrtf(dx * dx + dy * dy));
}

void	swap(t_city *a, t_city *b)
{
	t_city	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	solve(t_city *cities, int size, int pos,
		float current, float *best)
{
	int		i;
	float	d;

	if (current >= *best)
		return ;
	if (pos == size)
	{
		current += dist(cities[size - 1], cities[0]);
		if (current < *best)
			*best = current;
		return ;
	}
	i = pos;
	while (i < size)
	{
		swap(&cities[pos], &cities[i]);

		d = dist(cities[pos - 1], cities[pos]);

		solve(cities, size, pos + 1,
			current + d, best);

		swap(&cities[pos], &cities[i]);
		i++;
	}
}

float	tsp(t_city *cities, int size)
{
	float	best;
	int		i;

	if (size <= 1)
		return (0);

	/*
	** On prend le trajet dans l'ordre actuel
	** comme première valeur de best.
	*/
	best = 0;
	i = 0;
	while (i < size - 1)
	{
		best += dist(cities[i], cities[i + 1]);
		i++;
	}
	best += dist(cities[size - 1], cities[0]);

	/*
	** cities[0] reste fixe.
	** On permute seulement cities[1..size-1].
	*/
	solve(cities, size, 1, 0, &best);

	return (best);
}
