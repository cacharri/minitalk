/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:19:51 by ialvarez          #+#    #+#             */
/*   Updated: 2022/03/03 20:48:41 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_pid()

int	main(void)
{

	struct sigaction	sig;
	char a;

	a = getpid();
	write(1, "The server PID is: ", 19);
	write(1, (void *)sizeof(a), ft_strlen(&a));
	sig.sa_sigaction = send_pid;
	while (1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
	return (0);
}
