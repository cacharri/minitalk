/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:19:51 by ialvarez          #+#    #+#             */
/*   Updated: 2022/03/07 21:16:50 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char *str_add_one(char q)
{
	char *add;

	add = (char *)malloc(sizeof(char) * 2);
	if (!add)
		return (NULL);
	add[0] = q;
	add[1] = '\0';
	return (add);
}

static char *str_add(char *uwu, char q)
{
	char	*add;
	int		i;

	if (!q)
		return (NULL);
	if (!uwu)
		return (str_add_one(q));
	add = (char *)malloc(sizeof(char) * (ft_strlen(uwu) + 2));
	if (!add)
	{
		free(uwu);
		return (NULL);
	}
	i = 0;
	while (uwu[i++])
		add[i] = uwu[i];
	free(uwu);
	add[i] = q;
	add[++i] = '\0';
	return (add);
}

static char *print(char *mes)
{
	ft_putstr_fd(mes, 1);
	free(mes);
	return (NULL);
}

void send_pid(int a, siginfo_t *t, void *lux)
{
	static int lock;
	static char c;
	static int bit;
	int pid;
	static char *write;

	(void)lux;
	c = 0xFF;
	pid = t->si_pid;
	if (a == SIGUSR1)
		c ^= 0x80 >> bit;
	else if (a == SIGUSR2)
		c |= 0x80 >> bit;
	if (++bit == 8)
	{
		if (c)
			write = str_add(write, c);
		else
			write = print(write);
		bit = 0;
		c = 0xFF;
	}
}

int	main(void)
{

	struct sigaction	sig;
	sigset_t			block;

	sigemptyset(&block);
	sigaddset(&block, SIGINT);
	sigaddset(&block, SIGQUIT);
	sig.sa_handler = 0;
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = send_pid;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
	return (0);
}
