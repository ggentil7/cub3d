/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:44:44 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/04 16:44:22 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	dt;
	t_asset	asset;

	(void) argc;
	(void) argv;
	// ft_bzero(&dt, sizeof(t_data));
	// init_game(&dt);
	error_args(argc, argv);
	read_map(&dt, &asset);
	// mlx_loop_hook(dt.mlx, screen_display, &dt);
	// mlx_loop(dt.mlx);
}
