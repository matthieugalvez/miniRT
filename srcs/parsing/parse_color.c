/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:21:11 by achantra          #+#    #+#             */
/*   Updated: 2025/02/12 16:38:27 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	ft_is_color(char *data)
{
	int	i;
	int	n_coma;
	int	len_data;

	i = 0;
	n_coma = 0;
	len_data = ft_strlen(data);
	while (data[i])
	{
		if (!ft_isdigit(data[i]))
		{
			if (i == 0 || i == len_data - 1 || !(data[i] == ',')
				|| !ft_isdigit(data[i - 1]) || n_coma > 1)
				return (ft_putstr("Error: wrong data: color\n", 2), 0);
			else
				n_coma += 1;
		}
		i++;
	}
	return (1);
}

t_color	*ft_color(char *num1, char *num2, char *num3)
{
	t_color	*color;

	if (ft_strlen(num1) > 3 || ft_strlen(num2) > 3 || ft_strlen(num3) > 3)
		return (ft_putstr("Error: wrong data: color\n", 2), NULL);
	color = ft_calloc(sizeof(t_color), 1);
	if (!color)
		return (perror("Error"), NULL);
	color->r = ft_atoi(num1);
	color->g = ft_atoi(num2);
	color->b = ft_atoi(num3);
	if (color->r > 255 || color->g > 255 || color->b > 255 || color->r < 0
		|| color->g < 0 || color->b < 0)
		return (free(color), ft_putstr("Error: wrong data: color\n", 2), NULL);
	return (color);
}

t_color	*parse_color(char *data)
{
	t_color	*color;
	char	**num;

	if (!ft_is_color(data))
		return (NULL);
	num = ft_split(data, ',');
	if (!num)
		return (perror("Error"), NULL);
	color = ft_color(num[0], num[1], num[2]);
	return (ft_freetab(num), color);
}
