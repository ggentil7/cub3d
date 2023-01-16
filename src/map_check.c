/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielagentil <gabrielagentil@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:41:30 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/16 23:24:21 by gabrielagen      ###   ########.fr       */
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

int	replace_space_by_wall(t_data *dt) //appeler après check_borders
{
    int x;
    int y;
	
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

int check_player(t_data *dt) //appeler après check_borders
{
    int x;
    int y;
	
    if (dt->player_count == 0)
    {
        printf("Error: No player in the map\n");
        exit(EXIT_FAILURE);
    }
    y = 0;
    while (dt->map[y])
    {
        x = 0;
        while (dt->map[y][x])
        {
            if (dt->map[y][x] == 'N' || dt->map[y][x] == 'S'|| dt->map[y][x] == 'W'|| dt->map[y][x] == 'E' )
            {
                dt->player_count++;
                if (dt->player_count > 1)
                {
                    printf("Error: Multiple players in the map\n");
                    exit(EXIT_FAILURE);
                }
				dt->ppos_x = x;
				dt->ppos_y = y;
				dt->player_direction = dt->map[y][x];
            }
            x++;
        }
        y++;
    }
    return (0);
}
