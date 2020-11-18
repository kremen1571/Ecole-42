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
		newlst = NULL;
		headnew = NULL;
		while (lst)
		{
			newlst = ft_lstnew((f)(lst->content));
			if (!newlst)
			{
				ft_lstclear(&headnew, del);
				return (NULL);
			}
			ft_lstadd_back(&headnew, newlst);
			lst = lst->next;
		}
		return (headnew);
	}
	return (NULL);
}
