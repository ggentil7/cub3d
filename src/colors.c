/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:21:26 by mthiesso          #+#    #+#             */
/*   Updated: 2023/01/22 18:55:50 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	where_is_middle(t_data *dt)
{
	int	hori_line;
	int	x;
	int	y;

	hori_line = WIN_Y / 2;
	x = 0;
	while (x < WIN_X)
	{
		y = 0;
		while (y < hori_line)
		{
			my_pixel(dt, x, y, SKY);
			y++;
		}
		x++;
	}
	x = 0;
	while (x < WIN_X)
	{
		y = hori_line;
		while (y < WIN_Y)
		{
			my_pixel(dt, x, y, GRE);
			y++;
		}
		x++;
	}
	return (0);
}
