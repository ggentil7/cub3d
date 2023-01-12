/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:35:28 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/12 16:22:00 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	parse_file(t_data *dt, char *line, int i)
{
	parse_nswe(dt, line, i);
	parse_color(dt, line, i);
	parse_map(dt, line, i);
	return (i);
}

int	parse_nswe(t_data *dt, char *line, int i)
{
	int	j;

	if (nb_of_asset(line) == 1)
	{
		j = ft_tablen(dt->asset->nswe);
		dt->asset->nswe[j] = ft_strdup(line);
		check_valid_path(dt, line);
		// printf("nswe[%d] : %s", j, dt->asset->nswe[j]);
		i++;
	}
	return (i);
}

int	parse_color(t_data *dt, char *line, int i)
{
	int	j;

	if (nb_of_asset(line) == 2)
	{
		j = ft_tablen(dt->asset->color);
		dt->asset->color[j] = ft_strdup(line);
		parse_color2(dt, line);
		printf("color[%d] : %s\n", j, dt->asset->color[j]);
		i++;
	}
	return (i);
}

int	parse_map(t_data *dt, char *line, int i)
{
	int	j;

	if (nb_of_asset(line) == 3)
	{
		j = ft_tablen(dt->map);
		dt->map[j] = ft_strdup(line);
		// printf("map[%d] : %s", j, dt->map[j]);
		i++;
	}
	return (i);
}

int	error_asset(t_data *dt)
{
	if (dt->asset->nb_nswe != 4 || dt->asset->nb_color != 2)
	{
		printf("Error: invalid number of assets\n");
		return (EXIT_FAILURE);
	}
	return (0);
}
