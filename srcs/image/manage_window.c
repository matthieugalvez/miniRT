/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:55:30 by achantra          #+#    #+#             */
/*   Updated: 2025/02/10 16:55:59 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	init_mlx(t_env *env)
{
	env->mlx = mlx_init();
	if (!env->mlx)
		return (ft_putendl("Error: mlx", 2), clean_env_err(env));
	env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "miniRT");
	if (!env->win)
		return (ft_putendl("Error: mlx", 2), clean_env_err(env), 1);
	env->img.img = mlx_new_image(env->mlx, WIN_W, WIN_H);
	if (!env->img.img)
		return (ft_putendl("Error: mlx", 2), clean_env_err(env));
	return (0);
}
