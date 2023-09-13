/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 01:27:51 by seonggoc          #+#    #+#             */
/*   Updated: 2023/03/22 12:38:11 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_recur(int n, int fd)
{
	if (n <= 9)
	{
		ft_putchar(n + '0', fd);
	}
	else
	{
		ft_recur(n / 10, fd);
		ft_putchar(n % 10 + '0', fd);
	}
}

static void	ft_putnbr(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		ft_putchar('-', fd);
		n = -n;
		ft_recur(n, fd);
	}
	else
	{
		ft_recur(n, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}
