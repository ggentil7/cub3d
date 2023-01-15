/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiesso <mthiesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:32:02 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/15 18:22:55 by mthiesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumber(char *str)
{
	int	i;
	int	len;

	if (!str)
		return (0);
	i = 0;
	len = ft_strlen(str);
	if (str[0] == '-')
		i++;
	while (ft_isdigit(str[i]))
			i++;
	if (i < len)
		return (0);
	return (1);
}
