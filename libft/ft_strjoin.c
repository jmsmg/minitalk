/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:51:26 by seonggoc          #+#    #+#             */
/*   Updated: 2023/03/21 17:29:37 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	size;
	char	*tmp;

	size = ft_strlen(s1) + ft_strlen(s2);
	tmp = (char *)malloc(size + 1);
	if (!tmp)
	{
		return (0);
	}
	tmp[0] = 0;
	ft_strlcat(tmp, s1, size + 1);
	i = ft_strlen(s1);
	ft_strlcat(&tmp[i], s2, size + 1);
	return (tmp);
}
