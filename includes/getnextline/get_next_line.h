/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:38:05 by ediba-de          #+#    #+#             */
/*   Updated: 2026/03/06 16:42:56 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

#include "../ft_printf/libft/libft.h"

char	*ft_strdup(const char *s);
char	*ft_strchr(const char *str, int c);
char	*set_stash(int fd, char *stash);
char	*_get_line(char *stash);
char	*update_stash(char *stash);
char	*get_next_line(int fd);

#endif
