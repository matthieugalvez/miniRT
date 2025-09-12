/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:21:37 by achantra          #+#    #+#             */
/*   Updated: 2025/09/11 19:28:41 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// static void	debug_env_figure(t_element *figure)
// {
// 	while (figure)
// 	{
// 		if (figure->id == SPHERE)
// 			printf("sp %.2f,%.2f,%.2f %.2f %d,%d,%d", figure->coord.x,
// 				figure->coord.y, figure->coord.z, figure->diameter,
// 				figure->color.r, figure->color.g, figure->color.b);
// 		else if (figure->id == PLANE)
// 			printf("pl %.2f,%.2f,%.2f %.2f,%.2f,%.2f %d,%d,%d",
// 				figure->coord.x, figure->coord.y, figure->coord.z,
// 				figure->vector.x, figure->vector.y, figure->vector.z,
// 				figure->color.r, figure->color.g, figure->color.b);
// 		else if (figure->id == CYLINDER)
// 			printf("cy %.2f,%.2f,%.2f %.2f,%.2f,%.2f %.2f %.2f %d,%d,%d",
// 				figure->coord.x, figure->coord.y, figure->coord.z,
// 				figure->vector.x, figure->vector.y, figure->vector.z,
// 				figure->diameter, figure->height,
// 				figure->color.r, figure->color.g, figure->color.b);
// 		else if (figure->id == CONE)
// 			printf("co %.2f,%.2f,%.2f %.2f,%.2f,%.2f %.2f %.2f %d,%d,%d",
// 				figure->coord.x, figure->coord.y, figure->coord.z,
// 				figure->vector.x, figure->vector.y, figure->vector.z,
// 				figure->diameter, figure->height,
// 				figure->color.r, figure->color.g, figure->color.b);
// 		if (figure->color_cmpt == 2)
// 			printf(" %d,%d,%d",
// 				figure->colorbis.r, figure->colorbis.g, figure->colorbis.b);
// 		printf("\n");
// 		figure = figure->next;
// 	}
// }

// static void	debug_env_light(t_light *light)
// {
// 	while (light)
// 	{
// 		printf("L %.2f,%.2f,%.2f %.2f %d,%d,%d\n", light->coord.x,
// 			light->coord.y, light->coord.z, light->bright,
// 			light->color.r, light->color.g, light->color.b);
// 		light = light->next;
// 	}
// }

// void	debug_env(t_env *env)
// {
// 	printf("A %.2f %d,%d,%d\n", env->amb.bright, env->amb.color.r,
// 		env->amb.color.g, env->amb.color.b);
// 	if (env->light)
// 		debug_env_light(env->light);
// 	printf("C %.2f,%.2f,%.2f, %.2f,%.2f,%.2f, %.2f\n",
// 		env->camera.coord.x, env->camera.coord.y, env->camera.coord.z,
// 		env->camera.dir.x, env->camera.dir.y,
// 		env->camera.dir.z, env->camera.fov);
// 	if (env->figure)
// 		debug_env_figure(env->figure);
// }
