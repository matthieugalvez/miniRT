/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:44:19 by achantra          #+#    #+#             */
/*   Updated: 2025/02/10 17:00:51 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	init_env(t_env	*env)
{
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
}
