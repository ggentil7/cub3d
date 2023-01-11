/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asset_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:48:48 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/11 21:16:26 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_virgule(char *line)
{
	int	i;

	i = 0;
	while (line[i] && is_space(line[i + 1]))
	{
		if (line[i] == ',' && is_space(line[i + 1]) == ',')
			return (1);
		i++;
	}
	return (0);
}

int	atoi_color(t_color *rgb, char **color)
{
	rgb->r = ft_atoi(color[0]);
	rgb->g = ft_atoi(color[1]);
	rgb->b = ft_atoi(color[2]);
	free (color);
}

int	check_setting_color(t_data *dt)
{
	if (dt->asset.ceiling.r < 0 || dt->asset.celing.r > 255)
		printf("Error ceiling color red\n");
	if (dt->asset.ceiling.g < 0 || dt->asset.ceiling.g > 255)
		printf("Error ceiling color green\n");
	if (dt->asset.ceiling.b < 0 || dt->asset.ceiling.b > 255)
		printf("Error ceiling color blue\n");
	if (dt->asset.floor.r < 0 || dt->asset.floor.r > 255)
		printf("Error floor color blue\n");
	if (dt->asset.floor.g < 0 || dt->asset.floor.g > 255)
		printf("Error floor color green\n");
	if (dt->asset.floor.b < 0 || dt->asset.floor.b > 255)
		printf("Error floor color blue\n");
	return (0);
}
