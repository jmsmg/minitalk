/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:13:55 by seonggoc          #+#    #+#             */
/*   Updated: 2023/09/19 16:23:14 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handler(int signum)
{
	static volatile	sig_atomic_t	g_signal;
	ft_putstr_fd("signal!", 1);
	ft_putnbr_fd(signum, 1);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	if (pid == -1)
	{
		ft_putstr_fd("getpid fail", 1);
		return (1);
	}
	ft_putstr_fd("pid :", 1);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
		pause();
	}
}
