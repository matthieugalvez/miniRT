/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:36:53 by achantra          #+#    #+#             */
/*   Updated: 2025/02/02 12:24:11 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int ac, char **av)
{
	t_env	*env;

	if (check_entry(ac, av))
		return (1);
	env = init_env();
	if (!env)
		return (1);
	if (parse_file(av[1], env))
		return (clean_env(env), 1);
	debug_env(env);
	return (clean_env(env), 0);
}
