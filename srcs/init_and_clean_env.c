/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_clean_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:44:19 by achantra          #+#    #+#             */
/*   Updated: 2025/02/01 12:57:55 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_env   *init_env(void)
{
    t_env   *env;

    env = malloc(sizeof(t_env));
    if (!env)
        return (perror("Error"), NULL);
    env->data = NULL;
    return (env);
}

void    clean_env(t_env *env)
{
    ft_lstclear(&(env->data), free);
    free(env);
}