/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:13:13 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/11 18:20:54 by ggentil          ###   ########.fr       */
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

int	check_path(t_data *dt)
{
	int	fd;

	// printf("%s\n", dt->asset->path);
	fd = open(dt->asset->path, O_RDONLY);
	printf("path = {%s}\nfd = %d\n", dt->asset->path, fd);
	if (fd < 0)
	{
		printf("Error: invalid path texture\n");
		return (-1);
	}
	close(fd);
	return (0);
}

int	check_valid_path(t_data *dt, char *line)
{
	if (line && !ft_strncmp(line, "NO", 2))
	{
		dt->asset->path = ft_strtrim(line + 2, " ");
		check_path(dt);
		// printf("path = %s\n", dt->asset->path);
	}
	else if (line && !ft_strncmp(line, "SO", 2))
	{
		dt->asset->path = ft_strtrim(line + 2, " ");
		check_path(dt);
	}
	else if (line && !ft_strncmp(line, "WE", 2))
	{
		dt->asset->path = ft_strtrim(line + 2, " ");
		check_path(dt);
	}
	else if (line && !ft_strncmp(line, "EA", 2))
	{
		dt->asset->path = ft_strtrim(line + 2, " ");
		check_path(dt);
	}
	return (EXIT_SUCCESS);
}
