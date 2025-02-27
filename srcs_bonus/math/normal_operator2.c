/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_operator2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:20:06 by mgalvez           #+#    #+#             */
/*   Updated: 2025/02/27 18:05:37 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static t_coordinates	pyramid_normal(t_element *cone, t_coordinates *point)
{
	t_coordinates	projected_vec;
	double			factor;

	projected_vec = sub_vec(*point, *cone->coord);
	normalize_vec(&projected_vec);
	factor = cone->height / (0.5 * cone->diameter);
	projected_vec = mult_vec(projected_vec, factor);
	normalize_vec(&projected_vec);
	return (projected_vec);
}

t_coordinates	normal_at_co(t_element *cone, t_coordinates *point)
{
	t_coordinates	normal_at_vec;

	if (cone->cam_intersec_type == 1)
		normal_at_vec = pyramid_normal(cone, point);
	if (cone->cam_intersec_type == 2)
		normal_at_vec = *cone->vector;
	return (normal_at_vec);
}

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

t_coordinates	normal_at_cy(t_element *cylinder, t_coordinates *point)
{
	t_coordinates	normal_at_vec;

	if (cylinder->cam_intersec_type == 1)
		normal_at_vec = pipe_normal(cylinder, point);
	if (cylinder->cam_intersec_type == 2)
		normal_at_vec = *cylinder->vector;
	if (cylinder->cam_intersec_type == 3)
		normal_at_vec = mult_vec(*cylinder->vector, -1);
	return (normal_at_vec);
}
