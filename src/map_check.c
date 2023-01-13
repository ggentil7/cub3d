/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:41:30 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/13 11:35:41 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
//x = longueur 		y = largeur

int	check_walls(t_data *data) //appeler apres check_borders sinon segfaul
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (y == 0 || y == data->map_height - 1 || x == 0
				|| x == data->map_width - 1)
			{
				if (data->map[y][x] != '1')
				{
					printf("Error: walls map\n");
					exit(EXIT_FAILURE);
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_map_char(t_data *data) //appeler apres check_borders sinon segfault
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] != '1' && data->map[y][x] != '0'
				&& data->map[y][x] != 'N' && data->map[y][x] != 'S'
				&& data->map[y][x] != 'E' && data->map[y][x] != 'W')
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

int	check_borders(t_data *data)
{
	int	x;
	int	y;

	if (!data->map || !*data->map)
	{
		printf("Error: Map is empty\n");
		exit(EXIT_FAILURE);
	}
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
			{
				if ((x > 0 && data->map[y][x - 1] == '0') || (x < data->map_width - 1&& data->map[y][x + 1] == '0') ||
					(y > 0 && data->map[y - 1][x] == '0') || (y < data->map_height - 1 && data->map[y + 1][x] == '0'))
				{
					printf("Error: Wall error at x:%d y:%d\n", x, y);
					exit(EXIT_FAILURE);
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

/*La première vérification vérifie si la map est vide ou absente, si c'est le cas, elle affiche une erreur et quitte le programme.
Les vérifications suivantes vérifient si x ou y dépassent les limites de la map avant de vérifier les valeurs des cases adjacentes. Cela évite les erreurs de segmentation.
Enfin, si une erreur est détectée, l'erreur est affichée avec la position x et y ou l'erreur est survenue.
Il est important de noter que les variables map_width et map_height doivent être initialisées avec les dimensions de la map avant d'appeler 
cette fonction, pour pouvoir utiliser les limites correctes pour vérifier les bords de la map. Il faut aussi vérifier que ces valeurs ne soient pas négatives ou nulles avant de les utiliser.*/