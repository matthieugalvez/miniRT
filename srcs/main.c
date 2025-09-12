/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:36:53 by achantra          #+#    #+#             */
/*   Updated: 2025/09/11 19:28:50 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int ac, char **av)
{
	t_env	env;

	if (check_entry(ac, av))
		return (1);
	init_env(&env);
	env.mlx = mlx_init();
	if (!env.mlx)
	{
		ft_putstr("Error: mlx\n", 2);
		return (clean_env(&env, 1));
	}
	if (parse_file(av[1], &env) || check_element(&env))
		return (clean_env(&env, 1));
	init_mlx(&env);
	print_image(&env);
	mlx_key_hook(env.win, ft_key, &env);
	mlx_hook(env.win, 17, 0, clean_env, &env);
	mlx_loop(env.mlx);
	return (clean_env(&env, 0));
}
