/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:18:41 by ialvarez          #+#    #+#             */
/*   Updated: 2022/03/09 19:55:15 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	writting(int pid, char br)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (((br >> i++) & 0x01) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	pid = 0;
	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
			writting(pid, argv[2][i++]);
		writting(pid, '\0');
	}
	return (0);
}
