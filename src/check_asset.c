/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielagentil <gabrielagentil@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:13:13 by ggentil           #+#    #+#             */
/*   Updated: 2022/12/30 15:40:09 by gabrielagen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_asset(t_asset *asset, char *line)
{
	int		i;
	int		fd;
	char	*separator;

	i = 0;
	while (line[i] && is_space(line[i]))
		i++;
	if (!(asset->id = ft_strndup(line, i)))
	{
		printf("Error: failed to allocate memory for asset id\n");
		return (-1);
	}
	separator = line + i;
	while (is_space(*separator))
		separator++;
	if (!(asset->path = ft_strdup(separator)))
	{
		printf("Error: failed to allocate memory for asset path\n");
		return (-1);
	}
	if (!ft_strcmp(asset->id, "NO"))
	{
		if (!*asset->path)
		{
			printf("Error: invalid north texture path\n");
			return (-1);
		}
		if ((fd = open(asset->path, O_RDONLY)) == -1)
		{
			printf("Error: failed to open north texture file\n");
			return (-1);
		}
		close (fd);
	}
	else if (!ft_strcmp(asset->id, "SO"))
	{
		if (!*asset->path)
		{
			printf("Error: invalid south texture path\n");
			return (-1);
		}
		if ((fd = open(asset->path, O_RDONLY)) == -1)
		{
			printf("Error: failed to open south texture file\n");
			return (-1);
		}
		close (fd);
	}
	else if (!ft_strcmp(asset->id, "WE"))
	{
		if (!*asset->path)
		{
			printf("Error: invalid west texture path\n");
			return (-1);
		}
		if ((fd = open(asset->path, O_RDONLY)) == -1)
		{
			printf("Error: failed to open west texture file\n");
			return (-1);
		}
		close (fd);
	}
	else if (!ft_strcmp(asset->id, "EA"))
	{
		if (!*asset->path)
		{
			printf("Error: invalid east texture path\n");
			return (-1);
		}
		if ((fd = open(asset->path, O_RDONLY)) == -1)
		{
			printf("Error: failed to open east texture file\n");
			return (-1);
		}
		close (fd);
	}
	return (0);
}
