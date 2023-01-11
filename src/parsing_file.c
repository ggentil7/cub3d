/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielagentil <gabrielagentil@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:35:28 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/11 10:17:16 by gabrielagen      ###   ########.fr       */
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
		printf("nswe[%d] : %s", j, dt->asset->nswe[j]);
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
		printf("color[%d] : %s", j, dt->asset->color[j]);
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
		printf("map[%d] : %s", j, dt->map[j]);
		i++;
	}
	return (i);
}

int	asset_error(t_data *dt)
{
	if (dt->asset->nb_nswe != 4 || dt->asset->nb_color != 2)
	{
		printf("Error: invalid file\n");
		return (-1);
	}
	else if (!dt->asset->nb_nswe || !dt->asset->nb_color)
	{
		printf("Error: invalid file\n");
		return (-1);
	}
	return (0);
}