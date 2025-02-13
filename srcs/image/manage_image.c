/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:26:30 by achantra          #+#    #+#             */
/*   Updated: 2025/02/13 16:51:00 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	ft_reinit(t_env *env)
{
	env->rot_x = 0;
	env->rot_y = 0;
	env->rot_z = 0;
}

int	ft_key(int keysym, t_env *env)
{
	if (keysym == KEY_ESC)
		return (clean_env(env, 0));
	/*else if (keysym == KEY_PLUS || keysym == KEY_MINUS)
		ft_zoom(keysym, env);
	else if (keysym >= KEY_LEFT && keysym <= KEY_DOWN)
		ft_translate(keysym, env);
	else if ((keysym >= KEY_X && keysym <= KEY_Z) || (keysym >= KEY_A
			&& keysym <= KEY_C))
		ft_rotate(keysym, env);
	else if (keysym == KEY_P || keysym == KEY_K)
		ft_proj(keysym, env);
	else if (keysym == KEY_D || keysym == KEY_E)
		ft_elevation(keysym, env);*/
	else if (keysym == KEY_I)
		ft_reinit(env);
	print_image(env);
	return (0);
}
