/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielagentil <gabrielagentil@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:44:44 by ggentil           #+#    #+#             */
/*   Updated: 2022/12/27 09:51:44 by gabrielagen      ###   ########.fr       */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	dt;
	(void)	argc;
	(void)	argv;
	
	ft_bzero(&dt, sizeof(t_data));
	init_game(&dt);
	//error_args(argc, argv);
	mlx_loop_hook(dt.mlx, screen_display, &dt);
	mlx_loop(dt.mlx);
}
