/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:42:27 by mthiesso          #+#    #+#             */
/*   Updated: 2023/01/26 17:40:09 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	perform_dda(t_data *dt)
{
	while (dt->ray->hit == 0)
	{
		if (dt->ray->side_dist_x < dt->ray->side_dist_y)
		{
			dt->ray->side_dist_x += dt->ray->delta_dist_x;
			dt->ray->map_x += dt->ray->step_x;
			dt->ray->side = 0;
		}
		else
		{
			dt->ray->side_dist_y += dt->ray->delta_dist_y;
			dt->ray->map_y += dt->ray->step_y;
			dt->ray->side = 1;
		}
		hit_wall(dt);
	}
}

int	raycasting(t_data *dt)
{
	int	x;

	x = 0;
	while (x < WIN_X)
	{
		init_player_pos_dir(dt);
		calcul_ray_pos_dir(dt, x);
		calcul_side_distance(dt);
		perform_dda(dt);
		calcul_perp_distance(dt);
		calcul_stripe_to_fill(dt);
		draw_ver_line(dt, x);
		x++;
	}
	return (0);
}

int	which_color(t_data *dt, int x, int i)
{
	if (dt->ray->side == 0 && dt->ray->ray_dir_x > 0)
		my_pixel(dt, x, i, RED);
	else if (dt->ray->side == 0 && dt->ray->ray_dir_x < 0)
		my_pixel(dt, x, i, GREEN);
	else if (dt->ray->side == 1 && dt->ray->ray_dir_y < 0)
		my_pixel(dt, x, i, YEL);
	else if (dt->ray->side == 1 && dt->ray->ray_dir_y > 0)
		my_pixel(dt, x, i, BLU);
	return (0);
}

// void	side_coloring(t_data *dt)
// {
	
// }