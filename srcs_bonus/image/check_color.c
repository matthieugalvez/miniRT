/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:59:16 by achantra          #+#    #+#             */
/*   Updated: 2025/03/02 15:21:29 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static void	get_bump_map_elev(t_hitpoint *hitpoint, t_img *bump_map,
					double *uv_coords)
{
	int				x;
	int				y;
	char			*pixel_color;
	unsigned int	transformed_color;

	x = ((int)((uv_coords[0]) * bump_map->w) + bump_map->w / 2) % bump_map->w;
	y = (int)((1 - uv_coords[1]) * bump_map->h);
	pixel_color = bump_map->img_pixels
		+ (y * bump_map->line_len + x * (bump_map->bits_per_pixel / 8));
	transformed_color = *(unsigned int *)pixel_color;
	transformed_color = ((transformed_color >> 16) & 0xff)
		+ ((transformed_color >> 8) & 0xff) + (transformed_color & 0xff);
	transformed_color /= 3;
}

static void	get_img_pixel(t_hitpoint *hitpoint, t_img *texture,
					double *uv_coords)
{
	int				x;
	int				y;
	char			*pixel_color;
	unsigned int	transformed_color;

	x = ((int)((uv_coords[0]) * texture->w) + texture->w / 2) % texture->w;
	y = (int)((1 - uv_coords[1]) * texture->h);
	pixel_color = texture->img_pixels
		+ (y * texture->line_len + x * (texture->bits_per_pixel / 8));
	transformed_color = *(unsigned int *)pixel_color;
	hitpoint->color.r = (transformed_color >> 16) & 0xff;
	hitpoint->color.g = (transformed_color >> 8) & 0xff;
	hitpoint->color.b = transformed_color & 0xff;
}

void	find_hitpoint_color(t_hitpoint *hitpoint, t_element *figure)
{
	double	uv_coords[2];

	if (figure->color_cmpt == 1)
		hitpoint->color = figure->color;
	else
	{
		get_uv_coords(hitpoint, figure, &uv_coords[0]);
		if (figure->color_cmpt == 2)
		{
			if (((int)uv_coords[0] + (int)uv_coords[1]) % 2)
				hitpoint->color = figure->color;
			else
				hitpoint->color = figure->colorbis;
		}
		else
			get_img_pixel(hitpoint, &figure->texture, &uv_coords[0]);
		if (figure->bump_map_cmpt)
			get_bump_map_elev(hitpoint, &figure->bump_map, &uv_coords[0]);
	}
}
