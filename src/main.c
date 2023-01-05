/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:44:44 by ggentil           #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	dt;
	t_asset	asset;

	(void) argc;
	ft_bzero(&dt, sizeof(t_data));
	init_game(&dt);
	//error_args(argc, argv);
	read_map(&dt, &argv[1]);
	mlx_loop_hook(dt.mlx, screen_display, &dt);
	mlx_hook(dt.window, 17, 0, &exit_game, &dt);
	mlx_hook(dt.window, 2, 1L << 0, where_to_go, &dt);
	mlx_loop(dt.mlx);
}


