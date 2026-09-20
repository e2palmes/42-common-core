/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_file_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 01:05:59 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/20 01:06:01 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_hd_template(char *path)
{
	const char	*template;
	size_t		i;

	template = "/tmp/minishell_hd_00000000";
	i = 0;
	while (template[i])
	{
		path[i] = template[i];
		i++;
	}
	path[i] = '\0';
}

int	heredoc_open_error(int *read_fd, int write_fd)
{
	int	error;

	error = errno;
	close(*read_fd);
	close(write_fd);
	*read_fd = -1;
	errno = error;
	return (-1);
}
