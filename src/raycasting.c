/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:42:27 by mthiesso          #+#    #+#             */
/*   Updated: 2023/01/20 14:32:17 by mthiesso         ###   ########.fr       */
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
			dt->ray->map_x += dt->ray->step_x;
			dt->ray->side = 1;
		}
		hit_wall(dt);
	}
}

int	raycasting(t_data *dt)
{
	int	x;

	x = -1;
	while (++x < WIN_X)
	{
		calcul_ray_pos_dir(dt);
		calcul_step_init_sidedist(dt);
		perform_dda(dt);
	}
	return (0);
}
