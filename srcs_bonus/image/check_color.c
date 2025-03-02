/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:59:16 by achantra          #+#    #+#             */
/*   Updated: 2025/03/02 20:24:53 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static void	get_plane_case(t_img *texture, int *x, int *y)
{
	*x = texture->w / 2 + *x;
	*y = texture->h / 2 + *y;
}

static void	get_bump_map_elev(t_element *figure, t_hitpoint *hitpoint,
					double *uv_coords)
{
	t_img	*bump_map;
	int		x[2];
	int		y[2];
	char	*pixel_color;
	int		c[2];

	bump_map = &figure->bump_map;
	x[0] = ((int)((1 - uv_coords[0]) * bump_map->w) + bump_map->w / 2)
		% bump_map->w;
	y[0] = (int)((1 - uv_coords[1]) * bump_map->h);
	x[1] = (x[0] + 1) % bump_map->w;
	y[1] = (y[0] + 1) % bump_map->h;
	pixel_color = bump_map->img_pixels
		+ (y[0] * bump_map->line_len + x[0] * (bump_map->bits_per_pixel / 8));
	c[0] = *((unsigned int *)pixel_color) & 0xff;
	pixel_color = bump_map->img_pixels
		+ (y[0] * bump_map->line_len + x[1] * (bump_map->bits_per_pixel / 8));
	c[1] = *((unsigned int *)pixel_color) & 0xff;
	hitpoint->bubv[0] = -((double)(c[0] - c[1])) / 10;
	pixel_color = bump_map->img_pixels
		+ (y[1] * bump_map->line_len + x[0] * (bump_map->bits_per_pixel / 8));
	c[1] = *((unsigned int *)pixel_color) & 0xff;
	hitpoint->bubv[1] = -((double)(c[0] - c[1])) / 10;
}

static void	get_img_pixel(t_element *figure, t_hitpoint *hitpoint,
						double *uv_coords)
{
	t_img			*texture;
	int				x;
	int				y;
	char			*pixel_color;
	unsigned int	transformed_color;

	texture = &figure->texture;
	if (figure->id == PLANE)
	{
		x = (int)uv_coords[1] % (texture->w / 2);
		y = (int)uv_coords[0] % (texture->h / 2);
		get_plane_case(texture, &x, &y);
	}
	else
	{
		x = ((int)((1 - uv_coords[0]) * texture->w) + texture->w / 2)
			% texture->w;
		y = (int)((1 - uv_coords[1]) * texture->h);
	}
	pixel_color = texture->img_pixels
		+ (y * texture->line_len + x * (texture->bits_per_pixel / 8));
	transformed_color = *(unsigned int *)pixel_color;
	hitpoint->color.r = (transformed_color >> 16) & 0xff;
	hitpoint->color.g = (transformed_color >> 8) & 0xff;
	hitpoint->color.b = transformed_color & 0xff;
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
		v = (int)floor(uv_coords[1] / 2) % 2;
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
			get_img_pixel(figure, hitpoint, &uv_coords[0]);
		if (figure->bump_map_cmpt)
			get_bump_map_elev(figure, hitpoint, &uv_coords[0]);
	}
}
