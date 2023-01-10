/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:13:13 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/10 18:15:37 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_asset(t_data *dt, char *line)
{
	int		i;
	char	*separator;

	i = 0;
	while (line[i] && is_space(line[i]))
		i++;
	dt->asset->id = ft_strndup(line, i);
	if (dt->asset->id == NULL)
	{
		printf("Error: invalid asset id\n");
		return (-1);
	}
	separator = line + i;
	while (is_space(*separator))
		separator++;
	dt->asset->path = ft_strdup(separator);
	check_asset_id(dt);
	if (dt->asset->path == NULL)
	{
		printf("Error: invalid asset path\n");
		return (-1);
	}
	free (dt->asset->id);
	free (dt->asset->path);
	return (0);
}

int	check_no(t_data *dt)
{
	int		fd;

	fd = open(dt->asset->path, O_RDONLY);
	if (!ft_strcmp(dt->asset->id, dt->asset->no))
	{
		if (!*dt->asset->path)
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

int	check_so(t_data *dt)
{
	int		fd;

	fd = open(dt->asset->path, O_RDONLY);
	if (!ft_strcmp(dt->asset->id, dt->asset->so))
	{
		if (!*dt->asset->path)
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

int	check_we(t_data *dt)
{
	int		fd;

	fd = open(dt->asset->path, O_RDONLY);
	if (!ft_strcmp(dt->asset->id, dt->asset->we))
	{
		if (!*dt->asset->path)
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

int	check_ea(t_data *dt)
{
	int		fd;

	fd = open(dt->asset->path, O_RDONLY);
	if (!ft_strcmp(dt->asset->id, dt->asset->ea))
	{
		if (!*dt->asset->path)
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
