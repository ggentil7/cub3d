/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:22:49 by mthiesso          #+#    #+#             */
/*   Updated: 2023/01/04 16:34:21 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	where_to_go(int	keycode, t_data *dt)
{
	if (keycode == ESC)
		exit_game(dt);
	// else if (keycode == W_KEY)
	// 	straight_move(dt);
	// else if (keycode == A_KEY)
	// 	left_move(dt);
	// else if (keycode == S_KEY)
	// 	back_move(dt);
	// else if (keycode == D_KEY)
	// 	right_move(dt);
	return (EXIT_SUCCESS);
}