/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:36:06 by achantra          #+#    #+#             */
/*   Updated: 2025/02/01 19:21:45 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Ajouter une gestion des overflow

int	ft_is_float(char *data)
{
	int	i;
	int	n_float;
	int	len_data;

	i = 0;
	n_float = 0;
	len_data = ft_strlen(data);
	while (data[i])
	{
		if (!ft_isdigit(data[i]))
		{
			if (i == 0 || i == len_data - 1 || !(data[i] == '.'))
				return (0);
			else if (n_float)
				return (0);
			else
				n_float = 1;
		}
		i++;
	}
	return (1);
}

double	ft_atof(char *num1, char *num2)
{
	int		len_num2;
	double	res;

	if (!num2)
		return (ft_atoi(num1));
	len_num2 = 0;
	while (num2[len_num2])
		len_num2++;
	while (num2[len_num2 - 1] == '0')
		len_num2--;
	res = ft_atoi(num1) + (ft_atoi(num2) / pow(10, len_num2));
	return (res);
}
