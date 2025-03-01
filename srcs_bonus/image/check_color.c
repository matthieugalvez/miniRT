/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:59:16 by achantra          #+#    #+#             */
/*   Updated: 2025/03/01 21:12:25 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static double	get_bump_map_elev(t_hitpoint *hitpoint, t_element *figure)
{
}

static t_color	get_img_pixel(t_hitpoint *hitpoint, t_element *figure)
{
}

void	find_hitpoint_color(t_hitpoint *hitpoint, t_element *figure)
{
	if (figure->color_cmpt == 1)
		hitpoint->color = figure->color;
	else if (figure->color_cmpt == 2)
	{
		if (is_odd_coord(hitpoint, figure))
			hitpoint->color = figure->color;
		else
			hitpoint->color = figure->colorbis;
	}
	else
		hitpoint->color = get_img_pixel(hitpoint, figure);
	if (figure->bump_map_cmpt)
		hitpoint->normal_factor = get_bump_map_elev(hitpoint, figure);
}
