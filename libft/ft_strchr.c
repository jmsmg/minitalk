/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:29:41 by seonggoc          #+#    #+#             */
/*   Updated: 2023/03/16 19:44:02 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	tmp;

	tmp = c;
	i = 0;
	while (s[i] && s[i] != tmp)
	{
		i++;
	}
	if (!(s[i]) && tmp != '\0')
	{
		return (0);
	}
	return ((char *)s + i);
}
