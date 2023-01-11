/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:13:13 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/11 21:24:30 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

int	check_color(t_data *dt, char *line)
{
	char	**tmp;
	int		i;

	i = 0;
	if (check_virgule(line))
		printf("Error: color\n");
	tmp = ft_split(line + 1, ',');
	if (!line)
		printf("Error: malloc\n");
	while (i != 2 && tmp[i])
	{
		tmp[i] = ft_strtrim(tmp[i], " ");
		free (tmp);
		i++;
	}
	if (!ft_strncmp(line, "F", 1))
		atoi_color(dt->color->floor, tmp);
	else
		atoi_color(dt->color->ceiling, tmp);
	return (0);
}

int	parse_color2(t_data *dt, char *line)
{
	int	i;

	i = 0;
	if (!ft_strncmp(&line[i], "F", 1) || !ft_strncmp(&line[i], "C", 1))
	{
		check_color(dt, &line[i]);
		i++;
	}
	return (check_setting_color(dt));
}
