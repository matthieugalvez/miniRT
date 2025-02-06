/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:12:30 by achantra          #+#    #+#             */
/*   Updated: 2025/02/06 13:37:25 by achantra         ###   ########.fr       */
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
		if (cam->dir_right)
			free(cam->dir_right);
		if (cam->dir_up)
			free(cam->dir_up);
		free(cam);
	}
}

void	clean_form(t_element *form)
{
	t_element	*buf;

	if (form)
	{
		while (form)
		{
			buf = form;
			form = form->next;
			if (buf->coord)
				free(buf->coord);
			if (buf->vector)
				free(buf->vector);
			if (buf->color)
				free(buf->color);
			if (buf->c_inter)
				free(buf->c_inter);
			free(buf);
		}
	}
}
