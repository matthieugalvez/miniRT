/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ratio.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:23:50 by achantra          #+#    #+#             */
/*   Updated: 2025/02/01 20:12:02 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	parse_ratio(char *data)
{
	double ratio;
	char **num;

	if (!ft_is_float(data))
		return (print_data_err(), -1);
	num = ft_split(data, '.');
	if (!num)
		return (perror("Error"), -1);
	ratio = ft_atof(num[0], num[1]);
	ft_free_tab(num);
	if (ratio < 0 || ratio > 1)
		return (print_data_err(), -1);
	return (ratio);
}