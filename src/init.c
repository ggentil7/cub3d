/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielagentil <gabrielagentil@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:47:23 by mthiesso          #+#    #+#             */
/*   Updated: 2023/01/08 21:43:09 by mthiesso         ###   ########.fr       */
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
	dt->img->path = mlx_get_data_addr(dt->img->img, &dt->img->bytes, &dt->img->line, &dt->img->end);
	dt->tablen = 0;
	return(0);
}

int	init_asset(t_asset *asset)
{
	asset = malloc(sizeof(t_asset));
    if (asset == NULL)
    {
        printf("Error: malloc failed\n");
        return (0);
    }
	asset->id = 0;
	asset->path = 0;
	asset->nb_color = 0;
	asset->nb_nswe = 0;
	asset->r = 0;
	asset->g = 0;
	asset->b = 0;
	return (0);
}

