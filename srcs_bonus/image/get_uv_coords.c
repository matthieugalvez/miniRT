/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uv_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:07:24 by mgalvez           #+#    #+#             */
/*   Updated: 2025/03/02 15:45:53 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static void	change_ref(t_hitpoint *hitpoint, t_element *figure,
		t_coordinates *proj, t_coordinates *new_ref)
{
	t_coordinates	u;
	t_coordinates	temp_coord;
	double			teta;

	if (figure->id != PLANE)
		temp_coord = sub_vec(&hitpoint->coord, &figure->coord);
	else
		temp_coord = hitpoint->coord;
	new_ref->x = scalar_prod_vec(&figure->vector_up, &temp_coord);
	new_ref->y = scalar_prod_vec(&figure->vector_right, &temp_coord);
	new_ref->z = scalar_prod_vec(&figure->vector, &temp_coord);
}

static void	uv_pipe(t_hitpoint *hitpoint, t_element *figure,
		double *uv_coords)
{
	t_coordinates	ref_cy;
	t_coordinates	proj;

	uv_coords[2] = (int)floor(figure->diameter) % 2;
	if (!equal_double(figure->vector.z, 0))
		proj = change_vec(figure->vector.x, figure->vector.y, figure->vector.z);
	else if (!equal_double(figure->vector.y, 0))
		proj = change_vec(figure->vector.z, figure->vector.x, figure->vector.y);
	else
		proj = change_vec(figure->vector.y, figure->vector.z, figure->vector.x);
	change_ref(hitpoint, figure, &proj, &ref_cy);
	uv_coords[0] = (atan2(ref_cy.y, ref_cy.x) + M_PI) / (2 * M_PI);
	uv_coords[1] = ref_cy.z;
}

static void	uv_pl(t_hitpoint *hitpoint, t_element *figure,
		double *uv_coords)
{
	t_coordinates	ref_pl;
	t_coordinates	proj;

	if (!equal_double(figure->vector.z, 0))
		proj = change_vec(figure->vector.x, figure->vector.y, figure->vector.z);
	else if (!equal_double(figure->vector.y, 0))
		proj = change_vec(figure->vector.z, figure->vector.x, figure->vector.y);
	else
		proj = change_vec(figure->vector.y, figure->vector.z, figure->vector.x);
	change_ref(hitpoint, figure, &proj, &ref_pl);
	uv_coords[0] = ref_pl.x;
	uv_coords[1] = ref_pl.y;
}

static void	uv_sp(t_hitpoint *hitpoint, t_element *figure,
		double *uv_coords)
{
	t_coordinates	ref_sp;
	t_coordinates	proj;

	if (!equal_double(figure->vector.z, 0))
		proj = change_vec(figure->vector.x, figure->vector.y, figure->vector.z);
	else if (!equal_double(figure->vector.y, 0))
		proj = change_vec(figure->vector.z, figure->vector.x, figure->vector.y);
	else
		proj = change_vec(figure->vector.y, figure->vector.z, figure->vector.x);
	change_ref(hitpoint, figure, &proj, &ref_sp);
	uv_coords[2] = (int)floor(figure->diameter) % 2;
	uv_coords[0] = (atan2(ref_sp.y, ref_sp.x) + M_PI) / (2 * M_PI);
	uv_coords[1] = 0.5 + asin(ref_sp.z) / M_PI;
}

static void	get_uv_sphere(t_hitpoint *hitpoint, t_element *figure,
					double *uv_coords)
{
	double			u;
	double			v;
	t_coordinates	ref_sp;
	t_coordinates	proj;

	if (!equal_double(figure->vector.z, 0))
		proj = change_vec(figure->vector.x, figure->vector.y, figure->vector.z);
	else if (!equal_double(figure->vector.y, 0))
		proj = change_vec(figure->vector.z, figure->vector.x, figure->vector.y);
	else
		proj = change_vec(figure->vector.y, figure->vector.z, figure->vector.x);
	change_ref(hitpoint, figure, &proj, &ref_sp);
	normalize_vec(&ref_sp);
	uv_coords[0] = 0.5 + (atan2(ref_sp.z, ref_sp.x) / (2 * M_PI));
	uv_coords[1] = 0.5 + (asin(ref_sp.y)) / M_PI;
}

void	get_uv_coords(t_hitpoint *hitpoint, t_element *figure,
		double *uv_coords)
{
	if (figure->id == SPHERE)
		return (get_uv_sphere(hitpoint, figure, uv_coords));
	else if (figure->id == PLANE)
		return (uv_pl(hitpoint, figure, uv_coords));
	else if (figure->id == CYLINDER || figure->id == CONE)
		return (uv_pipe(hitpoint, figure, uv_coords));
}
