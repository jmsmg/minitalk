/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 01:30:55 by seonggoc          #+#    #+#             */
/*   Updated: 2023/03/23 14:58:46 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_except_zero(char *tmp)
{
	if (!tmp)
	{
		return (0);
	}
	tmp[0] = '0';
	tmp[1] = '\0';
	return (tmp);
}

static int	ft_check_size(int n)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*ft_rec(int n, char *tmp, int size)
{
	if (n == 0)
	{
		return (tmp);
	}
	else
	{
		if (n < 0)
		{
			tmp[size] = -(n % 10) + '0';
		}
		else
		{
			tmp[size] = n % 10 + '0';
		}
		return (ft_rec(n / 10, tmp, size - 1));
	}
}

char	*ft_itoa(int n)
{
	int		size;
	char	*tmp;

	size = ft_check_size(n);
	if (n == 0)
	{
		tmp = (char *)malloc(sizeof(char) * 2);
		return (ft_except_zero(tmp));
	}
	else if (n < 0)
	{
		tmp = (char *)malloc(sizeof(char) * size + 1 + 1);
		size++;
	}
	else
		tmp = (char *)malloc(sizeof(char) * size + 1);
	if (!tmp)
		return (0);
	tmp[0] = '-';
	tmp[size] = '\0';
	return (ft_rec(n, tmp, size - 1));
}
