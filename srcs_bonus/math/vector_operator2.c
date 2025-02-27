/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operator2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:30:17 by achantra          #+#    #+#             */
/*   Updated: 2025/02/27 13:58:30 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

t_coordinates	*new_vec(double x, double y, double z)
{
	t_coordinates	*vec;

	vec = ft_calloc(sizeof(t_coordinates), 1);
	if (!vec)
		return (NULL);
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

double	scalar_prod_vec(t_coordinates v1, t_coordinates v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double	get_norm(t_coordinates vector)
{
	double	norm;

	if (equal_double(vector.x, 0) && equal_double(vector.y, 0)
		&& equal_double(vector.z, 0))
		return (0);
	norm = sqrt(vector.x * vector.x
			+ vector.y * vector.y
			+ vector.z * vector.z);
	return (norm);
}

void	normalize_vec(t_coordinates *vector)
{
	double	norm;

	if (equal_double(vector->x, 0) && equal_double(vector->y, 0)
		&& equal_double(vector->z, 0))
		return ;
	norm = get_norm(*(vector));
	*vector = div_vec(*vector, norm);
}

t_coordinates	*vect_prod_vec(t_coordinates v1, t_coordinates v2)
{
	t_coordinates	*vec;

	vec = ft_calloc(sizeof(t_coordinates), 1);
	if (!vec)
		return (NULL);
	vec->x = v1.y * v2.z - v1.z * v2.y;
	vec->y = v1.z * v2.x - v1.x * v2.z;
	vec->z = v1.x * v2.y - v1.y * v2.x;
	return (vec);
}
