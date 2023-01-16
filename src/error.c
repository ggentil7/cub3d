/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:00:07 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/16 16:00:19 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	errorminator(t_data *dt, char **args)
{
	if (init_game(dt) < 0)
		return (EXIT_FAILURE);
	else if (init_asset(dt) < 0)
		return (EXIT_FAILURE);
	else if (read_map(dt, args) < 0)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}
