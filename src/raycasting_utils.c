/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielagentil <gabrielagentil@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 09:56:52 by gabrielagen       #+#    #+#             */
/*   Updated: 2023/01/18 10:03:51 by gabrielagen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_player_pos_dir(t_data *dt, t_ray *ray)
{
	ray->ray_pos_x = dt->player_x;
	ray->ray_pos_y = dt->player_y;
	ray->ray_dir_x = dt->pdir_x;
	ray->ray_dir_y = dt->pdir_y;
}