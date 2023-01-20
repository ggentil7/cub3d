/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:22:51 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/18 16:28:47 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_player_pos_dir(t_data *dt) 
{
	dt->ray->pos_x = dt->player_x;
	dt->ray->pos_y = dt->player_y;
	dt->ray->ray_dir_x = dt->pdir_x;
	dt->ray->ray_dir_y = dt->pdir_y;
}

void	calcul_ray_pos_dir(t_data *dt) //calculate ray position and direction
{
	int	x;

	x = 0;
	dt->ray->hit = 0;
	dt->ray->perp_wall_dist = 0;
	dt->ray->camera_x = 2 * x / (double)WIN_X - 1;
	dt->ray->ray_dir_x = dt->ray->dir_x + dt->ray->plane_x * dt->ray->camera_x;
	dt->ray->ray_dir_y = dt->ray->dir_y + dt->ray->plane_y * dt->ray->camera_x;
	dt->ray->map_x = (int)dt->ray->pos_x; //which box of the map we're in
	dt->ray->map_y = (int)dt->ray->pos_y; //which box of the map we're in
	dt->ray->delta_dist_x = fabs(1 / dt->ray->ray_dir_x);
	dt->ray->delta_dist_y = fabs(1 / dt->ray->ray_dir_y);
}

void	init_ray(t_data *dt) //x and y start position, initial direction vector, the 2d raycaster version of camera plane
{
	dt->ray->pos_x = 22;
	dt->ray->pos_y = 12;
	dt->ray->dir_x = -1;
	dt->ray->dir_y = 0;
	dt->ray->plane_x = 0;
	dt->ray->plane_y = 0.66;
}

void	calcul_step_init_sidedist(t_data *dt) //calculate step and initial sideDist
{
	double	delta_dist_x;
	double	delta_dist_y;

	delta_dist_x = dt->ray->delta_dist_x;
	delta_dist_y = dt->ray->delta_dist_y;
	if (dt->ray->ray_dir_x < 0)
	{
		dt->ray->step_x = -1;
		dt->ray->side_dist_x = (dt->ray->pos_x - dt->ray->map_x) * delta_dist_x;
	}
	else
	{
		dt->ray->step_x = 1;
		dt->ray->side_dist_x = (dt->ray->map_x + 1.0 - dt->ray->pos_x) * delta_dist_x;
	}
	if (dt->ray->ray_dir_y < 0)
	{
		dt->ray->step_y = -1;
		dt->ray->side_dist_y = (dt->ray->pos_y - dt->ray->map_y) * delta_dist_y;
	}
	else
	{
		dt->ray->step_y = 1;
		dt->ray->side_dist_y = (dt->ray->map_y + 1.0 - dt->ray->pos_y) * delta_dist_y;
	}
}
