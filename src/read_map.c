/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 09:53:36 by gabrielagen       #+#    #+#             */
/*   Updated: 2023/01/09 17:49:43 by mthiesso         ###   ########.fr       */
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

int	read_map(t_data *dt, t_asset *asset, char **args)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(*args, O_RDONLY);
	asset->nb_nswe = nb_line(dt, args, 1);
	asset->nb_color = nb_line(dt, args, 2);
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
	dt->map = malloc(sizeof(char *) * (dt->len_map + 1));
	asset->nswe = malloc(sizeof(char *) * (asset->nb_nswe + 1));
	asset->color = malloc(sizeof(char *) * (asset->nb_color + 1));
	while (i < dt->nb_line)
	{
		line = get_next_line(fd);
		if (nb_of_asset(line) != 0)
			i = parse_file(dt, asset, line);
		free(line);
		i++;
	}
	close(fd);
	return (EXIT_SUCCESS);
}

void	parse_file(t_data *dt, t_asset *asset, char *line, int i)
{
	if (nb_of_asset(line) == 1)
	{
		asset->nswe[i] = ft_strdup(line);
		printf("nswe [%d] : %s", i)
	}
	else if (nb_of_asset(line) == 2)
		asset->color[i] = ft_strdup(line);
	else if (nb_of_asset(line) == 3)
		dt->map[i] = ft_strdup(line);
}

// TROUVER UNE SOLUTION POUR LE I CAR ON ECRIT LA OU IL FAUT PAS !!
