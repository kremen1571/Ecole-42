/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 13:03:15 by klaronda          #+#    #+#             */
/*   Updated: 2020/08/30 13:03:17 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils/libft/libft.h"

int	main(int argc, char *argv[])
{
	t_ptr	*ptr;

	ptr = ft_init_ptr();
	ft_check_args(&argc, argv);
	ft_parse(argv[1], ptr);
	//printf("%s", ptr->map.map[10]);
	
   //Расчет и вывод результата работы функции tan
    //printf ("tanf : %f \n", tanf(1.59));
   //printf ("tan  : %.20f \n", tanf(3.14000001));
	setbeforestart(ptr);
	init_game(ptr);
	mlx_get_textures(ptr);
	ft_mlx_start(ptr);
	ft_free(ptr);
	return (0);
}
