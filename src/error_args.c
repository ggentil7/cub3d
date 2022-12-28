/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:51:09 by ggentil           #+#    #+#             */
/*   Updated: 2022/12/28 11:54:35 by ggentil          ###   ########.fr       */
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