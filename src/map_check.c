/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:41:30 by ggentil           #+#    #+#             */
/*   Updated: 2022/12/20 16:44:36 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	error_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error :\n Wrong number of arguments\n");
		exit (EXIT_SUCCESS);
	}
	if (check_cub(argv[1]) != 1)
	{
		ft_printf("Error :\n Wrong map, please insert a .cub map\n");
		exit (EXIT_SUCCESS);
	}
	return (0);
}

int	check_cub(char *c)
{
	int	i;

	i = ft_strlen(c);
	if (c[--i] == 'b')
	{
		if (c[--i] == 'u')
		{
			if (c[--i] == 'c')
				return (1);
		}
	}
	return (0);
}

/*int	check_wall(char **tab, int lon, int larg)
{
	
}*/

int	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != '\v' && line[i] != '\f' && line[i] != '\0')
			return (1);
		i++;
	}
	return (0);
}
