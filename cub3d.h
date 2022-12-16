/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielagentil <gabrielagentil@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:34:54 by ggentil           #+#    #+#             */
/*   Updated: 2022/12/16 14:15:28 by gabrielagen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include "./libft/libft.h"
# include "./mlx/mlx.h"

# define LEFT_KEY	123
# define RIGHT_KEY	124
# define UP_KEY	126
# define DOWN_KEY	125
# define A_KEY	0
# define S_KEY	1
# define D_KEY	2
# define W_KEY	13
# define ESC	53

typedef struct s_mlx
{
	void	*mlx;
	void	*win;

}		t_mlx;

//map_check
int	error_args(int argc, char **argv);
int	check_cub(char *c);
int	check_wall(char **tab, int lon, int larg);
int	empty_line(char *line);

#endif