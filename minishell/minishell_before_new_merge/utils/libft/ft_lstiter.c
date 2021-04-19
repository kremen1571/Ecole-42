/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 12:26:55 by jrosemar          #+#    #+#             */
/*   Updated: 2020/05/25 12:30:12 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *head;

	head = lst;
	if (!lst)
		return ;
	while (head->next != NULL)
	{
		f(head->content);
		head = head->next;
	}
	f(head->content);
}
