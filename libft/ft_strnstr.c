/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:55:12 by seonggoc          #+#    #+#             */
/*   Updated: 2023/03/27 14:36:56 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;

	i = 0;
	n_len = 0;
	if (haystack[0] == '\0' && needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	while (needle[n_len])
	{
		n_len++;
	}
	while (haystack[i] && i <= len)
	{
		if (ft_strcmp(haystack + i, needle) && n_len <= (len - i))
		{
			return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}
