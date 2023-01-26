/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asset_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:48:48 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/26 15:06:07 by mthiesso         ###   ########.fr       */
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

int	atoi_color(t_data *dt, char **color, char what)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(color[0]);
	g = ft_atoi(color[1]);
	b = ft_atoi(color[2]);
	if (what == 'F')
		dt->floor = create_trgb(0, r, g, b);
	else
		dt->ceiling = create_trgb(0, r, g, b);
	//free (color);
	return (0);
}

// int	check_setting_color(t_data *dt)
// {
// 	if (dt->ceiling->r < 0 || dt->ceiling->r > 255)
// 		printf("Error ceiling color red\n");
// 	if (dt->ceiling->g < 0 || dt->ceiling->g > 255)
// 		printf("Error ceiling color green\n");
// 	if (dt->ceiling->b < 0 || dt->ceiling->b > 255)
// 		printf("Error ceiling color blue\n");
// 	if (dt->floor->r < 0 || dt->floor->r > 255)
// 		printf("Error floor color blue\n");
// 	if (dt->floor->g < 0 || dt->floor->g > 255)
// 		printf("Error floor color green\n");
// 	if (dt->floor->b < 0 || dt->floor->b > 255)
// 		printf("Error floor color blue\n");
// 	return (0);
// }
