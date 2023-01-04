/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 09:53:36 by gabrielagen       #+#    #+#             */
/*   Updated: 2023/01/04 16:45:01 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	read_map(t_data *data, t_asset *asset)
{
	int		fd;
	int		i;
	//t_asset	*asset;
	char	*line;

	i = 0;
	fd = open(line, O_RDONLY);
	line = get_next_line(fd);
	if (fd == -1)
	{
		printf("Error: map error\n");
		exit (EXIT_SUCCESS);
	}
	while (get_next_line(fd))
	{
		if (check_asset(asset, line) == -1)
			return (-1);
		else if (check_line_map(data, line))
		{
			if (check_wall(data) == -1)
				return (-1);
		}
		else
		{
			printf("Error: map error\n");
			return (-1);
		}
		free (line);
	}
	return (0);
}
