/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 09:41:17 by gabrielagen       #+#    #+#             */
/*   Updated: 2023/01/05 15:39:37 by mthiesso         ###   ########.fr       */
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

char	*ft_strndup(const char *s, int n)
{
    char	*result;
    int	len;

	len = ft_strlen(s);
	if (n < len)
		len = n;
	result = (char *) malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	return ((char *) ft_memcpy(result, s, len));
}
// Cette fonction prend en paramètres une chaîne de caractères s
//et un entier n, et renvoie une copie allouée dynamiquement de la chaîne 
//s jusqu'au n-ième caractère (inclus). Si n est supérieur à la longueur
//de la chaîne s, la copie sera de la longueur de s. 
//Si l'allocation de mémoire échoue, la fonction renvoie NULL.
