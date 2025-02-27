/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:36:08 by mgalvez           #+#    #+#             */
/*   Updated: 2025/02/27 20:42:58 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	*sts;
	size_t	i;
	size_t	j;
	size_t	loop_n;
	size_t	char_loop_n;

	sts = (size_t *)s;
	i = 0;
	j = 0;
	loop_n = n / 8;
	char_loop_n = n % 8;
	while (i < loop_n)
	{
		sts[i] = c;
		i++;
	}
	i *= 8;
	while (j < char_loop_n)
	{
		((char *)s)[i + j] = c;
		j++;
	}
	return (s);
}
