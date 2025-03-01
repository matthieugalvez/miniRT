/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:59:16 by achantra          #+#    #+#             */
/*   Updated: 2025/03/01 13:02:21 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static int	is_odd_sp(t_hitpoint *hitpoint, t_element *figure)
{
	double	u;
	double	v;
	int		x_value;
	int		y_value;

	u = 100
		* (atan2(hitpoint->coord.y, hitpoint->coord.x) + M_PI) / (2 * M_PI);
	v = 100 * (acos(2 * hitpoint->coord.z / figure->diameter) + M_PI_2) / M_PI;
	x_value = (int) u % 2;
	y_value = (int) v % 2;
	return ((x_value + y_value) % 2);
}

static int	is_odd_cy(t_hitpoint *hitpoint, t_element *figure)
{
	double	theta;
	double	z;
	double	u;
	double	v;
	int		x_value;
	int		y_value;

	theta = atan2(hitpoint->coord.y, hitpoint->coord.x);
	z = hitpoint->coord.z;
	if (hitpoint->coord.z == figure->coord->z - (figure->height / 2)
		|| hitpoint->coord.z == figure->coord->z + (figure->height / 2))
	{
		u = hitpoint->coord.x + hitpoint->coord.y;
		v = hitpoint->coord.z;
		x_value = (int)hitpoint->coord.x % 2;
		y_value = (int)hitpoint->coord.y % 2;
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

static int	is_odd_co(t_hitpoint *hitpoint, t_element *figure)
{
	double	theta;
	double	z;
	double	u;
	double	v;
	int		x_value;
	int		y_value;

	theta = atan2(hitpoint->coord.y, hitpoint->coord.x);
	z = hitpoint->coord.z;
	if (hitpoint->coord.z == figure->coord->z + figure->height)
	{
		u = hitpoint->coord.x + hitpoint->coord.y;
		v = hitpoint->coord.z;
		x_value = (int)hitpoint->coord.x % 2;
		y_value = (int)hitpoint->coord.y % 2;
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
	int	x_value;
	int	y_value;
	int	z_value;

	x_value = (int)floor(hitpoint->coord.x) % 2;
	y_value = (int)floor(hitpoint->coord.y) % 2;
	z_value = (int)floor(hitpoint->coord.z) % 2;
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
		hitpoint->color = *figure->color;
	else
	{
		if (is_odd_coord(hitpoint, figure))
			hitpoint->color = *figure->color;
		else
			hitpoint->color = *figure->colorbis;
	}
}
