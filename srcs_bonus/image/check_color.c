/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:59:16 by achantra          #+#    #+#             */
/*   Updated: 2025/03/02 14:43:23 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static double	get_bump_map_elev(t_hitpoint *hitpoint, t_element *figure,
		double *uv_coords)
{
}

static t_color	get_img_pixel(t_hitpoint *hitpoint, t_element *figure,
		double *uv_coords)
{
}

static void	find_checkerboard_color(t_hitpoint *hitpoint, t_element *figure,
		double *uv_coords)
{
	int	u;
	int	v;

	if (figure->id == SPHERE)
	{
		u = (int)((figure->diameter + uv_coords[2]) * uv_coords[0]) % 2;
		v = (int)((figure->diameter) * uv_coords[1]) % 2;
	}
	else if (figure->id == PLANE)
	{
		u = (int)floor(uv_coords[0] / 10) % 2;
		v = (int)floor(uv_coords[1] / 10) % 2;
	}
	else if (figure->id == CYLINDER || figure->id == CONE)
	{
		u = (int) floor((figure->diameter + uv_coords[2]) * uv_coords[0]) % 2;
		v = (int)floor(uv_coords[1]) % 2;
	}
	if ((u + v) % 2 != 0)
		hitpoint->color = figure->color;
	else
		hitpoint->color = figure->colorbis;
}

void	find_hitpoint_color(t_hitpoint *hitpoint, t_element *figure)
{
	double	uv_coords[3];

	if (figure->color_cmpt == 1)
		hitpoint->color = figure->color;
	else
	{
		get_uv_coords(hitpoint, figure, &uv_coords[0]);
		if (figure->color_cmpt == 2)
			find_checkerboard_color(hitpoint, figure, uv_coords);
		else
			hitpoint->color = get_img_pixel(hitpoint, figure, &uv_coords[0]);
		if (figure->bump_map_cmpt)
			hitpoint->normal_factor = get_bump_map_elev(hitpoint, figure,
					&uv_coords[0]);
	}
}
