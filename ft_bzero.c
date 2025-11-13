void	ft_bzero(void *s, unsigned int n)
{
	 int	index;

	 index = 0;
	 while (index < n)
	 {
		 s[index] = '\0';
		 index++;
	 }
}
