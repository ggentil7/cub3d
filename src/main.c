/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:44:44 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/15 17:53:23 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	dt;

	(void) argc;
	ft_bzero(&dt, sizeof(t_data));
	//error_args(argc, argv);
	if (errorminator(&dt, &argv[1]) == EXIT_FAILURE)
	{
		ft_printf("Error\n");
		return (EXIT_FAILURE);
	}
	mlx_loop_hook(dt.mlx, screen_display, &dt);
	//mlx_hook(dt.window, 17, 0, &exit_game, &dt);
	//mlx_hook(dt.window, 2, 1L << 0, where_to_go, &dt);
	//mlx_loop(dt.mlx);
	return (EXIT_SUCCESS);
}
