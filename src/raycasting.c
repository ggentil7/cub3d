/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:42:27 by mthiesso          #+#    #+#             */
/*   Updated: 2022/12/22 17:26:57 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	screen_display(t_data *dt)
{
	minimap_display(dt);
	mlx_put_image_to_window(dt->mlx, dt->window, dt->img->img, 0, 0);
	return(0);
}