/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:21:11 by achantra          #+#    #+#             */
/*   Updated: 2025/09/11 19:28:07 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	ft_color(char *num1, char *num2, char *num3, t_color *color)
{
	if (ft_strlen(num1) > 3 || ft_strlen(num2) > 3 || ft_strlen(num3) > 3)
	{
		ft_putstr("Error: wrong data: color\n", 2);
		return (1);
	}
	color->r = ft_atoi(num1);
	color->g = ft_atoi(num2);
	color->b = ft_atoi(num3);
	if (color->r > 255 || color->g > 255 || color->b > 255
		|| color->r < 0 || color->g < 0 || color->b < 0)
	{
		ft_putstr("Error: wrong data: color\n", 2);
		return (1);
	}
	return (0);
}

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
			{
				ft_putstr("Error: wrong data: color\n", 2);
				return (0);
			}
			else
				n_coma += 1;
		}
		i++;
	}
	return (1);
}

int	parse_color(char *data, t_color *color)
{
	char	**num;

	if (!ft_is_color(data))
		return (1);
	num = ft_split(data, ',');
	if (!num)
	{
		perror("Error");
		return (1);
	}
	if (ft_color(num[0], num[1], num[2], color))
	{
		ft_freetab(num);
		return (1);
	}
	ft_freetab(num);
	return (0);
}

int	parse_figure_color_data(t_element *figure, t_env *env, char *data)
{
	t_color	*next_color;

	if (!figure->color_cmpt)
		next_color = &figure->color;
	else if (figure->color_cmpt == 1)
		next_color = &figure->colorbis;
	if (!ft_strrncmp(data, ".xpm", 4))
	{
		if (!figure->color_cmpt && !figure->texture_cmpt)
		{
			figure->texture_cmpt += 1;
			return (parse_xpm_file(env, &figure->texture, data));
		}
		else if (figure-> id == SPHERE)
		{
			figure->bump_map_cmpt += 1;
			return (parse_xpm_file(env, &figure->bump_map, data));
		}
		ft_putstr("Error: wrong data: color\n", 2);
		return (1);
	}
	figure->color_cmpt += 1;
	return (parse_color(data, next_color));
}
