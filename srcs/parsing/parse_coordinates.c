/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:00:53 by achantra          #+#    #+#             */
/*   Updated: 2025/02/13 16:01:02 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	check_coordinates(t_coordinates *coord, char **num, char c)
{
	if (ft_strlen(num[0]) > 11 || ft_strlen(num[1]) > 11)
		return (1);
	else if (c == 'x')
		coord->x = ft_atof(num[0], num[1]);
	else if (c == 'y')
		coord->y = ft_atof(num[0], num[1]);
	else if (c == 'z')
		coord->z = ft_atof(num[0], num[1]);
	return (0);
}

static int	get_coordinate(t_coordinates *coord, char *num, char axis)
{
	char	**splited_num;

	splited_num = ft_split(num, '.');
	if (!splited_num)
	{
		perror("Error");
		free(coord);
		return (1);
	}
	if (check_coordinates(coord, splited_num, axis))
	{
		ft_freetab(splited_num);
		free(coord);
		ft_putstr("Error: wrong data: coord\n", 2);
		return (1);
	}
	ft_freetab(splited_num);
	return (0);
}

static t_coordinates	*ft_coordinates(char *num1, char *num2, char *num3)
{
	t_coordinates	*coord;

	coord = ft_calloc(sizeof(t_coordinates), 1);
	if (!coord)
	{
		perror("Error");
		return (NULL);
	}
	if (get_coordinate(coord, num1, 'x'))
		return (NULL);
	if (get_coordinate(coord, num2, 'y'))
		return (NULL);
	if (get_coordinate(coord, num3, 'z'))
		return (NULL);
	return (coord);
}

static int	count_coma(char *data)
{
	int	i;
	int	n_coma;
	int	len_data;

	i = 0;
	n_coma = 0;
	len_data = ft_strlen(data);
	while (data[i])
	{
		if (data[i] == ',')
		{
			if (i == 0 || i == len_data - 1 || !ft_isdigit(data[i - 1]))
				return (0);
			else
				n_coma += 1;
		}
		i++;
	}
	return (n_coma);
}

t_coordinates	*parse_coordinates(char *data)
{
	t_coordinates	*coord;
	char			**num;

	if (count_coma(data) != 2)
	{
		ft_putstr("Error: wrong data: coord\n", 2);
		return (NULL);
	}
	num = ft_split(data, ',');
	if (!num)
	{
		perror("Error");
		return (NULL);
	}
	if (!ft_is_float(num[0]) || !ft_is_float(num[1]) || !ft_is_float(num[2]))
	{
		ft_freetab(num);
		ft_putstr("Error: wrong data: coord\n", 2);
		return (NULL);
	}
	coord = ft_coordinates(num[0], num[1], num[2]);
	ft_freetab(num);
	return (coord);
}
