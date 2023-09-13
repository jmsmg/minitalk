/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:22:45 by seonggoc          #+#    #+#             */
/*   Updated: 2023/03/21 13:31:46 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_check_size(char const *s, unsigned int start, size_t len)
{
	size_t	size;

	size = (size_t)ft_strlen(s);
	if (size <= start)
	{
		return (0);
	}
	else if (size <= start + len)
	{
		return (size - start);
	}
	else
	{
		return (len);
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;
	size_t	size;

	size = ft_check_size(s, start, len);
	tmp = (char *)malloc(size + 1);
	if (!tmp)
	{
		return (0);
	}
	i = 0;
	while (i < size)
	{
		tmp[i] = s[start];
		start++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
