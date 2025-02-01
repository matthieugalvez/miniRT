/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:21:37 by achantra          #+#    #+#             */
/*   Updated: 2025/02/01 20:49:13 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_data_err(void)
{
	ft_putstr_fd("Error: Wrong data\n", 2);
}

void	debug_env(t_env *env)
{
	if (env->light)
		printf("l_x=%f, l_y=%f, l_z=%f, l_bri=%f l_r=%d, l_g=%d, l_b=%d\n",
			env->light->coord->x, env->light->coord->y, env->light->coord->z,
			env->light->bright, env->light->color->r, env->light->color->g,
			env->light->color->b);
	if (env->amb)
		printf("amb_light=%f, amb_r=%d, amb_g=%d, amb_b=%d\n", env->amb->light,
			env->amb->color->r, env->amb->color->g, env->amb->color->b);
}
