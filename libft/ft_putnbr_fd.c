/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:34:23 by ediba-de          #+#    #+#             */
/*   Updated: 2025/11/28 18:34:27 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-nbr, fd);
	}
	else if (nbr < 10)
		ft_putchar_fd(nbr + 48, fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((nbr % 10) + 48, fd);
	}
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	printf("test ft_putnbr_fd: ");
	int fd = open("test_putnbr_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd < 0)
	{
		perror("open");
		return 1;
	}

	ft_putnbr_fd(0, fd);

        close(fd);

        printf("File 'test_putnbr_fd.txt' written. Check its content.\n");

        return 0;
}*/
