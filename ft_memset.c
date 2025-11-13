void	*memset(void *dest, int value, unsigned int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		dest[index] = value;
		index++;
	}
}
