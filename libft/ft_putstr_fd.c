/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:59:12 by ediba-de          #+#    #+#             */
/*   Updated: 2025/11/27 16:02:51 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, sizeof(*s));
		s++;
	}
}
/*
#include <fcntl.h>
#include <stdio.h>

int     main(void)
{
        printf("Test stdout: ");

        int fd = open("test_putchar.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd < 0)
        {
                perror("open");
                return 1;
        }

        ft_putstr_fd("ABdeC\n", fd);

        close(fd);

        printf("File 'test_putchar.txt' written. Check its content.\n");

        return 0;
}*/
