/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 09:53:36 by gabrielagen       #+#    #+#             */
/*   Updated: 2023/01/17 16:26:09 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	nb_of_asset(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
	{
		printf("Error : %s\n", line);
		return (EXIT_FAILURE);
	}
	while (line[i] != '\0')
	{
		if (ft_strchr("NSWE", line[i]))
			return (1);
		else if (ft_strchr("FC", line[i]))
			return (2);
		else if (ft_strchr("01", line[i]))
			return (3);
		i++;
	}
	return (0);
}

int	nb_line(t_data *dt, char **args, int number)
{
	int		fd;
	int		i;
	char	*tmp;
	int		type;

	i = 0;
	type = 0;
	if (number == -1)
		return (EXIT_FAILURE);
	fd = open(*args, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		if (nb_of_asset(tmp) == number)
			type++;
		free(tmp);
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		i++;
	}
	dt->nb_line = i;
	close(fd);
	return (type);
}

int	read_map(t_data *dt, char **args)
{
	int		fd;
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	fd = open(*args, O_RDONLY);
	init_file(dt, args);
	error_map(dt, args);
	error_asset(dt);
	calloc_asset(dt);
	while (i < dt->nb_line)
	{
		line = get_next_line(fd);
		tmp = ft_strtrim(line, "\n\t ");
		if (tmp == NULL)
			break ;
		else if (nb_of_asset(tmp) != 0)
			i = parse_file(dt, tmp, i);
		free(line);
		free (tmp);
	}
	close(fd);
	check_borders(dt);
	check_map_char(dt);
	check_player(dt);
	replace_space_by_wall(dt);
	init_dir_player(dt);
	return (EXIT_SUCCESS);
}

int	error_map(t_data *dt, char **args)
{
	int	fd;

	fd = open(*args, O_RDONLY);
	if (dt->nb_line == 0)
	{
		ft_printf("Error\n");
		return (EXIT_FAILURE);
	}
	if (fd == -1)
	{
		ft_printf("Error:\n map error\n");
		return (EXIT_FAILURE);
	}
	close (fd);
	return (0);
}

void	calloc_asset(t_data *dt)
{
	dt->map = ft_calloc(dt->len_map + 1, sizeof(char *));
	dt->asset->nswe = ft_calloc(dt->asset->nb_nswe + 1, sizeof(char *));
	dt->asset->color = ft_calloc(dt->asset->nb_color + 1, sizeof(char *));
}
