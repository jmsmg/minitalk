/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:13:55 by seonggoc          #+#    #+#             */
/*   Updated: 2023/09/22 11:42:53 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_error(int err)
{
	if (err == SIG_FAIL)
		ft_putstr_fd("Signal Error", 1);
	if (err == PID_FAIL)
		ft_putstr_fd("getpid fail", 1);
	exit(1);
}

void	handler(int signum)
{
	static int	i;
	static char	tmp;

	if (signum == SIGUSR1)
	{
		tmp |= 0;
		if (i < 7)
			tmp <<= 1;
	}
	else if (signum == SIGUSR2)
	{
		tmp |= 1;
		if (i < 7)
			tmp <<= 1;
	}
	i++;
	if (i == 8)
	{
		write(1, &tmp, 1);
		i = 0;
		tmp = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	if (pid == -1)
		ft_error(PID_FAIL);
	ft_putstr_fd("pid :", 1);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	exit(0);
}
