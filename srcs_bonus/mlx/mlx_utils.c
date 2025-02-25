/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:49:04 by mgalvez           #+#    #+#             */
/*   Updated: 2025/02/25 18:03:08 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

int	check_element(t_env *env)
{
	if (env->camera && env->amb && env->light && env->figure)
		return (0);
	if (!env->camera)
		ft_putstr("Warning: missing camera\n", 2);
	if (!env->amb)
		ft_putstr("Warning: missing ambiant light\n", 2);
	if (!env->light)
		ft_putstr("Warning: missing light\n", 2);
	if (!env->figure)
		ft_putstr("Warning: missing figure\n", 2);
	return (1);
}
