/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:59:16 by achantra          #+#    #+#             */
/*   Updated: 2025/02/28 20:12:28 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static int	is_odd_sp(t_hitpoint *hitpoint, t_element *figure)
{
	t_coordinates	temp_coord;
	double	u;
	double	v;
	int		u_value;
	int		v_value;
	int		odd;

	temp_coord = sub_vec(*hitpoint->coord, *figure->coord);
	normalize_vec(&temp_coord);
	odd = (int) floor(figure->diameter) % 2;
	u = (figure->diameter + odd) * (atan2(temp_coord.y,
		temp_coord.x) + M_PI) / (2 * M_PI);
	v = ((figure->diameter * figure->diameter)) * (acos(2 * (temp_coord.z) / figure->diameter) + M_PI_2) / M_PI;
	u_value = (int)u % 2;
	v_value = (int)v % 2;
	return ((u_value + v_value) % 2);
}

static int	is_odd_cy(t_hitpoint *hitpoint, t_element *figure)
{
	int				teta_value;
	int				r_value;
	int				z_value;
	t_coordinates	temp_coord;
	t_coordinates	ref_cy;
	t_coordinates	u;
	double			teta;
	double			r;
	
	temp_coord.x = hitpoint->coord->x - figure->coord->x;
	temp_coord.y = hitpoint->coord->y - figure->coord->y;
	temp_coord.z = hitpoint->coord->z - figure->coord->z;

	teta = acos(figure->vector->z / get_norm(*figure->vector));
	u.x = -figure->vector->y;
	u.y = figure->vector->x;
	u.z = 0;
	normalize_vec(&u);
	ref_cy = add_vec(add_vec(mult_vec(temp_coord, cos(teta)),
				mult_vec(*vect_prod_vec(u, *figure->vector),
					sin(teta))), mult_vec(u, (1 - cos(teta))
			* scalar_prod_vec(u, *figure->vector)));
	teta = atan2(ref_cy.y, ref_cy.x);
	r = sqrt(ref_cy.x * ref_cy.x + ref_cy.y * ref_cy.y);
	teta_value = (int)floor(4 * teta / (2 * M_PI)) % 2;
	r_value = (int)floor(r) % 2;
	z_value = (int)floor(ref_cy.z) % 2;	
	return ((teta_value + r_value + z_value) % 2);
}

static int	is_odd_co(t_hitpoint *hitpoint, t_element *figure)
{
	double	theta;
	double	z;
	double	u;
	double	v;
	int		x_value;
	int		y_value;

	theta = atan2(hitpoint->coord->y - figure->coord->y, hitpoint->coord->x
			- figure->coord->x);
	z = hitpoint->coord->z - figure->coord->z;
	if (hitpoint->coord->z == figure->coord->z + figure->height)
	{
		u = hitpoint->coord->x + hitpoint->coord->y;
		v = hitpoint->coord->z;
		x_value = (int)hitpoint->coord->x % 2;
		y_value = (int)hitpoint->coord->y % 2;
		// z_value = (int) hitpoint->coord->z % 2;
	}
	else
	{
		u = 100 * (theta + M_PI) / (2 * M_PI);
		v = 100 * z / figure->height;
		x_value = (int)u % 2;
		y_value = (int)v % 2;
		// z_value = (int) hitpoint->coord->z % 2;
		/*u = hitpoint->coord->x + hitpoint->coord->y;
		v = hitpoint->coord->z;
		x_value = (int) hitpoint->coord->x % 2;
		y_value = (int) hitpoint->coord->y % 2;
		z_value = (int) hitpoint->coord->z % 2;*/
	}
	return ((x_value + y_value) % 2);
}

static int	is_odd_pl(t_hitpoint *hitpoint, t_element *figure)
{
	int				x_value;
	int				y_value;
	int				z_value;
	t_coordinates	ref_pl;
	t_coordinates	u;
	double			teta;

	if (!equal_double(figure->vector->z, 0))
	{
		teta = acos(figure->vector->z / get_norm(*figure->vector));
		u.x = -figure->vector->y;
		u.y = figure->vector->x;
		u.z = 0;
		normalize_vec(&u);
		ref_pl = add_vec(add_vec(mult_vec(*hitpoint->coord, cos(teta)),
					mult_vec(*vect_prod_vec(u, *figure->vector),
						sin(teta))), mult_vec(u, (1 - cos(teta))
				* scalar_prod_vec(u, *figure->vector)));
		x_value = (int)floor(ref_pl.x / 10) % 2;
		y_value = (int)floor(ref_pl.y / 10) % 2;
		z_value = 0;		
	}
	else if (!equal_double(figure->vector->y, 0))
	{
		teta = acos(figure->vector->y / get_norm(*figure->vector));
		u.x = -figure->vector->x;
		u.y = figure->vector->z;
		u.z = 0;
		normalize_vec(&u);
		ref_pl = add_vec(add_vec(mult_vec(*hitpoint->coord, cos(teta)),
					mult_vec(*vect_prod_vec(u, *figure->vector),
						sin(teta))), mult_vec(u, (1 - cos(teta))
				* scalar_prod_vec(u, *figure->vector)));
		x_value = (int)floor(ref_pl.x / 10) % 2;
		y_value = 0;
		z_value = (int)floor(ref_pl.z / 10) % 2;
	}
	else
	{
		teta = acos(figure->vector->x / get_norm(*figure->vector));
		u.x = -figure->vector->z;
		u.y = figure->vector->y;
		u.z = 0;
		normalize_vec(&u);
		ref_pl = add_vec(add_vec(mult_vec(*hitpoint->coord, cos(teta)),
					mult_vec(*vect_prod_vec(u, *figure->vector),
						sin(teta))), mult_vec(u, (1 - cos(teta))
				* scalar_prod_vec(u, *figure->vector)));
		x_value = 0;
		y_value = (int)floor(ref_pl.y / 10) % 2;
		z_value = (int)floor(ref_pl.z / 10) % 2;	
	}
	return ((x_value + y_value + z_value) % 2);
}

static int	is_odd_coord(t_hitpoint *hitpoint, t_element *figure)
{
	if (figure->id == SPHERE)
		return (is_odd_sp(hitpoint, figure));
	else if (figure->id == CYLINDER)
		return (is_odd_cy(hitpoint, figure));
	else if (figure->id == PLANE)
		return (is_odd_pl(hitpoint, figure));
	else if (figure->id == CONE)
		return (is_odd_co(hitpoint, figure));
	return (1);
}

void	find_hitpoint_color(t_hitpoint *hitpoint, t_element *figure)
{
	if (!figure->colorbis)
		hitpoint->color = figure->color;
	else
	{
		if (is_odd_coord(hitpoint, figure))
			hitpoint->color = figure->color;
		else
			hitpoint->color = figure->colorbis;
	}
}
