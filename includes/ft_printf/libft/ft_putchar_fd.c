/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:41:58 by ediba-de          #+#    #+#             */
/*   Updated: 2025/11/27 14:55:53 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	printf("Test stdout: ");

	int fd = open("test_putchar.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("open");
		return 1;
	}

	ft_putchar_fd('X', fd);
	ft_putchar_fd('Y', fd);
	ft_putchar_fd('Z', fd);
	ft_putchar_fd('\n', fd);

	close(fd);

    	printf("File 'test_putchar.txt' written. Check its content.\n");

    	return 0;
}*/
