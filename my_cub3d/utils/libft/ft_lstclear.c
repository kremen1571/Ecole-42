/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 17:34:02 by klaronda          #+#    #+#             */
/*   Updated: 2020/05/18 17:34:05 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;

	if (lst && del)
	{
		if (*lst)
		{
			while (*lst)
			{
				temp = (*lst)->next;
				del((*lst)->content);
				free(*lst);
				*lst = temp;
			}
		}
		lst = NULL;
	}
}
