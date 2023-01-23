/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 09:56:52 by gabrielagen       #+#    #+#             */
/*   Updated: 2023/01/23 20:43:49 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	screen_display(t_data *dt)
{
	// printf("coucou\n");
	dt->img->img = mlx_new_image(dt->mlx, WIN_X, WIN_Y);
	dt->img->path = mlx_get_data_addr(dt->img->img, &dt->img->bytes,
			&dt->img->line, &dt->img->end);
	// where_is_middle(dt);
	raycasting(dt);
	minimap_display(dt);
	mlx_put_image_to_window(dt->mlx, dt->window, dt->img->img, 0, 0);
	mlx_destroy_image(dt->mlx, dt->img->img);
	return (0);
}

void	hit_wall(t_data *dt) //Check if ray has hit a wall
{
	// int	x;
	// int	y;

	// x = dt->ray->map_x;
	// y = dt->ray->map_y;
	printf("ray map x: %d\n", dt->ray->map_x);
	printf("ray map y: %d\n", dt->ray->map_y);
	if (dt->map[dt->ray->map_x][dt->ray->map_y] > 0)
		{
			dt->ray->hit = 1;
		}
}

void	calcul_perp_distance(t_data *dt)
{
	printf("side = %d\n", dt->ray->side);
	printf("side y = %f\n", dt->ray->side_dist_y);
	printf("delta y = %f\n", dt->ray->delta_dist_y);
	if (dt->ray->side == 0)
		dt->ray->perp_wall_dist = (dt->ray->side_dist_x - dt->ray->delta_dist_x);
	else
		dt->ray->perp_wall_dist = (dt->ray->side_dist_y - dt->ray->delta_dist_y);
}

void	calcul_stripe_to_fill(t_data *dt) //calculate lowest and highest pixel to fill in current stripe
{
	dt->line = malloc(sizeof(t_line));
	printf("perp2 = %f\n", dt->ray->perp_wall_dist);
	dt->line->height = (WIN_Y / dt->ray->perp_wall_dist);
	printf("line height = %d\n", dt->line->height);
	dt->line->drawstart = (dt->line->height / -2) + WIN_Y / 2;
	if (dt->line->drawstart < 0)
		dt->line->drawstart = 0;
	dt->line->drawend = (dt->line->height / 2) + WIN_Y / 2;
	if (dt->line->drawend >= WIN_Y)
		dt->line->drawend = WIN_Y - 1;
}

int	draw_ver_line(t_data *dt, int x)
{
	int	i;
	int	start;
	int	end;

	i = -1;
	start = dt->line->drawstart;
	end = dt->line->drawend;
	printf("perp wall dist = %f\n", dt->ray->perp_wall_dist);
	printf("start = %d\n", dt->line->drawstart);
	printf("end = %d\n", dt->line->drawend);
	// exit (0);
	while (++i < start)
		my_pixel(dt, x, i, SKY);
	while (start < end)
		start++;
	while (++start < (WIN_Y - 1))
	{
		// printf("x = %d\n", x);
		// printf("start = %d\n", start);
		my_pixel(dt, x, start, GRE);
	}
	return (0);
}
