/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:29:32 by ediba-de          #+#    #+#             */
/*   Updated: 2025/12/01 19:02:55 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c >= 32 && c < 127);
}
/*
#include <stdio.h>
#include <ctype.h>

int     main(void)
{
        printf("isprint: %d\n", isprint(127));
        printf("ft_isprintt: %d\n", ft_isprint(127));
}
*/
