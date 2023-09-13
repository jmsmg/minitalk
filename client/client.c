/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:27:13 by seonggoc          #+#    #+#             */
/*   Updated: 2023/09/13 15:20:48 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char *argv[])
{
	int		pid;
	char	message;

	if (argc != 3)
	{
		ft_putstr_fd("fail", 1);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 2 && 32768 < pid)
		return (1);
	message = argv[2];

}
