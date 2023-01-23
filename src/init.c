/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:05:46 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/23 17:42:55 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_game(t_data *dt)
{
	// dt = malloc(sizeof (t_data));
	dt->ray = malloc(sizeof(t_ray));
	dt->img = ft_calloc(1, sizeof(t_imgptr));
	dt->mlx = mlx_init();
	dt->window = mlx_new_window(dt->mlx, WIN_X, WIN_Y, "Les gentils seaux");
	dt->img->img = mlx_new_image(dt->mlx, WIN_X, WIN_Y);
	dt->img->path = mlx_get_data_addr(dt->img->img, &dt->img->bytes,
			&dt->img->line, &dt->img->end);
	dt->tablen = 0;
	dt->player_count = 0;
	dt->ppos_x = 0;
	dt->ppos_y = 0;
	dt->ray->plane_x = 0;
	dt->ray->plane_y = 0.66;
	return (0);
}

int	init_asset(t_data *dt)
{
	dt->asset = malloc(sizeof(t_asset));
	if (dt->asset == NULL)
	{
		printf("Error: malloc failed\n");
		return (0);
	}
	dt->asset->path = 0;
	dt->asset->nb_color = 0;
	dt->asset->nb_nswe = 0;
	dt->asset->r = 0;
	dt->asset->g = 0;
	dt->asset->b = 0;
	// dt->asset->ceiling = 0;
	// dt->asset->floor = 0;
	return (0);
}

void	init_file(t_data *dt, char **args)
{
	dt->asset->nb_nswe = nb_line(dt, args, 1);
	dt->asset->nb_color = nb_line(dt, args, 2);
	dt->len_map = nb_line(dt, args, 3);
}

void	init_color(t_color *color)
{
	color = malloc(sizeof(t_color));
	color->r = 0;
	color->g = 0;
	color->b = 0;
	color->floor = 0;
	color->ceiling = 0;
}

void	init_map(t_data *dt)
{
	int	len;

	dt->map_height = 0;
	dt->map_width = 0;
	while (dt->map[dt->map_height])
	{
		len = ft_strlen(dt->map[dt->map_height]);
		if (len > dt->map_width)
			dt->map_width = len;
		dt->map_height++;
	}
}
