/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:49:38 by achantra          #+#    #+#             */
/*   Updated: 2025/09/11 19:28:28 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_element(t_env *env)
{
	if (env->cam_cmpt && env->amb_cmpt && env->light && env->figure)
		return (0);
	if (!env->cam_cmpt)
		ft_putstr("Warning: missing camera\n", 2);
	if (!env->amb_cmpt)
		ft_putstr("Warning: missing ambiant light\n", 2);
	if (!env->light)
		ft_putstr("Warning: missing light\n", 2);
	if (!env->figure)
		ft_putstr("Warning: missing figure\n", 2);
	return (1);
}

// Check the content of the file and parse it in env
static int	fill_env(int fd, t_env *env)
{
	char	*line;
	char	*trim_line;
	int		status;

	status = 0;
	line = ft_getnextline(fd);
	while (line)
	{
		if (line[0] != '\n' && !status)
		{
			trim_line = ft_strtrim(line, "\n");
			if (init_element(env, trim_line))
				status = 1;
			free(trim_line);
		}
		free(line);
		line = ft_getnextline(fd);
	}
	close(fd);
	return (status);
}

// Check if the file is readable and if its content is correct
int	parse_file(char *path, t_env *env)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror(path);
		return (1);
	}
	return (fill_env(fd, env));
}

// Check the entry
int	check_entry(int ac, char **av)
{
	int	len;

	if (ac < 2)
	{
		ft_putstr("Error: Missing file\n", 2);
		return (1);
	}
	else if (ac > 2)
	{
		ft_putstr("Error: Too many arguments\n", 2);
		return (1);
	}
	len = ft_strlen(av[1]);
	if (len < 4 || ft_strncmp(av[1] + (len - 3), ".rt", 3))
	{
		ft_putstr("Error: Wrong file\n", 2);
		return (1);
	}
	return (0);
}
