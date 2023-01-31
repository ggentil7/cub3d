/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:46:42 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/30 20:58:26 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	replace_space_by_wall(t_data *dt)
{
	int	x;
	int	y;

	y = 0;
	while (dt->map[y])
	{
		x = 0;
		while (dt->map[y][x])
		{
			if (dt->map[y][x] == ' ')
			{
				dt->map[y][x] = '1';
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	empty_map(t_data *dt)
{
	if (!dt->map || !*dt->map)
	{
		printf("Error: Map is empty\n");
		exit_game(dt);
	}
}

void	no_player(t_data *dt)
{
	if (dt->player_count == 0)
	{
		printf("Error: No player in the map\n");
		exit_game(dt);
	}
}

void	multiple_players(t_data *dt)
{
	if (dt->player_count > 1)
	{
		printf("Error: Multiple players in the map\n");
		exit_game(dt);
	}
}
