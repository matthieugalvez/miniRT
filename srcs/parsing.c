/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:49:38 by achantra          #+#    #+#             */
/*   Updated: 2025/02/01 12:58:50 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
Premier argument est un *.rt
	Chaque ligne commence par un identificateur et
	chaque identificateur a ses propres arguments

	- A(u) :
		* ambient lighting ratio in range [0.0,1.0]: 0.2
		* R,G,B colors in range [0-255]: 255, 255, 255
	- C(u)
		∗ x,y,z coordinates of the view point: -50.0,0,20
		∗ 3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
		∗ FOV : Horizontal field of view in degrees in range [0,180]: 70
	- L(u)
		∗ x,y,z coordinates of the light point: -40.0,50.0,0.0
		∗ the light brightness ratio in range [0.0,1.0]: 0.6
		∗ (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255
	- sp
		∗ x,y,z coordinates of the sphere center: 0.0,0.0,20.6
		∗ the sphere diameter: 12.6
			R,G,B colors in range [0-255]: 10, 0, 255
	- pl
		∗ identifier: pl
		∗ x,y,z coordinates of a point in the plane: 0.0,0.0,-10.0
		∗ 3d normalized normal vector. In range [-1,1] for each x,y,z axis: 0.0,1.0,0.0
		∗ R,G,B colors in range [0-255]: 0,0,225
	- cy
		∗ x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6
		∗ 3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis 0.0,0.0,1.0
		∗ the cylinder diameter: 14.2
		∗ the cylinder height: 21.42
		∗ R,G,B colors in range [0,255]: 10, 0, 255
*/

// Check the content of the file and parse it in a list
int	read_file(int fd, t_env *env)
{
    (void) env;
	return (close(fd), 0);
}

// Check if the file is readable and if its content is correct
int	parse_file(char *path, t_env *env)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (perror(path), 1);
	else if (read_file(fd, env))
		return (1);
	return (0);
}

// Check the entry
int	check_entry(int ac, char **av)
{
	int len;

	if (ac < 2)
		return (ft_putstr_fd("Error: Missing file\n", 2), 1);
	else if (ac > 2)
		return (ft_putstr_fd("Error: Too many arguments\n", 2), 1);
	len = ft_strlen(av[1]);
	if (len < 4 || ft_strncmp(av[1] + (len - 3), ".rt", 3))
		return (ft_putstr_fd("Error: Wrong file\n", 2), 1);
	return (0);
}