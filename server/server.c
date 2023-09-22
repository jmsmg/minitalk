/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:13:55 by seonggoc          #+#    #+#             */
/*   Updated: 2023/09/22 08:07:41 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_error(int err)
{
	if (err == SIG_FAIL)
		ft_putstr_fd("Signal Error");
	if (err == PID_FAIL)
		ft_putstr_fd("getpid fail", 1);
	exit(1);
}

void	handler(int signum)
{
	if (signum == SIGUSR1)
	{

	}
	else if (signum == SIGUSR2)
	{

	}

	ft_putstr_fd("signal!", 1);
	ft_putnbr_fd(signum, 1);
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
	if (signal(SIGUSR1, handler) == SIG_ERR
		|| signal(SIGUSR2, handler) == SIG_ERR)
		ft_error(SIG_FAIL);
	while (1)
		pause();
	exit(0);
}
