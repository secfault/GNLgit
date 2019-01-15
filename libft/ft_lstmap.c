/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 20:17:54 by dtony             #+#    #+#             */
/*   Updated: 2018/12/17 16:29:28 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*ret;
	t_list	*begin;

	if (lst && f)
	{
		temp = f(lst);
		if (!(ret = ft_lstnew(temp->content, temp->content_size)))
			return (NULL);
		begin = ret;
		lst = lst->next;
		while (lst)
		{
			temp = f(lst);
			if (!(ret->next = ft_lstnew(temp->content, temp->content_size)))
				return (NULL);
			ret = ret->next;
			lst = lst->next;
		}
		return (begin);
	}
	return (NULL);
}
