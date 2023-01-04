/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:13:13 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/04 11:06:10 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_asset(t_asset *asset, char *line)
{
	int		i;
	char	*separator;

	i = 0;
	while (line[i] && is_space(line[i]))
		i++;
	asset->id = ft_strndup(line, i);
	if (asset->id == NULL)
	{
		printf("Error: failed to allocate memory for asset id\n");
		return (-1);
	}
	separator = line + i;
	while (is_space(*separator))
		separator++;
	asset->path = ft_strdup(separator);
	check_asset_id(asset);
	if (asset->path == NULL)
	{
		printf("Error: failed to allocate memory for asset path\n");
		return (-1);
	}
	return (0);
}

int	check_no(t_asset *asset)
{
	int		fd;
	t_data	*data;

	fd = open(asset->path, O_RDONLY);
	if (!ft_strcmp(asset->id, data->no))
	{
		if (!*asset->path)
		{
			printf("Error: invalid north texture path\n");
			return (-1);
		}
		if (fd == -1)
		{
			printf("Error: failed to open north texture file\n");
			return (-1);
		}
		close (fd);
	}
	return (0);
}

int	check_so(t_asset *asset)
{
	int		fd;
	t_data	*data;

	fd = open(asset->path, O_RDONLY);
	if (!ft_strcmp(asset->id, data->so))
	{
		if (!*asset->path)
		{
			printf("Error: invalid south texture path\n");
			return (-1);
		}
		if (fd == -1)
		{
			printf("Error: failed to open south texture file\n");
			return (-1);
		}
		close (fd);
	}
	return (0);
}

int	check_we(t_asset *asset)
{
	int		fd;
	t_data	*data;

	fd = open(asset->path, O_RDONLY);
	if (!ft_strcmp(asset->id, data->we))
	{
		if (!*asset->path)
		{
			printf("Error: invalid west texture path\n");
			return (-1);
		}
		if (fd == -1)
		{
			printf("Error: failed to open west texture file\n");
			return (-1);
		}
		close (fd);
	}
	return (0);
}

int	check_ea(t_asset *asset)
{
	int		fd;
	t_data	*data;

	fd = open(asset->path, O_RDONLY);
	if (!ft_strcmp(asset->id, data->ea))
	{
		if (!*asset->path)
		{
			printf("Error: invalid east texture path\n");
			return (-1);
		}
		if (fd == -1)
		{
			printf("Error: failed to open east texture file\n");
			return (-1);
		}
		close (fd);
	}
	return (0);
}
