/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 09:53:36 by gabrielagen       #+#    #+#             */
/*   Updated: 2023/01/10 15:15:18 by mthiesso         ###   ########.fr       */
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
	int		i;

	i = 0;
	fd = open(*args, O_RDONLY);
	dt->asset->nb_nswe = nb_line(dt, args, 1);
	dt->asset->nb_color = nb_line(dt, args, 2);
	dt->len_map = nb_line(dt, args, 3);
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
	dt->map = ft_calloc(dt->len_map + 1, sizeof(char *));
	dt->asset->nswe = ft_calloc(dt->asset->nb_nswe + 1, sizeof(char *));
	dt->asset->color = ft_calloc(dt->asset->nb_color + 1, sizeof(char *));
	while (i < dt->nb_line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		else if (nb_of_asset(line) != 0)
			i = parse_file(dt, line, i);
		free(line);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	parse_file(t_data *dt, char *line, int i)
{
	int	j;

	if (nb_of_asset(line) == 1)
	{
		j = ft_tablen(dt->asset->nswe);
		dt->asset->nswe[j] = ft_strdup(line);
		printf("nswe[%d] : %s", j, dt->asset->nswe[j]);
		i++;
		return (i);
	}
	else if (nb_of_asset(line) == 2)
	{
		j = ft_tablen(dt->asset->color);
		dt->asset->color[j] = ft_strdup(line);
		printf("color[%d] : %s", j, dt->asset->color[j]);
		i++;
		return (i);
	}
	else if (nb_of_asset(line) == 3)
	{
		j = ft_tablen(dt->map);
		dt->map[j] = ft_strdup(line);
		printf("map[%d] : %s", j, dt->map[j]);
		i++;
		return (i);
	}
	return (i);
}
