/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 09:53:36 by gabrielagen       #+#    #+#             */
/*   Updated: 2023/01/05 17:08:48 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// int	read_map_asset(char *args, t_data *data, t_asset *asset)
// {
// 	int		fd;
// 	char	*line;

// 	init_asset(asset);
// 	malloc_asset(data);
// 	fd = open(args, O_RDONLY);
// 	printf("fd: %d\n", fd);
// 	if (fd == -1)
// 	{
// 		printf("Error: map error\n");
// 		exit (EXIT_SUCCESS);
// 	}
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		if (check_asset(asset, data, line) == -1)
// 		{
// 			printf("Error: map error\n");
// 			free (line);
// 			line = get_next_line(fd);
// 		}
// 		free (line);
// 	}
// 	return (0);
// }

int    nb_of_asset(char *line, t_asset *asset)
{
    int    i;

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
    return (0);
}
int	nb_line(char **args)
{
	int		fd;
	int		i;
	char	*tmp;
	t_asset	*asset;

	i = 0;
	asset = NULL;
	fd = open(*args, O_RDONLY);
	tmp = get_next_line(fd);
	printf("tmp : %s\n", tmp);
	while (tmp || nb_of_asset(tmp, asset) != 1)
	{
		free(tmp);
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break;
		i++;
	}
	close(fd);
	printf("nb line : [%d]\n", i);
	return (i);
}

int	read_map(t_data *dt, char **args)
{
	int		fd;
	char	*line;
	int		i;

	i = -1;
	fd = open(*args, O_RDONLY);
	dt->nb_line = nb_line(args);
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
	while (++i < dt->nb_line)
	{
		line = get_next_line(fd);
		dt->map[i] = ft_strdup(line);
		printf("line[%d] : %s", i, dt->map[i]);
		free(line);
	}
	close(fd);
	return(EXIT_SUCCESS);
}
