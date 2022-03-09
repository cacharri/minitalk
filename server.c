/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:19:51 by ialvarez          #+#    #+#             */
/*   Updated: 2022/03/09 20:01:14 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_count = 0;

static void	copy(int bit)
{
	static char	x;

	if (g_count == 0)
		x = 0;
	x += bit << g_count;
	g_count++;
	if (g_count == 8)
	{
		ft_putstr_fd(&x, 1);
		if (x == '\0')
			ft_putstr_fd("\n", 1);
		g_count = 0;
	}
}

static	void	handle(int sig)
{
	if (sig == 30)
		copy(0);
	if (sig == 31)
		copy(1);
}

int	main(void)
{
	struct sigaction	sig;
	sigset_t			block;

	sigemptyset(&block);
	sigaddset(&block, SIGINT);
	sigaddset(&block, SIGQUIT);
	sig.sa_handler = &handle;
	sig.sa_flags = SA_SIGINFO;
	sig.sa_mask = block;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
}
