/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asset2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:48:48 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/03 13:56:16 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_f(t_asset *asset)
{
	int	fd;

	fd = open(asset->path, O_RDONLY);
	if (!ft_strcmp(asset->id, "F"))
	{
		if (!*asset->path)
		{
			printf("Error: invalid floor texture path\n");
			return (-1);
		}
		if (fd == -1)
		{
			printf("Error: failed to open floor texture file\n");
			return (-1);
		}
		close (fd);
	}
	return (0);
}

int	check_c(t_asset *asset)
{
	int	fd;

	fd = open(asset->path, O_RDONLY);
	if (!ft_strcmp(asset->id, "C"))
	{
		if (!*asset->path)
		{
			printf("Error: invalid ceiling texture path\n");
			return (-1);
		}
		if (fd == -1)
		{
			printf("Error: failed to open ceiling texure path\n");
			return (-1);
		}
		close (fd);
	}
	return (0);
}
