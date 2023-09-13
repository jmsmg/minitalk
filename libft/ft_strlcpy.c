/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:48:27 by seonggoc          #+#    #+#             */
/*   Updated: 2023/03/27 14:00:56 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] && i < dstsize - 1 && 0 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize)
	{
		dst[i] = '\0';
	}
	while (src[j])
	{
		j++;
	}
	return (j);
}
