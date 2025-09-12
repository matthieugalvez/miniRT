/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:14:57 by mgalvez           #+#    #+#             */
/*   Updated: 2025/09/11 19:25:29 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	init_mlx(t_env *env)
{
	env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "miniRT");
	if (!env->win)
	{
		ft_putstr("Error: mlx\n", 2);
		return (clean_env(env, 1));
	}
	env->img.img = mlx_new_image(env->mlx, WIN_W, WIN_H);
	if (!env->img.img)
	{
		ft_putstr("Error: mlx\n", 2);
		return (clean_env(env, 1));
	}
	return (0);
}
