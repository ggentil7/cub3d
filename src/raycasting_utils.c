/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 09:56:52 by gabrielagen       #+#    #+#             */
/*   Updated: 2023/01/18 16:36:45 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	screen_display(t_data *dt)
{
	dt->img->img = mlx_new_image(dt->mlx, WIN_X, WIN_Y);
	dt->img->path = mlx_get_data_addr(dt->img->img, &dt->img->bytes,
			&dt->img->line, &dt->img->end);
	minimap_display(dt);
	mlx_put_image_to_window(dt->mlx, dt->window, dt->img->img, 0, 0);
	mlx_destroy_image(dt->mlx, dt->img->img);
	return (0);
}

void	hit_wall(t_data *dt) //Check if ray has hit a wall
{
	int	x;
	int	y;

	x = dt->ray->map_x;
	y = dt->ray->map_y;
	if (dt->map[x][y] > 0)
		dt->ray->hit = 1;
}

double	calcul_perp_distance(t_data *dt)
{
	if (dt->ray->side == 0)
		return (dt->ray->perp_wall_dist = (dt->ray->side_dist_x - dt->ray->delta_dist_x));
	else
		return (dt->ray->perp_wall_dist = (dt->ray->side_dist_y - dt->ray->delta_dist_y));
}
