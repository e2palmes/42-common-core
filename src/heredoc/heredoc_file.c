/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 01:06:07 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/20 01:06:10 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	heredoc_name(char *path, unsigned int number)
{
	size_t	i;
	int		digits;

	i = 0;
	while (path[i])
		i++;
	digits = 8;
	while (digits > 0)
	{
		path[--i] = "0123456789abcdef"[number % 16];
		number /= 16;
		digits--;
	}
}

static int	heredoc_create(char *path)
{
	unsigned int	attempt;
	int				fd;

	attempt = 0;
	while (attempt < 4096)
	{
		heredoc_name(path, attempt);
		fd = open(path, O_WRONLY | O_CREAT | O_EXCL, 0600);
		if (fd != -1 || errno != EEXIST)
			return (fd);
		attempt++;
	}
	errno = EEXIST;
	return (-1);
}

int	heredoc_open(int *read_fd)
{
	char	path[64];
	int		write_fd;
	int		error;

	copy_hd_template(path);
	write_fd = heredoc_create(path);
	if (write_fd == -1)
		return (-1);
	*read_fd = open(path, O_RDONLY);
	if (*read_fd == -1)
	{
		error = errno;
		unlink(path);
		close(write_fd);
		errno = error;
		return (-1);
	}
	if (unlink(path) == -1)
		return (heredoc_open_error(read_fd, write_fd));
	return (write_fd);
}
