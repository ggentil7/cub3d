/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:24:29 by mthiesso          #+#    #+#             */
/*   Updated: 2023/01/13 11:46:06 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	exit_game(t_data *dt)
{
	int	i;

	i = 0;
	while (i < dt->map_width)
	{
		free(dt->map[i]);
		i++;
	}
	free(dt->map);
	free(dt);
	exit(EXIT_SUCCESS);
}
