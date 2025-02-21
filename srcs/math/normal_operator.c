/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:54:12 by mgalvez           #+#    #+#             */
/*   Updated: 2025/02/21 15:52:50 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_coordinates	pipe_normal(t_element *cylinder, t_coordinates *point)
{
	t_coordinates	bottom_disk_center;
	double			t;
	t_coordinates	circle_center;
	t_coordinates	normal_at_vec;

	bottom_disk_center = sub_vec(*cylinder->coord,
			mult_vec(*cylinder->vector, cylinder->height));
	t = scalar_prod_vec(sub_vec(*point, bottom_disk_center), *cylinder->vector);
	circle_center = add_vec(bottom_disk_center, mult_vec(*cylinder->vector, t));
	normal_at_vec = sub_vec(*point, circle_center);
	normalize_vec(&normal_at_vec);
	return (normal_at_vec);
}

static t_coordinates	normal_at_cy(t_element *cylinder, t_coordinates *point)
{
	t_coordinates	normal_at_vec;

	if (cylinder->intersec_type == 1)
		normal_at_vec = pipe_normal(cylinder, point);
	if (cylinder->intersec_type == 2)
		normal_at_vec = *cylinder->vector;
	if (cylinder->intersec_type == 3)
		normal_at_vec = mult_vec(*cylinder->vector, -1);
	return (normal_at_vec);
}

static t_coordinates	normal_at_sp(t_element *sphere, t_coordinates *point)
{
	t_coordinates	normal_at_vec;

	normal_at_vec = sub_vec(*point, *sphere->coord);
	normalize_vec(&normal_at_vec);
	return (normal_at_vec);
}

t_coordinates	get_normal_at(t_element *figure, t_coordinates *point)
{
	if (figure->id == SPHERE)
		return (normal_at_sp(figure, point));
//	if (figure->id == CYLINDER)
	return (normal_at_cy(figure, point));
}
