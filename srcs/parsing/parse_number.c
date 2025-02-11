/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:48:37 by achantra          #+#    #+#             */
/*   Updated: 2025/02/11 20:13:13 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	parse_ratio(char *data)
{
	double	ratio;
	char	**num;

	if (!ft_is_float(data))
		return (ft_putstr("Error: wrong data: ratio\n", 2), -1);
	num = ft_split(data, '.');
	if (!num)
		return (perror("Error"), -1);
	if (ft_strlen(num[0]) > 11 || ft_strlen(num[1]) > 11)
		return (ft_freetab(num), ft_putstr("Error: wrong data: ratio\n", 2), -1);
	ratio = ft_atof(num[0], num[1]);
	ft_freetab(num);
	if (ratio < 0 || ratio > 1)
		return (ft_putstr("Error: wrong data: ratio\n", 2), -1);
	return (ratio);
}

double	parse_fov(char *data)
{
	double	fov;
	char	**num;

	if (!ft_is_float(data))
		return (ft_putstr("Error: wrong data: fov\n", 2), -1);
	num = ft_split(data, '.');
	if (!num)
		return (perror("Error"), -1);
	if (ft_strlen(num[0]) > 11 || ft_strlen(num[1]) > 11)
		return (ft_freetab(num), ft_putstr("Error: wrong data: fov\n", 2), -1);
	fov = ft_atof(num[0], num[1]);
	ft_freetab(num);
	if (fov < 0 || fov > 180)
		return (ft_putstr("Error: wrong data: fov\n", 2), -1);
	return (fov);
}

double	parse_length(char *data)
{
	double	number;
	char	**num;

	if (!ft_is_float(data))
		return (ft_putstr("Error: wrong data: length\n", 2), -1);
	num = ft_split(data, '.');
	if (!num)
		return (perror("Error"), -1);
	if (ft_strlen(num[0]) > 11 || ft_strlen(num[1]) > 11)
		return (ft_freetab(num),
			ft_putstr("Error: wrong data: length\n", 2), -1);
	number = ft_atof(num[0], num[1]);
	ft_freetab(num);
	return (number);
}
