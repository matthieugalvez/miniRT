/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:48:37 by achantra          #+#    #+#             */
/*   Updated: 2025/02/02 15:30:07 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	parse_ratio(char *data)
{
	double	ratio;
	char	**num;

	if (!ft_is_float(data))
		return (print_data_err("ratio"), -1);
	num = ft_split(data, '.');
	if (!num)
		return (perror("Error"), -1);
	if (ft_strlen(num[0]) > 11 || ft_strlen(num[1]) > 11)
		return (ft_free_tab(num), print_data_err("ratio"), -1);
	ratio = ft_atof(num[0], num[1]);
	ft_free_tab(num);
	if (ratio < 0 || ratio > 1)
		return (print_data_err("ratio"), -1);
	return (ratio);
}

double	parse_fov(char *data)
{
	double	fov;
	char	**num;

	if (!ft_is_float(data))
		return (print_data_err("fov"), -1);
	num = ft_split(data, '.');
	if (!num)
		return (perror("Error"), -1);
	if (ft_strlen(num[0]) > 11 || ft_strlen(num[1]) > 11)
		return (ft_free_tab(num), print_data_err("fov"), -1);
	fov = ft_atof(num[0], num[1]);
	ft_free_tab(num);
	if (fov < 0 || fov > 180)
		return (print_data_err("fov"), -1);
	return (fov);
}

double	parse_length(char *data)
{
	double	number;
	char	**num;

	if (!ft_is_float(data))
		return (print_data_err("length"), -1);
	num = ft_split(data, '.');
	if (!num)
		return (perror("Error"), -1);
	if (ft_strlen(num[0]) > 11 || ft_strlen(num[1]) > 11)
		return (ft_free_tab(num), print_data_err("length"), -1);
	number = ft_atof(num[0], num[1]);
	ft_free_tab(num);
	return (number);
}
