/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:44:19 by achantra          #+#    #+#             */
/*   Updated: 2025/02/06 13:21:25 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_env	*init_env(void)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (perror("Error"), NULL);
	env->form = NULL;
	env->camera = NULL;
	env->light = NULL;
	env->amb = NULL;
	env->mlx = NULL;
	env->win = NULL;
	env->zoom = 1;
	env->rot_x = 0;
	env->rot_y = 0;
	env->rot_z = 0;
	env->a_ratio = WIN_W / WIN_H;
	return (env);
}
