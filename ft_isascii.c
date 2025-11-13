int	ft_isascii(int c)
{
	return (!(c && c >= 0 && c < 128));
}
