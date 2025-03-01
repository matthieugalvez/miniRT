/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:12:30 by achantra          #+#    #+#             */
/*   Updated: 2025/03/01 14:24:38 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	clean_ambient(t_amb *amb)
{
	if (amb)
	{
		if (amb->color)
			free(amb->color);
		free(amb);
	}
}

void	clean_light(t_light *light)
{
	if (light)
	{
		if (light->coord)
			free(light->coord);
		if (light->color)
			free(light->color);
		free(light);
	}
}

void	clean_camera(t_camera *cam)
{
	if (cam)
	{
		if (cam->coord)
			free(cam->coord);
		if (cam->dir)
			free(cam->dir);
		free(cam);
	}
}

void	clean_figure(t_element *figure)
{
	t_element	*buf;

	if (figure)
	{
		while (figure)
		{
			buf = figure;
			figure = figure->next;
			if (buf->coord)
				free(buf->coord);
			if (buf->vector)
				free(buf->vector);
			if (buf->color)
				free(buf->color);
			free(buf);
		}
	}
}
