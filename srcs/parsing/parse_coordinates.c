/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:00:53 by achantra          #+#    #+#             */
/*   Updated: 2025/02/01 21:11:19 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	count_coma(char *data)
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

t_coordinates	*ft_coordinates(char *num1, char *num2, char *num3)
{
	t_coordinates	*coord;
	char			**num;

	coord = malloc(sizeof(t_coordinates));
	if (!coord)
		return (perror("Error"), NULL);
	num = ft_split(num1, '.');
	if (!num)
		return (perror("Error"), NULL);
	coord->x = ft_atof(num[0], num[1]);
	ft_free_tab(num);
	num = ft_split(num2, '.');
	if (!num)
		return (perror("Error"), NULL);
	coord->y = ft_atof(num[0], num[1]);
	ft_free_tab(num);
	num = ft_split(num3, '.');
	if (!num)
		return (perror("Error"), NULL);
	coord->z = ft_atof(num[0], num[1]);
	ft_free_tab(num);
	return (coord);
}

t_coordinates	*parse_coordinates(char *data)
{
	t_coordinates	*coord;
	char			**num;
	int				i;

	if (count_coma(data) != 2)
		return (print_data_err(), NULL);
	num = ft_split(data, ',');
	if (!num)
		return (perror("Error"), NULL);
	i = 0;
	while (i < 3)
	{
		if (!ft_is_float(num[i]))
			return (ft_free_tab(num), print_data_err(), NULL);
		i ++;
	}
	coord = ft_coordinates(num[0], num[1], num[2]);
	ft_free_tab(num);
	return (coord);
}
