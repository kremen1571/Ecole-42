/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:03:15 by klaronda          #+#    #+#             */
/*   Updated: 2021/04/04 16:03:16 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	print_error(void)
{
	printf("\033[1;31m");
	printf("%s\n", "number of philosophers less then 2 or bigger then 200");
	printf("%s\n", "Args not a number");
	printf("%s\n", "time to die, or time to eat, or time to sleep less 60 ms");
}
