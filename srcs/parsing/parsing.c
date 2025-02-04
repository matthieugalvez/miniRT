/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:49:38 by achantra          #+#    #+#             */
/*   Updated: 2025/02/04 17:54:20 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Check the content of the file and parse it in env
int	fill_env(int fd, t_env *env)
{
	char	*line;
	char	*trim_line;
	int		status;

	status = 0;
	line = get_next_line(fd);
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
		line = get_next_line(fd);
	}
	close(fd);
	find_viewport(env);
	return (status);
}

// Check if the file is readable and if its content is correct
int	parse_file(char *path, t_env *env)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (perror(path), 1);
	else if (fill_env(fd, env))
		return (1);
	return (0);
}

// Check the entry
int	check_entry(int ac, char **av)
{
	int	len;

	if (ac < 2)
		return (ft_putstr_fd("Error: Missing file\n", 2), 1);
	else if (ac > 2)
		return (ft_putstr_fd("Error: Too many arguments\n", 2), 1);
	len = ft_strlen(av[1]);
	if (len < 4 || ft_strncmp(av[1] + (len - 3), ".rt", 3))
		return (ft_putstr_fd("Error: Wrong file\n", 2), 1);
	return (0);
}
