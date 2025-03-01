/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:03:23 by achantra          #+#    #+#             */
/*   Updated: 2025/03/01 13:18:10 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

t_coordinates	change_vec(double x, double y, double z)
{
	t_coordinates	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_coordinates	add_vec(t_coordinates *v1, t_coordinates *v2)
{
	t_coordinates	vec;

	vec.x = v1->x + v2->x;
	vec.y = v1->y + v2->y;
	vec.z = v1->z + v2->z;
	return (vec);
}

t_coordinates	sub_vec(t_coordinates *v1, t_coordinates *v2)
{
	t_coordinates	vec;

	vec.x = v1->x - v2->x;
	vec.y = v1->y - v2->y;
	vec.z = v1->z - v2->z;
	return (vec);
}

t_coordinates	mult_vec(t_coordinates *v, double fact)
{
	t_coordinates	vec;

	vec.x = v->x * fact;
	vec.y = v->y * fact;
	vec.z = v->z * fact;
	return (vec);
}

t_coordinates	div_vec(t_coordinates *v, double fact)
{
	t_coordinates	vec;

	if (equal_double(fact, 0))
		return (*v);
	vec.x = v->x / fact;
	vec.y = v->y / fact;
	vec.z = v->z / fact;
	return (vec);
}
