/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:58:25 by achantra          #+#    #+#             */
/*   Updated: 2024/11/15 19:46:51 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*t_dst;
	char	*t_src;

	if (!src && !dst && n > 0)
		return (0);
	i = 0;
	t_dst = (char *)dst;
	t_src = (char *)src;
	while (i < n)
	{
		t_dst[i] = t_src[i];
		i++;
	}
	return (dst);
}
/*
int	main(void)
{
	//printf("%s\n", (char *)memcpy("2222", "1111", 2));
	printf("%s\n", (char *)ft_memcpy("2222", "1111", 2));
}*/
