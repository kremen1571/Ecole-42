/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 13:50:10 by jrosemar          #+#    #+#             */
/*   Updated: 2020/05/27 23:50:48 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *head;

	if (!new)
		return ;
	head = *lst;
	if (!(*lst))
		*lst = new;
	else
	{
		while (head->next != NULL)
			head = head->next;
		head->next = new;
	}
}
