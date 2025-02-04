/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operator2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:30:17 by achantra          #+#    #+#             */
/*   Updated: 2025/02/04 19:06:08 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	scalar_prod_vec(t_coordinates v1, t_coordinates v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

void	normalize_vec(t_coordinates *vector)
{
	double	norm;
	if (vector->x == 0 && vector->y == 0 && vector->z == 0)
		return ;
	norm = sqrt(pow(vector->x, 2) + pow(vector->y, 2) + pow(vector->z, 2));
	*vector = divide_vec(*vector, norm);
}