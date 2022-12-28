/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielagentil <gabrielagentil@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:34:54 by ggentil           #+#    #+#             */
/*   Updated: 2022/12/27 10:40:36 by gabrielagen      ###   ########.fr       */
/*                                                                            */
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
# include "../utils/libft/libft.h"
# include "../utils/mlx/mlx.h"

# define WIN_X		1920
# define WIN_Y		1080
# define LEFT_KEY	123
# define RIGHT_KEY	124
# define UP_KEY		126
# define DOWN_KEY	125
# define A_KEY		0
# define S_KEY		1
# define D_KEY		2
# define W_KEY		13
# define ESC		53

typedef	struct s_imgptr
{
	char	*path;
	void	*img;
	int		width;
	int		height;
	int		*px;
	int		bytes;
	int		line;
	int		end;
}	t_imgptr;

typedef	struct s_data
{
	void		*mlx;
	void		*window;
	t_imgptr	*img;

}	t_data;


typedef struct s_data
{
	char	**map;
	int		map_x;
	int		map_y;
}	t_data;

//map_check
int	check_cub(char *c);
//int	check_wall(t_data *map, int lon, int larg);
//int	wall(char *str);
int	check_map(t_data *data);
int	check_map_char(char *line);
int	map(t_data *data, char *line);

//read_map
int	read_map(t_data *data, char **map);

//error_args
int	error_args(int argc, char **argv);

//map_utils
int	empty_line(char *line);

//init
int	init_game(t_data *dt);

//minimap
int	minimap_display(t_data *dt);

//raycasting
int	screen_display(t_data *dt);

#endif