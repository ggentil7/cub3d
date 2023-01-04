/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 09:53:36 by gabrielagen       #+#    #+#             */
/*   Updated: 2023/01/04 18:09:04 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	read_map_asset(char *args, t_data *data, t_asset *asset)
{
	int		fd;
	int		i;
	//t_asset	*asset;
	char	*line;

	i = 0;
	fd = open(args, O_RDONLY);
	printf("fd : [%d]\n", fd);
	line = get_next_line(fd);
	printf("line map = %s\n", line);
	//check_asset(asset, data, line);
	if (fd == -1)
	{
		printf("Error: map error\n");
		exit (EXIT_SUCCESS);
	}
	while (get_next_line(fd))
	{
		printf("after gnl = %s\n", line);
		if (check_asset(asset, data, line) == -1)
			return (-1);
		else
		{
			printf("Error: map error\n");
			return (-1);
		}
		free (line);
	}
	return (0);
}
