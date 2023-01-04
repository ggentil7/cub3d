/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:44:44 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/04 11:23:20 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	dt;

	(void) argc;
	(void) argv;
	ft_bzero(&dt, sizeof(t_data));
	init_game(&dt);
	//error_args(argc, argv);
	mlx_loop_hook(dt.mlx, screen_display, &dt);
	mlx_hook(dt.window, 17, 0, &exit_game, &dt);
	mlx_loop(dt.mlx);
}
