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
