/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uv_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:07:24 by mgalvez           #+#    #+#             */
/*   Updated: 2025/03/02 13:17:03 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static void	get_uv_sphere(t_hitpoint *hitpoint, t_element *figure,
					double *uv_coords)
{
	t_coordinates	vector;
	double			u;
	double			v;

	vector = sub_vec(&hitpoint->coord, &figure->coord);
	normalize_vec(&vector);
	uv_coords[0] = 0.5 + (atan2(vector.z, vector.x) / (2 * M_PI));
	uv_coords[1] = 0.5 + (asin(vector.y)) / M_PI;
}

void	get_uv_coords(t_hitpoint *hitpoint, t_element *figure,
				double *uv_coords)
{
	if (figure->id == SPHERE)
		return (get_uv_sphere(hitpoint, figure, uv_coords));
//	else if (figure->id == PLANE)
//		return (is_odd_pl(hitpoint, figure, uv_coords));
//	else if (figure->id == CYLINDER)
//		return (is_odd_cy(hitpoint, figure, uv_coords));
//	else if (figure->id == CONE)
//		return (is_odd_co(hitpoint, figure, uv_coords));
}
