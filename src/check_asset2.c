/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asset2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:48:48 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/04 11:06:05 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_f(t_asset *asset)
{
	int	fd;

	fd = open(asset->path, O_RDONLY);
	if (!ft_strcmp(asset->id, "F"))
	{
		if (!*asset->path)
		{
			printf("Error: invalid floor texture path\n");
			return (-1);
		}
		if (fd == -1)
		{
			printf("Error: failed to open floor texture file\n");
			return (-1);
		}
		close (fd);
	}
	return (0);
}

int	check_c(t_asset *asset)
{
	int	fd;

	fd = open(asset->path, O_RDONLY);
	if (!ft_strcmp(asset->id, "C"))
	{
		if (!*asset->path)
		{
			printf("Error: invalid ceiling texture path\n");
			return (-1);
		}
		if (fd == -1)
		{
			printf("Error: failed to open ceiling texure path\n");
			return (-1);
		}
		close (fd);
	}
	return (0);
}

int	check_asset_id(t_asset *asset)
{
	t_data	*data;

	if (!strcmp(asset->id, data->no))
		check_no(asset);
	else if (!strcmp(asset->id, data->so))
		check_so(asset);
	else if (!strcmp(asset->id, data->we))
		check_we(asset);
	else if (!strcmp(asset->id, data->ea))
		check_ea(asset);
	else
	{
		printf("Error: invalid asset id\n");
		return (-1);
	}
	return (0);
}

int	calloc_asset(t_data *data)
{
	data->no = ft_calloc(1, sizeof(char *));
	data->so = ft_calloc(1, sizeof(char *));
	data->we = ft_calloc(1, sizeof(char *));
	data->ea = ft_calloc(1, sizeof(char *));
	return (0);
}
