/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_element1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:12:30 by achantra          #+#    #+#             */
/*   Updated: 2025/02/04 18:50:39 by achantra         ###   ########.fr       */
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
