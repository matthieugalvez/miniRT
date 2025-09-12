/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:44:19 by achantra          #+#    #+#             */
/*   Updated: 2025/09/11 19:25:16 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_env(t_env	*env)
{
	ft_bzero(env, sizeof(t_env));
	env->a_ratio = (float)WIN_W / (float)WIN_H;
}
