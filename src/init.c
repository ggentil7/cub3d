/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:47:23 by mthiesso          #+#    #+#             */
/*   Updated: 2023/01/04 16:53:41 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_game(t_data *dt)
{
	//dt = malloc(sizeof (t_data));
	dt->img = ft_calloc(1, sizeof(t_imgptr));
	dt->mlx = mlx_init();
	dt->window = mlx_new_window(dt->mlx, WIN_X, WIN_Y, "TBD");
	dt->img->img = mlx_new_image(dt->mlx, WIN_X, WIN_Y);
	dt->img->path = mlx_get_data_addr(dt->img->img, &dt->img->bytes, &dt->img->line, &dt->img->end);
	return(0);
}

int	init_asset(t_asset *asset)
{
	asset->id = 0;
	asset->path = 0;
	asset->r = 0;
	asset->g = 0;
	asset->b = 0;
	return (0);
}
