/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:23:15 by achantra          #+#    #+#             */
/*   Updated: 2024/11/06 16:51:43 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*t_dest;
	unsigned char	*t_src;

	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	else if (dest < src)
	{
		i = 0;
		while (i < (int) n)
		{
			t_dest[i] = t_src[i];
			i ++;
		}
	}
	else
	{
		i = (int)n;
		while (--i >= 0)
			t_dest[i] = t_src[i];
	}
	return (dest);
}
