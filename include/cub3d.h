/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:34:54 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/04 10:52:24 by ggentil          ###   ########.fr       */
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
# define MAP_SIZE	10
# define LEFT_KEY	123
# define RIGHT_KEY	124
# define UP_KEY		126
# define DOWN_KEY	125
# define A_KEY		0
# define S_KEY		1
# define D_KEY		2
# define W_KEY		13
# define ESC		53

typedef struct s_imgptr
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

typedef struct s_data
{
	void		*mlx;
	void		*window;
	t_imgptr	*img;
	int			x_map;
	int			y_map;
	char		**map;
	int			map_x;
	int			map_y;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	// int			f;
	// int			c;
}	t_data;

typedef struct s_asset
{
	char	*id;
	char	*path;
}	t_asset;
//map_check
int		check_wall(t_data *data);
int		check_map_char(char *line);
int		is_map(t_data *data, char *line);
int		check_map_closed(char **map, int width, int height);
int		check_borders(t_data *data);

//read_map
int		read_map(t_data *data, char **map);

//error_args
int		error_args(int argc, char **argv);
int		check_cub(char *c);

//map_utils
int		empty_line(char *line);
int		find_char(char *line, char c);
int		is_space(int c);
char	*ft_strndup(const char *s, int n);

//init
int		init_game(t_data *dt);
int		init_asset(t_asset *asset);

//minimap
int		minimap_display(t_data *dt);
void	minimap_printer(t_data *dt, int i, int j, char c);
void	my_pixel(t_data *dt, int x, int y, int color);
void	my_square_pixel(t_data *dt, int x, int y, int color);

//raycasting
int		screen_display(t_data *dt);

//check_asset
int		check_asset(t_asset *asset, char *line);
int		check_no(t_asset *asset);
int		check_so(t_asset *asset);
int		check_we(t_asset *asset);
int		check_ea(t_asset *asset);

//check_asset2
int		check_f(t_asset *asset);
int		check_c(t_asset *asset);
int		check_asset_id(t_asset *asset);
int		calloc_asset(t_data *data);

#endif