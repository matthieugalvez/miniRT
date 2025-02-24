/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_key_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:24:45 by mgalvez           #+#    #+#             */
/*   Updated: 2025/02/24 17:26:45 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_rotate_figure(int keysym, t_env *env, t_element *figure);

void	ft_elevate_figure(int keysym, t_env *env, t_element *figure);

void	ft_translate_figure(int keysym, t_env *env, t_element *figure);

void	ft_scale(int keysym, t_env *env, t_element *figure);
