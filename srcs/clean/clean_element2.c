/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_element2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:24:03 by achantra          #+#    #+#             */
/*   Updated: 2025/02/02 13:31:21 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	clean_cylinder(t_element *cy)
{
	if (cy)
	{
		if (cy->coord)
			free(cy->coord);
		if (cy->vector)
			free(cy->vector);
		if (cy->color)
			free(cy->color);
		free(cy);
	}
}

void	clean_sphere(t_element *sp)
{
	if (sp)
	{
		if (sp->coord)
			free(sp->coord);
		if (sp->color)
			free(sp->color);
		free(sp);
	}
}

void	clean_plane(t_element *pl)
{
	if (pl)
	{
		if (pl->coord)
			free(pl->coord);
		if (pl->vector)
			free(pl->vector);
		if (pl->color)
			free(pl->color);
		free(pl);
	}
}
