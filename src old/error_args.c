/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:51:09 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/30 20:25:32 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	error_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error :\n Wrong number of arguments\n");
		exit (EXIT_FAILURE);
	}
	if (check_cub(argv[1]) != 1)
	{
		ft_printf("Error :\n Wrong map, please insert a .cub map\n");
		exit (EXIT_FAILURE);
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
