/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:41:12 by mthiesso          #+#    #+#             */
/*   Updated: 2023/01/04 13:35:27 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	minimap_display(t_data *dt)
{
	(void) dt;
	char	**hc;
	int		i = 0;
	int		j = 0;

	hc = malloc(sizeof(char *) * 10);
	dt->x_map = 9;
	dt->y_map = 9;
	while (i < 9)
	{
		hc[i] = malloc(sizeof(char) * 10);
		i++;
	}
	hc[0] = "111111111";
	hc[1] = "100000011";
	hc[2] = "101111001";
	hc[3] = "101000001";
	hc[4] = "101111101";
	hc[5] = "100000001";
	hc[6] = "100011101";
	hc[7] = "100P00011";
	hc[8] = "111111111";
	hc[9] = NULL;
	i = 0;
	while (i < dt->y_map)
	{
		j = 0;
		while (j < dt->x_map)
		{
			minimap_printer(dt, i, j, hc[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}

void	minimap_printer(t_data *dt, int i, int j, char c)
{
	if(c == '1')
		my_square_pixel(dt, i, j, BLU);
	else if(c == '0')
		my_square_pixel(dt, i, j, GRE);
	else if (c == 'P')
		my_player_pixel(dt, i, j, RED);
	else
		my_square_pixel(dt, i, j, BLU);
}

void	my_square_pixel(t_data *dt, int x, int y, int color)
{
	int	pos_x;
	int	pos_y;

	pos_x = x * MAP_SIZE;

	while(pos_x < ((x + 1) * MAP_SIZE))
	{
		pos_y = y * MAP_SIZE;
		while(pos_y < ((y + 1)  * MAP_SIZE))
		{
			my_pixel(dt, pos_x, pos_y, color);
			pos_y++;
		}
		pos_x++;
	}
}

void	my_player_pixel(t_data *dt, int x, int y, int color)
{
	int	pos_x;
	int	pos_y;

	pos_x = x * 10;

	while(pos_x < ((x + 1) * 10))
	{
		pos_y = y * 10;
		while(pos_y < ((y + 1)  * 10))
		{
			my_pixel(dt, pos_x, pos_y, color);
			pos_y++;
		}
		pos_x++;
	}
}

void	my_pixel(t_data *dt, int x, int y, int color)
{
	char	*dst;

	dst = dt->img->path + (y * dt->img->line + x * (dt->img->bytes / 8));
	*(unsigned int*)dst = color;
}
