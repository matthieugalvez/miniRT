/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:21:37 by achantra          #+#    #+#             */
/*   Updated: 2025/02/01 20:00:11 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_data_err(void)
{
	ft_putstr_fd("Error: Wrong data\n", 2);
}

void	debug_env(t_env *env)
{
	printf("amb_ratio = %f, amb_r = %d, amb_g = %d, amb_b = %d\n", env->amb->ratio, env->amb->color->r, env->amb->color->g, env->amb->color->b);
}