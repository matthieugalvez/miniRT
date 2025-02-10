/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:03:23 by achantra          #+#    #+#             */
/*   Updated: 2025/02/10 16:52:14 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_coordinates	change_vec(double x, double y, double z)
{
	t_coordinates	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_coordinates	add_vec(t_coordinates v1, t_coordinates v2)
{
	return (change_vec(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

t_coordinates	substract_vec(t_coordinates v1, t_coordinates v2)
{
	return (change_vec(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

t_coordinates	multiply_vec(t_coordinates v, double fact)
{
	return (change_vec(fact * v.x, fact * v.y, fact * v.z));
}

t_coordinates	divide_vec(t_coordinates v, double fact)
{
	if (equal_double(fact, 0))
		return (v);
	return (change_vec(v.x / fact, v.y / fact, v.z / fact));
}
