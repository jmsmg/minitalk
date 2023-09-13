/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:35:21 by seonggoc          #+#    #+#             */
/*   Updated: 2023/03/24 15:02:44 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_d;
	unsigned char	*tmp_s;

	tmp_d = (unsigned char *)dst;
	tmp_s = (unsigned char *)src;
	if (src < dst)
	{
		while (0 < len)
		{
			tmp_d[len - 1] = tmp_s[len - 1];
			len--;
		}
		return (dst);
	}
	else
	{
		return (ft_memcpy(dst, src, len));
	}
}
