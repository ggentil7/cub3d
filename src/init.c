/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:47:23 by mthiesso          #+#    #+#             */
/*   Updated: 2023/01/11 21:21:10 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_game(t_data *dt)
{
	//dt = malloc(sizeof (t_data));
	dt->img = ft_calloc(1, sizeof(t_imgptr));
	dt->mlx = mlx_init();
	dt->window = mlx_new_window(dt->mlx, WIN_X, WIN_Y, "Les gentils seaux");
	dt->img->img = mlx_new_image(dt->mlx, WIN_X, WIN_Y);
	dt->img->path = mlx_get_data_addr(dt->img->img, &dt->img->bytes,
			&dt->img->line, &dt->img->end);
	dt->tablen = 0;	
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
	dt->asset->id = 0;
	dt->asset->path = 0;
	dt->asset->nb_color = 0;
	dt->asset->nb_nswe = 0;
	// dt->asset->r = 0;
	// dt->asset->g = 0;
	// dt->asset->b = 0;
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
	color->r = 0;
	color->g = 0;
	color->b = 0;
}
