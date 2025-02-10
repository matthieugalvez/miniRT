/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:00:53 by achantra          #+#    #+#             */
/*   Updated: 2025/02/10 17:02:57 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

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

int	check_coordinates(t_coordinates *coord, char **num, char c)
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
	if (check_coordinates(coord, num, 'x'))
		return (ft_freetab(num), free(coord), print_data_err("coord"), NULL);
	ft_freetab(num);
	num = ft_split(num2, '.');
	if (!num)
		return (perror("Error"), NULL);
	if (check_coordinates(coord, num, 'y'))
		return (ft_freetab(num), free(coord), print_data_err("coord"), NULL);
	ft_freetab(num);
	num = ft_split(num3, '.');
	if (!num)
		return (perror("Error"), NULL);
	if (check_coordinates(coord, num, 'z'))
		return (ft_freetab(num), free(coord), print_data_err("coord"), NULL);
	return (ft_freetab(num), coord);
}

t_coordinates	*parse_coordinates(char *data)
{
	t_coordinates	*coord;
	char			**num;

	if (count_coma(data) != 2)
		return (print_data_err("coord"), NULL);
	num = ft_split(data, ',');
	if (!num)
		return (perror("Error"), NULL);
	if (!ft_is_float(num[0]) || !ft_is_float(num[1]) || !ft_is_float(num[2]))
		return (ft_freetab(num), print_data_err("coord"), NULL);
	coord = ft_coordinates(num[0], num[1], num[2]);
	return (ft_freetab(num), coord);
}

t_coordinates	*parse_vector(char *data)
{
	t_coordinates	*vector;
	char			**num;

	if (count_coma(data) != 2)
		return (print_data_err("vector"), NULL);
	num = ft_split(data, ',');
	if (!num)
		return (perror("Error"), NULL);
	if (!ft_is_float(num[0]) || !ft_is_float(num[1]) || !ft_is_float(num[2]))
		return (ft_freetab(num), print_data_err("vector"), NULL);
	vector = ft_coordinates(num[0], num[1], num[2]);
	if (!vector)
		return (ft_freetab(num), NULL);
	if (vector->x < -1 || vector->y < -1 || vector->z < -1 || vector->x > 1
		|| vector->y > 1 || vector->z > 1)
		return (free(vector), ft_freetab(num), print_data_err("vector"), NULL);
	if (equal_double(vector->x, 0) && equal_double(vector->y, 0)
		&& equal_double(vector->z, 0))
		return (free(vector), ft_freetab(num), print_data_err("vector"), NULL);
	return (ft_freetab(num), vector);
}
