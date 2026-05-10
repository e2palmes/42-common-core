/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:11:44 by ediba-de          #+#    #+#             */
/*   Updated: 2026/02/01 14:50:07 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_printupperhex(unsigned long nb);
int	ft_printlowerhex(unsigned long nb);
int	ft_printpointer(void *s);
int	ft_printdecimal(int n);
int	ft_printunsigneddecimal(unsigned int n);
int	ft_format_arg(va_list args, char flag);

#endif
