/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asset2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:48:48 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/10 15:36:41 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// int	check_f(t_asset *asset, t_data *data)
// {
// 	char	*separator;

// 	if (!ft_strcmp(asset->id, data->f))
// 	{
// 		separator = asset->path;
// 		asset->r = ft_atoi(separator);
// 		while (*separator && *separator != ',')
// 				separator++;
// 		error_format(asset);
// 		separator++;
// 		asset->g = ft_atoi(separator);
// 		while (*separator && *separator != ',')
// 				separator++;
// 		error_format(asset);
// 		separator++;
// 		asset->b = ft_atoi(separator);
// 		if (asset->r < 0 || asset->r > 255 || asset->g < 0 || asset->g > 255
// 			|| asset->b < 0 || asset->b > 255)
// 		{
// 			printf("Error: invalid format\n");
// 			return (-1);
// 		}
// 	}
// 	return (0);
// }

// int	check_c(t_asset *asset, t_data *data)
// {
// 	char	*separator;

// 	if (!ft_strcmp(asset->id, data->c))
// 	{
// 		separator = asset->path;
// 		asset->r = ft_atoi(separator);
// 		while (*separator && *separator != ',')
// 				separator++;
// 		error_format(asset);
// 		separator++;
// 		asset->g = ft_atoi(separator);
// 		while (*separator && *separator != ',')
// 				separator++;
// 		error_format(asset);
// 		separator++;
// 		asset->b = ft_atoi(separator);
// 		if (asset->r < 0 || asset->r > 255 || asset->g < 0 || asset->g > 255
// 			|| asset->b < 0 || asset->b > 255)
// 		{
// 			printf("Error: invalid format\n");
// 			return (-1);
// 		}
// 	}
// 	return (0);
// }

// int	check_asset_id(t_asset *asset, t_data *data)
// {
// 	if (!strcmp(asset->id, data->no))
// 		check_no(asset, data);
// 	else if (!strcmp(asset->id, data->so))
// 		check_so(asset, data);
// 	else if (!strcmp(asset->id, data->we))
// 		check_we(asset, data);
// 	else if (!strcmp(asset->id, data->ea))
// 		check_ea(asset, data);
// 	else if (!strcmp(asset->id, data->f))
// 		check_f(asset, data);
// 	else if (!strcmp(asset->id, data->c))
// 		check_c(asset, data);
// 	else
// 	{
// 		printf("Error: invalid asset id\n");
// 		return (-1);
// 	}
// 	return (0);
// }

// int	error_format(t_asset *asset)
// {
// 	char	*separator;

// 	(void) asset;
// 	separator = asset->path;
// 	if (*separator != ',')
// 	{
// 		printf("Error: invalid format\n");
// 		return (-1);
// 	}
// 	return (0);
// }
