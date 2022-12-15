/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:41:30 by ggentil           #+#    #+#             */
/*   Updated: 2022/12/15 15:47:23 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error :\n Wrong number of arguments\n");
		exit (EXIT_SUCCESS);
	}
	if (check_cub(argv[1]) != 1)
	{
		ft_printf("Error :\n Wrong map, please insert a .ber map\n");
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
