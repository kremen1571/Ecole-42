/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 10:48:21 by jrosemar          #+#    #+#             */
/*   Updated: 2020/05/25 22:56:54 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *head;
	t_list *cp;

	if (!(*lst))
		return ;
	head = *lst;
	while (head)
	{
		cp = head;
		head = head->next;
		del(cp->content);
		free(cp);
	}
	*lst = NULL;
}
