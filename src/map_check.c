/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:41:30 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/15 17:53:48 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
//x = longueur 		y = largeur

int	check_map_char(t_data *dt)
{
	int	x;
	int	y;

	y = 0;
	while (dt->map[y])
	{
		x = 0;
		while (dt->map[y][x])
		{
			if (dt->map[y][x] != '1' && dt->map[y][x] != '0'
				&& dt->map[y][x] != 'N' && dt->map[y][x] != 'S'
				&& dt->map[y][x] != 'E' && dt->map[y][x] != 'W'
				&& dt->map[y][x] != ' ')
			{
				printf("Error: Invalid character\n");
				exit(EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_borders(t_data *dt)
{
	int	i;
	int	j;

	if (!dt->map || !*dt->map)
	{
		printf("Error: Map is empty\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	j = 0;
	while (dt->map[0][j])
	{
		if (dt->map[0][j] != '1')
		{
			printf("Error: Wall error\n");
			exit(EXIT_FAILURE);
		}
		j++;
	}
	i = 0;
	j = 0;
	while (dt->map[dt->map_height - 1][j])
	{
		if (dt->map[dt->map_height - 1][j] != '1')
		{
			printf("Error: Wall error\n");
			exit(EXIT_FAILURE);
		}
		j++;
	}
	i = 0;
	while (dt->map[i])
	{
		j = 0;
		if (dt->map[i][0] != '1'
			|| dt->map[i][ft_strlen(dt->map[i]) - 1] != '1')
		{
			printf("Error: Wall error\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (0);
}
