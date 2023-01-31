/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:13:13 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/31 14:15:21 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_path(t_data *dt)
{
	int	fd;

	fd = open(dt->asset->path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: invalid path texture\n");
		close(fd);
		exit_game(dt);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	check_valid_path(t_data *dt, char *line)
{
	if (line && !ft_strncmp(line, "NO", 2))
	{
		dt->asset->path = ft_strtrim(line + 2, " ");
		check_path(dt);
		dt->asset->no->img_path = ft_strdup(dt->asset->path);
	}
	else if (line && !ft_strncmp(line, "SO", 2))
	{
		dt->asset->path = ft_strtrim(line + 2, " ");
		check_path(dt);
		dt->asset->so->img_path = ft_strdup(dt->asset->path);
	}
	else if (line && !ft_strncmp(line, "WE", 2))
	{
		dt->asset->path = ft_strtrim(line + 2, " ");
		check_path(dt);
		dt->asset->we->img_path = ft_strdup(dt->asset->path);
	}
	else if (line && !ft_strncmp(line, "EA", 2))
	{
		dt->asset->path = ft_strtrim(line + 2, " ");
		check_path(dt);
		dt->asset->ea->img_path = ft_strdup(dt->asset->path);
	}
	free(dt->asset->path);
	dt->asset->path = NULL;
	return (EXIT_SUCCESS);
}

int	check_color(t_data *dt, char *line)
{
	char	**tmp;
	char	*tmp_2;
	int		i;

	i = 0;
	error_color(line);
	tmp = ft_split(line + 1, ',');
	if (!tmp)
		printf("Error: in check color\n");
	while (i != 3 && tmp[i])
	{
		tmp_2 = tmp[i];
		tmp[i] = ft_strtrim(tmp_2, " ");
		free(tmp_2);
		i++;
	}
	if (ft_tablen(tmp) != 3 || !ft_tab_isnumber(tmp))
	{
		printf("Error : missing color\n");
		exit_img(dt->asset->no);
		exit_img(dt->asset->so);
		exit_img(dt->asset->ea);
		exit_img(dt->asset->we);
		exit_asset(dt->asset);
		mlx_destroy_image(dt->mlx, dt->img->img);
		free(dt->ray);
		exit_dt(dt);
		exit(EXIT_SUCCESS);
	}
	if (!ft_strncmp(line, "F", 1))
		atoi_color(dt, tmp, 'F');
	else
		atoi_color(dt, tmp, 'C');
	free_tmp(tmp);
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
	return (0);
}

void	error_color(char *line)
{
	if (check_virgule(line))
	{
		printf("Error: parsing color (,)\n");
		exit(0);
	}
}
