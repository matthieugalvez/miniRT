/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:44:19 by achantra          #+#    #+#             */
/*   Updated: 2025/02/01 21:13:07 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_env	*init_env(void)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (perror("Error"), NULL);
	env->elem = NULL;
	env->camera = NULL;
	env->light = NULL;
	env->amb = NULL;
	return (env);
}
