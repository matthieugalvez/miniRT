/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:59:16 by achantra          #+#    #+#             */
/*   Updated: 2025/03/02 11:31:42 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static double	get_bump_map_elev(t_hitpoint *hitpoint, t_element *figure,
					int *uv_coords)
{
}

static t_color	get_img_pixel(t_hitpoint *hitpoint, t_element *figure,
					int *uv_coords)
{
}

void	find_hitpoint_color(t_hitpoint *hitpoint, t_element *figure)
{
	int	uv_coords[2];

	if (figure->color_cmpt == 1)
		hitpoint->color = figure->color;
	else
	{
		get_uv_coords(hitpoint, figure, &uv_coords[0]);
		if (figure->color_cmpt == 2)
		{
			if ((uv_coords[0] + uv_coords[1]) % 2)
				hitpoint->color = figure->color;
			else
				hitpoint->color = figure->colorbis;
		}
		else
			hitpoint->color = get_img_pixel(hitpoint, figure, &uv_coords[0]);
		if (figure->bump_map_cmpt)
			hitpoint->normal_factor
				= get_bump_map_elev(hitpoint, figure, &uv_coords[0]);
	}
}
