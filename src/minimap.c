/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:41:12 by mthiesso          #+#    #+#             */
/*   Updated: 2022/12/22 17:33:52 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	minimap_display(t_data *dt)
{
	(void)	dt;
	char	**hc;
	int		i = 0;

	hc = malloc(sizeof(char *) * 5);
	while (i < 5)
	{
		hc[i] = malloc(sizeof(char) * 5);
	}
	hc[0] = "1111";
	hc[1] = "1001";
	hc[2] = "1001";
	hc[3] = "1111";
	hc[4] = NULL;
	return (0);
}