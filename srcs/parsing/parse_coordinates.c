/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:00:53 by achantra          #+#    #+#             */
/*   Updated: 2025/02/01 20:14:24 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_is_coordinates(char *data)
{
	int i;
	int n_coma;
	int len_data;

	i = 0;
	n_coma = 0;
	len_data = ft_strlen(data);
	while (data[i])
	{
		if (!ft_isdigit(data[i]))
		{
			if (data[i] == '-' || data[i] == '+')
			{
				if (!(i == 0 || data[i - 1] == ','))
					return (print_data_err(), 0);
			}
			else if (data[i] == '.' || data[i] == ',')
			{
				if (i == 0 || i == len_data - 1 || !ft_isdigit(data[i - 1]))
					return (print_data_err(), 0);
			}
			else if (n_coma > 1)
				return (print_data_err(), 0);
			else
				n_coma += 1;
		}
		i++;
	}
	return (1);
}

t_coordinates	*ft_coordinates(char *num1, char *num2, char *num3)
{
	t_coordinates	*coord;

	coord = malloc(sizeof(t_coordinates));
	if (!coord)
		return (perror("Error"), NULL);
	coord->x = ft_atof(num1);
	coord->y = ft_atof(num2);
	coord->z = ft_atof(num3);
	return (coord);
}