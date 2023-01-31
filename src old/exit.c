/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:24:29 by mthiesso          #+#    #+#             */
/*   Updated: 2023/01/31 13:03:10 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	exit_game(t_data *dt)
{
	exit_img(dt->asset->no);
	mlx_destroy_image(dt->mlx, dt->asset->no->img);
	mlx_destroy_image(dt->mlx, dt->asset->so->img);
	mlx_destroy_image(dt->mlx, dt->asset->ea->img);
	mlx_destroy_image(dt->mlx, dt->asset->we->img);
	mlx_destroy_window(dt->mlx, dt->window);
	exit_img(dt->asset->so);
	exit_img(dt->asset->ea);
	exit_img(dt->asset->we);
	exit_asset(dt->asset);
	exit_dt(dt);
	exit(EXIT_SUCCESS);
}

void	exit_dt(t_data *dt)
{
	free_tab(dt->map);
	free(dt->map_path);
	free(dt->window);
	free(dt);
}

void	exit_asset(t_asset *asset)
{
	free_tab(asset->nswe);
	free_tab(asset->color);
	free(asset->path);
	free(asset);
}

void	exit_img(t_img *img)
{
	free(img->img_path);
	free(img);
}
