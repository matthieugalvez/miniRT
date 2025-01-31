/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:53:03 by achantra          #+#    #+#             */
/*   Updated: 2024/12/05 21:23:13 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*pointer;
	size_t	i;	

	pointer = malloc(count * size);
	if (!pointer)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		pointer[i] = 0;
		i ++;
	}
	return ((void *) pointer);
}
/*
int	main(void)
{
	char *p1 = (char *) calloc(3, sizeof(char));
	char *p2 = (char *) ft_calloc(3, sizeof(char));

	
	printf("%s\n", p1);
	printf("%s\n", p2);
	free(p1);
	free(p2);
	return (0);
}*/