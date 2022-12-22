/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:41:30 by ggentil           #+#    #+#             */
/*   Updated: 2022/12/22 17:29:36 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_cub(char *c)
{
	int	i;

	i = ft_strlen(c);
	if (c[--i] == 'b')
	{
		if (c[--i] == 'u')
		{
			if (c[--i] == 'c')
				return (1);
		}
	}
	return (0);
}

int	check_wall(t_data *data, int x, int y) //x = longueur y = largeur 
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
}

int	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
			&&line[i] != '\v' && line[i] != '\f' && line[i] != '\0')
			return (1);
		i++;
	}
	return (0);
}

int	is_map(t_data *data)
