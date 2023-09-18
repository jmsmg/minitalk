/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:13:55 by seonggoc          #+#    #+#             */
/*   Updated: 2023/09/18 17:21:41 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handler(int signum)
{
	ft_putstr_fd("signal!", 1);
	ft_putnbr_fd(signum, 1);
}

int	main(void)
{
	int	pid;

	ft_putstr_fd("pid :", 1);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, handler);
	while (1)
	{
		sleep(1);
	}
}
