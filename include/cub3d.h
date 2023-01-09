/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:34:54 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/09 17:33:26 by mthiesso         ###   ########.fr       */
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

typedef struct s_data
{
	void		*mlx;
	void		*window;
	t_imgptr	*img;
	int			x_map;
	int			y_map;
	char		**map;
	char		**asset;
	int			map_x;
	int			map_y;
	float		ppos_x;
	float		ppos_y;
	int			len_map;
	int			nb_line;
	int			tablen;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
}	t_data;

typedef struct s_asset
{
	char	*id;
	char	*path;
	int		r;
	int		g;
	int		b;
	int		nb_nswe;
	int		nb_color;
	char	**nswe;
	char	**color;
}	t_asset;

//map_check
int		check_wall(t_data *data);
int		check_map_char(char *line);
int		check_line_map(t_data *data, char *line);
int		check_map_closed(char **map, int width, int height);
int		check_borders(t_data *data);

//read_map
int		nb_of_asset(char *line);
int		read_map(t_data *data, t_asset *asset, char **args);
int		nb_line(t_data *dt, char **args, int number);
void	parse_file(t_data *dt, t_asset *asset, char *line, int i);

//error_args
int		error_args(int argc, char **argv);
int		check_cub(char *c);

//map_utils
int		empty_line(char *line, int i);
int		find_char(char *line, char c);
int		is_space(int c);
char	*ft_strndup(const char *s, int n);
int		ft_tablen(char **tab);

//init
int		init_game(t_data *dt);
int		init_asset(t_asset *asset);

//minimap
int		minimap_display(t_data *dt);
void	minimap_printer(t_data *dt, int i, int j, char c);
void	my_pixel(t_data *dt, int x, int y, int color);
void	my_square_pixel(t_data *dt, int x, int y, int color);
void	my_player_pixel(t_data *dt, int x, int y, int color);

//raycasting
int		screen_display(t_data *dt);

//check_asset
int		check_asset(t_asset *asset, t_data *data, char *line);
int		check_no(t_asset *asset, t_data *data);
int		check_so(t_asset *asset, t_data *data);
int		check_we(t_asset *asset, t_data *data);
int		check_ea(t_asset *asset, t_data *data);

//check_asset2
int		check_f(t_asset *asset, t_data *data);
int		check_c(t_asset *asset, t_data *data);
int		check_asset_id(t_asset *asset, t_data *data);
int		malloc_asset(t_data *data);
int		error_format(t_asset *asset);
void 	free_asset(t_asset *asset);

//exit
int		exit_game(t_data *dt);

//moves
int		where_to_go(int keycode, t_data *dt);

#endif