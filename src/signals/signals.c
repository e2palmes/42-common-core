/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 01:44:20 by ediba-de          #+#    #+#             */
/*   Updated: 2026/09/20 01:44:23 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_signal = 0;

static void	prompt_handler(int signo)
{
	int	saved_errno;

	saved_errno = errno;
	g_signal = signo;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	errno = saved_errno;
}

static void	record_handler(int signo)
{
	g_signal = signo;
}

void	signals_prompt(void)
{
	signal(SIGINT, prompt_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	signals_wait(void)
{
	signal(SIGINT, record_handler);
	signal(SIGQUIT, record_handler);
}

void	signals_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
