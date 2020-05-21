/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 17:56:17 by klaronda          #+#    #+#             */
/*   Updated: 2020/05/18 17:56:18 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*headnew;

	if (lst && f && del)
	{
		newlst = ft_lstnew(lst->content);
		if (!newlst)
			return (NULL);
		headnew = newlst;
		while (lst->next != NULL)
		{
			lst = lst->next;
			newlst = headnew;
			ft_lstadd_back(&newlst, ft_lstnew(lst->content));
		}
		newlst = headnew;
		while (newlst)
		{
			f(newlst->content);
			newlst = newlst->next;
		}
		return (headnew);
	}
	return (NULL);
}
