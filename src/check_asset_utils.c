/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asset_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:48:48 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/15 17:49:35 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_virgule(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i + 1]))
	{
		if (line[i] == ',' && (line[i + 1]) == ',')
			return (1);
		i++;
	}
	return (0);
}

int	atoi_color(t_asset *asset, char **color)
{
	asset->r = ft_atoi(color[0]);
	asset->g = ft_atoi(color[1]);
	asset->b = ft_atoi(color[2]);
	free (color);
	return (0);
}

int	check_setting_color(t_data *dt)
{
	if (dt->asset->ceiling.r < 0 || dt->asset->ceiling.r > 255)
		printf("Error ceiling color red\n");
	if (dt->asset->ceiling.g < 0 || dt->asset->ceiling.g > 255)
		printf("Error ceiling color green\n");
	if (dt->asset->ceiling.b < 0 || dt->asset->ceiling.b > 255)
		printf("Error ceiling color blue\n");
	if (dt->asset->floor.r < 0 || dt->asset->floor.r > 255)
		printf("Error floor color blue\n");
	if (dt->asset->floor.g < 0 || dt->asset->floor.g > 255)
		printf("Error floor color green\n");
	if (dt->asset->floor.b < 0 || dt->asset->floor.b > 255)
		printf("Error floor color blue\n");
	return (0);
}
