/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:16:44 by achantra          #+#    #+#             */
/*   Updated: 2024/12/16 22:27:21 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(int fd, char *buffer)
{
	int		nchar;
	char	*res;
	char	*temp;

	res = buffer;
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (free(res), NULL);
	nchar = read(fd, buffer, BUFFER_SIZE);
	while (nchar > 0)
	{
		buffer[nchar] = 0;
		temp = res;
		res = ft_strjoin(res, buffer);
		if (!res)
			return (free(buffer), free(temp), NULL);
		free(temp);
		if (ft_strchr(res, '\n'))
			break ;
		nchar = read(fd, buffer, BUFFER_SIZE);
	}
	if (nchar < 0)
		return (free(buffer), free(res), NULL);
	return (free(buffer), res);
}

char	*ft_line(char *buffer)
{
	int		i;
	char	*res;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	res = ft_substr(buffer, 0, i);
	if (!res)
		return ("Error\n");
	if (res[0] == 0)
		return (free(res), NULL);
	return (res);
}

int	ft_next(char *res, char **buffer)
{
	char	*temp;

	temp = *buffer;
	*buffer = ft_substr(temp, ft_strlen(res), ft_strlen(temp) - ft_strlen(res));
	if (!*buffer)
		return (free(temp), 0);
	return (free(temp), 1);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer[fd])
			free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	res = ft_line(buffer[fd]);
	if (!res)
		return (free(buffer[fd]), NULL);
	if (!ft_next(res, &buffer[fd]))
		return (free(res), NULL);
	return (res);
}

char	*get_next_line_fdf(int fd)
{
	static char	*buffer[1024];
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer[fd])
			free(buffer[fd]);
		buffer[fd] = NULL;
		return ("Error\n");
	}
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return ("Error\n");
	res = ft_line(buffer[fd]);
	if (!res)
		return (free(buffer[fd]), NULL);
	if (!ft_strncmp(res, "Error\n", 7))
		return (free(buffer[fd]), res);
	if (!ft_next(res, &buffer[fd]))
		return (free(res), "Error\n");
	return (res);
}

/*
int	main(int ac, char **av)
{
	if (ac <= 2)
		return (1);

	int	fd = open(av[1], O_RDONLY);
	int	fd_2 = open(av[2], O_RDONLY);
	char	*line;

	if (fd > 0 && fd_2 > 0)
	{
		line = get_next_line(fd);
		if (line)
			printf("%s", line);
		free(line);
		line = get_next_line(fd);
		if (line)
			printf("%s", line);
		free(line);
		line = get_next_line(fd_2);
		if (line)
			printf("%s", line);
		free(line);
		line = get_next_line(fd);
				if (line)
						printf("%s", line);
				free(line);
		line = get_next_line(fd_2);
				if (line)
						printf("%s", line);
				free(line);
		line = get_next_line(fd);
				if (line)
						printf("%s", line);
				free(line);
		close(fd);
	}
	return (0);
}*/
