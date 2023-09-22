/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:27:13 by seonggoc          #+#    #+#             */
/*   Updated: 2023/09/22 11:35:26 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_error(int err)
{
	if (err == ARG_ERR)
		ft_putstr_fd("Arguments Error", 1);
	else if (PID_ERR)
		ft_putstr_fd("Pid Error", 1);
	else if (PERMISSION_ERR)
		ft_putstr_fd("Permssion Denied", 1);
	else if (MALLOC_ERR)
		ft_putstr_fd("Malloc Fail", 1);
	exit(1);
}

void	connect_signal(pid_t pid, char c)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < 8)
	{
		tmp = c >> (7 - i) & 1;
		if (tmp == 0)
			kill(pid, SIGUSR1);
		else if (tmp == 1)
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
	usleep(200);
}

int	check_permission(pid_t pid)
{
	int	ret;

	ret = kill(pid, 0);
	if (ret)
		return (1);
	return (0);
}

void	send_signal(pid_t pid, char *msg)
{
	int	i;
	int	len;

	if (check_permission(pid))
		ft_error(PERMISSION_ERR);
	msg = ft_strjoin(msg, "\n");
	if (!msg)
		ft_error(MALLOC_ERR);
	i = 0;
	len = ft_strlen(msg);
	while (i < len)
	{
		connect_signal(pid, msg[i]);
		i++;
	}
	free(msg);
	msg = NULL;
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*msg;

	if (argc != 3)
		ft_error(ARG_ERR);
	pid = ft_atoi(argv[1]);
	if (pid < 2 || 99998 < pid)
		ft_error(PID_ERR);
	msg = argv[2];
	send_signal(pid, msg);
	exit(0);
}
