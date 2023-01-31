/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:51:48 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/31 13:35:39 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	create_trgb(t_data *dt, int r, int g, int b)
{
	if (r < 0 || r > 255)
	{
		printf("Error color\n");
		exit_game(dt);
	}
	if (g < 0 || g > 255)
	{
		printf("Error color\n");
		exit_game(dt);
	}
	if (b < 0 || b > 255)
	{
		printf("Error color\n");
		exit_game(dt);
	}
	return (r << 16 | g << 8 | b);
}
