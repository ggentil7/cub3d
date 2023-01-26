/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:42:27 by mthiesso          #+#    #+#             */
/*   Updated: 2023/01/26 15:10:17 by mthiesso         ###   ########.fr       */
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
	// 	printf("side_dist_x = %f\n", dt->ray->side_dist_x);
	// 	printf("side_dist_y = %f\n", dt->ray->side_dist_y);
	// 	printf("delta_dist_x = %f\n", dt->ray->delta_dist_x);
	// 	printf("delta_dist_y = %f\n", dt->ray->delta_dist_y);
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
