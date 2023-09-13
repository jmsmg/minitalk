/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:27:48 by seonggoc          #+#    #+#             */
/*   Updated: 2023/03/27 13:46:32 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new_lst;
	t_list	*tail;
	void	*ptr;

	new_lst = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = lst->next;
		ptr = f(lst->content);
		tail = ft_lstnew(ptr);
		if (!tail)
		{
			del(ptr);
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, tail);
		lst = tmp;
	}
	return (new_lst);
}
