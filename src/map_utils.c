/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 09:41:17 by gabrielagen       #+#    #+#             */
/*   Updated: 2023/01/12 15:29:53 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	empty_line(char *line, int i)
{
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
			&&line[i] != '\v' && line[i] != '\f' && line[i] != '\0')
			return (1);
		i++;
	}
	return (0);
}

int	find_char(char *line, char c)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	is_space(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r');
}

// char	*ft_strndup(const char *s, int n)
// {
//     char	*result;
//     int	len;

// 	len = ft_strlen(s);
// 	if (n < len)
// 		len = n;
// 	result = (char *) malloc(len + 1);
// 	if (!result)
// 		return (NULL);
// 	result[len] = '\0';
// 	return ((char *) ft_memcpy(result, s, len));
// }

// int	ft_tablen(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }
