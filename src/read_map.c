/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 09:53:36 by gabrielagen       #+#    #+#             */
/*   Updated: 2023/01/08 21:44:07 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	nb_of_asset(char *line, t_asset *asset)
{
	int	i;

	i = -1;
	if (line == NULL)
	{
		printf("Error : %s\n", line);
		return (EXIT_FAILURE);
	}
	while (line[++i] != '\0')
	{
		if (ft_strchr("NSWE", line[i]))
		{
			asset->nb_nswe++;
			return (0);
		}
		else if (ft_strchr("FC", line[i]))
		{
			asset->nb_color++;
			return (0);
		}
		else if (ft_strchr("01", line[i]))
			return (1);
	}
	printf("nb_asset : %d\n", (asset->nb_color + asset->nb_nswe));
	return (0);
}

int	nb_line(t_asset *asset, char **args)
{
	int		fd;
	int		i;
	char	*tmp;

	i = 0;
	asset = NULL;
	fd = open(*args, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp || nb_of_asset(tmp, asset) != 1)
	{
		free(tmp);
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		i++;
	}
	close(fd);
	printf("nb line : [%d]\n", i);
	return (i);
}

int	read_map(t_data *dt, t_asset *asset, char **args)
{
	int		fd;
	char	*line;
	int		i;

	i = -1;
	fd = open(*args, O_RDONLY);
	dt->nb_line = nb_line(asset, args);
	if (dt->nb_line == 0)
	{
		ft_printf("Error\n");
		return (EXIT_FAILURE);
	}
	if (fd == -1)
	{
		ft_printf("Error:\n map error\n");
		exit (EXIT_FAILURE);
	}
	dt->map = malloc(sizeof(char *) * dt->nb_line);
	dt->asset = malloc(sizeof(char *) * 7); //A MODIFIER
	while (++i < dt->nb_line)
	{
		line = get_next_line(fd);
		while (i < dt->nb_line && nb_of_asset(line, asset) != 1)
		{
			dt->asset[i] = ft_strdup(line);
			line = get_next_line(fd);
			i++;
		}
		dt->map[dt->tablen] = ft_strdup(line);
		printf("map[%d] : %s", dt->tablen, dt->map[dt->tablen]);
		free(line);
		dt->tablen++;
	}
	i = 0;
	while (i < 7)
	{
		printf("asset[%d] : %s", i, dt->asset[i]);
		i++;
	}
	close(fd);
	return (EXIT_SUCCESS);
}
