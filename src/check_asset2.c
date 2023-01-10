/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asset2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:48:48 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/10 18:19:21 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_f(t_data *dt)
{
	char	*separator;

	if (!ft_strcmp(dt->asset->id, dt->asset->f))
	{
		separator = dt->asset->path;
		dt->asset->r = ft_atoi(separator);
		while (*separator && *separator != ',')
				separator++;
		error_format(dt);
		separator++;
		dt->asset->g = ft_atoi(separator);
		while (*separator && *separator != ',')
				separator++;
		error_format(dt);
		separator++;
		dt->asset->b = ft_atoi(separator);
		if (dt->asset->r < 0 || dt->asset->r > 255 || dt->asset->g < 0
			|| dt->asset->g > 255 || dt->asset->b < 0 || dt->asset->b > 255)
		{
			printf("Error: invalid format\n");
			return (-1);
		}
	}
	return (0);
}

int	check_c(t_data *dt)
{
	char	*separator;

	if (!ft_strcmp(dt->asset->id, dt->asset->c))
	{
		separator = dt->asset->path;
		dt->asset->r = ft_atoi(separator);
		while (*separator && *separator != ',')
				separator++;
		error_format(dt);
		separator++;
		dt->asset->g = ft_atoi(separator);
		while (*separator && *separator != ',')
				separator++;
		error_format(dt);
		separator++;
		dt->asset->b = ft_atoi(separator);
		if (dt->asset->r < 0 || dt->asset->r > 255 || dt->asset->g < 0
			|| dt->asset->g > 255 || dt->asset->b < 0 || dt->asset->b > 255)
		{
			printf("Error: invalid format\n");
			return (-1);
		}
	}
	return (0);
}

int	check_asset_id(t_data *dt)
{
	if (!strcmp(dt->asset->id, dt->asset->no))
		check_no(dt);
	else if (!strcmp(dt->asset->id, dt->asset->so))
		check_so(dt);
	else if (!strcmp(dt->asset->id, dt->asset->we))
		check_we(dt);
	else if (!strcmp(dt->asset->id, dt->asset->ea))
		check_ea(dt);
	else if (!strcmp(dt->asset->id, dt->asset->f))
		check_f(dt);
	else if (!strcmp(dt->asset->id, dt->asset->c))
		check_c(dt);
	else
	{
		printf("Error: invalid asset id\n");
		return (-1);
	}
	return (0);
}

int	error_format(t_data *dt)
{
	char	*separator;

	separator = dt->asset->path;
	if (*separator != ',')
	{
		printf("Error: invalid format\n");
		return (-1);
	}
	return (0);
}
