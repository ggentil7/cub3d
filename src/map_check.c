/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:41:30 by ggentil           #+#    #+#             */
/*   Updated: 2022/12/28 16:23:33 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*int	check_wall(t_data *data, int x, int y) //x = longueur y = largeur 
{
	if (data->map[0][x] != '1' || data->map[data->map_y - 2][x] != '1')
	{
		ft_printf("Error:\n wall error\n");
		exit(0);
	}
	if (data->map[y][0] != '1' || data->map[y][data->map_x - 2] != '1')
	{
		ft_printf("Error:\n wall error\n");
		exit (EXIT_SUCCESS);
	}
}*/

/*int	wall(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}*/

int	check_wall(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
			{
				if (data->map[y][x + 1] == '0' || data->map[y][x - 1] == '0'
					|| data->map[y + 1][x] == '0' || data->map[y - 1][x] == '0')
				{
					ft_printf("Error:\n wall error\n");
					exit (EXIT_SUCCESS);
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_map_char(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	if (find_char(line, '1') == 1 || find_char(line, '0') == 1)
	{
		while (line[i])
		{
			if (line[i] != '1' && line[i] != '0' && line[i] != 'N'
				&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
				&& line[i] != '\n' && line[i] != '\t' && line[i] != ' ')
				return (1);
			i++;
		}
	}
	return (0);
}

int	is_map(t_data *data, char *line)
{
	int	i;

	i = 0;
	if (data->map_y == 0)
	{
		data->map_x = ft_strlen(line);
		data->map_y++;
	}
	else
	{
		if (data->map_x != ft_strlen(line))
		{
			ft_printf("Error:\n map error\n");
			exit (EXIT_SUCCESS);
		}
		data->map_y++;
	}
	if (check_map_char(line))
	{
		ft_printf("Error:\n map error\n");
		exit (EXIT_SUCCESS);
	}
	return (0);
}