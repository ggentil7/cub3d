/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:44:44 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/09 17:14:05 by mthiesso         ###   ########.fr       */
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
	init_asset(&asset);
	//error_args(argc, argv);
	if (read_map(&dt, &asset, &argv[1]) == -1)
		return (EXIT_FAILURE);
	mlx_loop_hook(dt.mlx, screen_display, &dt);
	mlx_hook(dt.window, 17, 0, &exit_game, &dt);
	mlx_hook(dt.window, 2, 1L << 0, where_to_go, &dt);
	mlx_loop(dt.mlx);
	return (EXIT_SUCCESS);
}
