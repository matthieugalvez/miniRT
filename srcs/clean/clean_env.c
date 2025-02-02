/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:24:42 by achantra          #+#    #+#             */
/*   Updated: 2025/02/02 13:32:02 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	clean_element(t_env *env)
{
	t_element	*buf;

	clean_ambient(env->amb);
	clean_light(env->light);
	clean_camera(env->camera);
	if (env->elem)
	{
		while (*(env->elem))
		{
			buf = *(env->elem);
			if (buf->id == CYLINDER)
				clean_cylinder(buf);
			else if (buf->id == SPHERE)
				clean_sphere(buf);
			else if (buf->id == PLANE)
				clean_plane(buf);
			*(env->elem) = (*(env->elem))->next;
		}
	}
}

void	clean_env(t_env *env)
{
	clean_element(env);
	free(env);
}
