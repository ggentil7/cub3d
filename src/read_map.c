/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielagentil <gabrielagentil@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 09:53:36 by gabrielagen       #+#    #+#             */
/*   Updated: 2022/12/27 10:40:45 by gabrielagen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	read_map(t_data *data, char **map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(*map, O_RDONLY);
	line = get_next_line(fd);
	if (fd == -1)
	{
		ft_printf("Error:\n map error\n");
		exit (EXIT_SUCCESS);
	}
	
}
