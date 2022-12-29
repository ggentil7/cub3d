/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:41:12 by mthiesso          #+#    #+#             */
/*   Updated: 2022/12/29 15:40:03 by ggentil          ###   ########.fr       */
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
	hc[1] = "101111011";
	hc[2] = "111111101";
	hc[3] = "111111101";
	hc[4] = "111111101";
	hc[5] = "111111101";
	hc[6] = "111111101";
	hc[7] = "101111011";
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
		my_square_pixel(dt, i, j, 0x000000FF);
	else if(c == '0')
		my_square_pixel(dt, i, j, 0xAAAAAA);
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

void	my_pixel(t_data *dt, int x, int y, int color)
{
	char	*dst;

	dst = dt->img->path + (y * dt->img->line + x * (dt->img->bytes / 8));
	*(unsigned int*)dst = color;
}
