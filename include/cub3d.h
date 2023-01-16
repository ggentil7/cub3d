/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:34:54 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/16 16:00:49 by ggentil          ###   ########.fr       */
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
# include <limits.h>
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
# define RED 		0x00FF0000
# define YEL 		0x00FFFF00
# define GREEN 		0x003AFF00
# define GRE 		0x00808080
# define BLU 		0x00002EFF
# define WHI 		0x00FFFFFF

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

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int		floor;
	int		ceiling;
}	t_color;

typedef struct s_asset
{
	char	*path;
	t_color	floor;
	t_color	ceiling;
	int		r;
	int		g;
	int		b;
	int		nb_nswe;
	int		nb_color;
	char	**nswe;
	char	**color;
}	t_asset;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	t_imgptr	*img;
	int			x_map;
	int			y_map;
	char		**map;
	int			map_height;
	int			map_width;
	float		ppos_x;
	float		ppos_y;
	int			len_map;
	int			nb_line;
	int			tablen;
	t_asset		*asset;
}	t_data;

//map_check
int		check_map_char(t_data *dt);
int		check_borders(t_data *dt);

//read_map
int		nb_of_asset(char *line);
int		read_map(t_data *data, char **args);
int		nb_line(t_data *dt, char **args, int number);
int		error_map(t_data *dt, char **args);
void	calloc_asset(t_data *dt);

//parsing_file
int		parse_file(t_data *dt, char *line, int i);
int		parse_nswe(t_data *dt, char *line, int i);
int		parse_color(t_data *dt, char *line, int i);
int		parse_map(t_data *dt, char *line, int i);
int		error_asset(t_data *dt);

//error_args
int		error_args(int argc, char **argv);
int		check_cub(char *c);

//map_utils
int		empty_line(char *line, int i);
int		find_char(char *line, char c);
int		is_space(int c);
int		ft_tab_isnumber(char **tab);

//init
int		init_game(t_data *dt);
int		init_asset(t_data *dt);
void	init_file(t_data *dt, char **args);
void	init_color(t_color *color);
void	init_map(t_data *dt);

//minimap
int		minimap_display(t_data *dt);
void	minimap_printer(t_data *dt, int i, int j, char c);
void	my_pixel(t_data *dt, int x, int y, int color);
void	my_square_pixel(t_data *dt, int x, int y, int color);
void	my_player_pixel(t_data *dt, int x, int y, int color);

//raycasting
int		screen_display(t_data *dt);

//check_asset
int		check_path(t_data *dt);
int		check_valid_path(t_data *dt, char *line);
int		check_color(t_data *dt, char *line);
int		parse_color2(t_data *dt, char *line);

//check_asset_utils
int		atoi_color(t_asset *asset, char **color);
int		check_virgule(char *line);
int		check_setting_color(t_data *dt);

//exit
int		exit_game(t_data *dt);

//errors
int		errorminator(t_data *dt, char **args);

//moves
int		where_to_go(int keycode, t_data *dt);

#endif