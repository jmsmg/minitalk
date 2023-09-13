/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:20:30 by seonggoc          #+#    #+#             */
/*   Updated: 2023/03/16 20:12:39 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	tmp;

	tmp = c;
	i = ft_strlen(s);
	while (0 <= i)
	{
		if (tmp == s[i])
		{
			return ((char *)s + i);
		}
		i--;
	}
	return (0);
}
