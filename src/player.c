/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:33:33 by mthiesso          #+#    #+#             */
/*   Updated: 2023/01/17 17:15:17 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	player_display(t_data *dt)
{
	pixel_player(dt);
	ray_display(dt);
}

void	pixel_player(t_data *dt)
{
	int	pos_x;
	int	pos_y;
	int	size;

	size = 0;
	pos_y = ((dt->ppos_y - 0.5) * MAP_SIZE) + (MAP_SIZE / 10 * 3);
	while (pos_y < ((dt->ppos_y - 0.5) * MAP_SIZE) + (MAP_SIZE / 10 * 7))
	{
		pos_x = ((dt->ppos_x - 0.5) * MAP_SIZE) + (MAP_SIZE / 10 * 3);
		while (pos_x < ((dt->ppos_x - 0.5) * MAP_SIZE) + (MAP_SIZE / 10 * 7))
		{
			my_pixel(dt, pos_x, pos_y, RED);
			pos_x++;
		}
		pos_y++;
	}
}

void	init_dir_player(t_data *dt)
{
	if (dt->player_direction == 'N')
	{
		dt->pdir_x = 0;
		dt->pdir_y = -1;
	}
	else if (dt->player_direction == 'S')
	{
		dt->pdir_x = 0;
		dt->pdir_y = 1;
	}
	else if (dt->player_direction == 'E')
	{
		dt->pdir_x = 1;
		dt->pdir_y = 0;
	}
	else if (dt->player_direction == 'W')
	{
		dt->pdir_x = -1;
		dt->pdir_y = 0;
	}
}

void	ray_display(t_data *dt)
{
	float	pos_x;
	float	pos_y;
	int		i;

	i = 0;
	pos_x = dt->ppos_x + dt->pdir_x * SPEED;
	pos_y = dt->ppos_y + dt->pdir_y * SPEED;
	while (i < 10)
	{
		pos_x += dt->pdir_x * SPEED;
		pos_y += dt->pdir_y * SPEED;
		if (dt->map[(int)pos_y][(int)pos_x] == '1')
			return ;
		my_pixel(dt, pos_x * MAP_SIZE, pos_y * MAP_SIZE, GREEN);
		i++;
	}
}
