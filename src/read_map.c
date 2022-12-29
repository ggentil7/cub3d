/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 09:53:36 by gabrielagen       #+#    #+#             */
/*   Updated: 2022/12/29 16:50:01 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*int	read_map(t_data *data, char **map)
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
	
}*/

int	read_map(t_data *data, char *args)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(args, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error:\n map error\n");
		exit (EXIT_SUCCESS);
	}
}
