/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:41:30 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/10 16:31:25 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
//x = longueur 		y = largeur

// int	check_wall(t_data *data)
// {
// 	int	x;
// 	int	y;

// 	check_borders(data);
// 	y = 0;
// 	while (data->map[y])
// 	{
// 		x = 0;
// 		while (data->map[y][x])
// 		{
// 			if (data->map[y][x] == '1')
// 			{
// 				if (data->map[y][x + 1] == '0' || data->map[y][x - 1] == '0'
// 					|| data->map[y + 1][x] == '0' || data->map[y - 1][x] == '0')
// 				{
// 					printf("Error:\n wall error\n");
// 					exit (EXIT_SUCCESS);
// 				}
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (0);
// }

// int	check_map_char(char *line)
// {
// 	int	i;

// 	i = 0;
// 	if (!line)
// 		return (0);
// 	if (find_char(line, '1') == 1 || find_char(line, '0') == 1)
// 	{
// 		while (line[i])
// 		{
// 			if (line[i] != '1' && line[i] != '0' && line[i] != 'N'
// 				&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
// 				&& line[i] != '\n' && line[i] != '\t' && line[i] != ' ')
// 				return (1);
// 			i++;
// 		}
// 	}
// 	return (0);
// }

// int	is_map(t_data *data, char *line) //vérifie que la longueur de chaque ligne de la map est identique
// {
// 	int	i;

// 	i = 0;
// 	if (data->map_y == 0)
// 	{
// 		data->map_x = ft_strlen(line);
// 		data->map_y++;
// 	}
// 	else
// 	{
// 		if (data->map_x != ft_strlen(line))
// 		{
// 			printf("Error:\n map error\n");
// 			exit (EXIT_SUCCESS);
// 		}
// 		data->map_y++;
// 	}
// 	if (check_map_char(line) == 1)
// 	{
// 		printf("Error:\n map error\n");
// 		exit (EXIT_SUCCESS);
// 	}
// 	return (0);
// }

// int	check_map_closed(char **map, int width, int height)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < height)
// 	{
// 		j = 0;
// 		while (j < width)
// 		{
// 			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
// 			{
// 				if (map[i][j] == ' ')
// 				{
// 					printf("Error: map is not closed\n");
// 					return (-1);
// 				}
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int	check_borders(t_data *data)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (data->map[0][x])
// 	{
// 		if (data->map[0][x] != '1')
// 		{
// 			printf("Error:\n map is not surrounded by walls\n");
// 			exit (EXIT_SUCCESS);
// 		}
// 		x++;
// 	}
// 	x = 0;
// 	y = 0;
// 	while (data->map[y - 1][x])
// 	{
// 		if (data->map[y - 1][x] != '1')
// 		{
// 			printf("Error:\n map is not surrounded by walls\n");
// 			exit (EXIT_SUCCESS);
// 		}
// 		x++;
// 	}
// 	x = 0;
// 	y = 0;
// 	while (data->map[y])
// 	{
// 		if (data->map[y][0] != '1')
// 		{
// 			printf("Error:\n map is not surrounded by walls\n");
// 			exit (EXIT_SUCCESS);
// 		}
// 		y++;
// 	}
// 	x = 0;
// 	y = 0;
// 	while (data->map[y])
// 	{
// 		if (data->map[y][x - 1] != '1')
// 		{
// 			printf("Error:\n map is not surrounded by walls\n");
// 			exit (EXIT_SUCCESS);
// 		}
// 		y++;
// 	}
// 	return (0);
// }
