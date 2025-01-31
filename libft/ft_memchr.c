/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:56:04 by achantra          #+#    #+#             */
/*   Updated: 2024/11/06 17:08:25 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*t_s;

	t_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (t_s[i] == (unsigned char) c)
			return ((void *)s + i);
		i ++;
	}
	return (NULL);
}
