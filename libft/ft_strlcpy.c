/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:18:50 by achantra          #+#    #+#             */
/*   Updated: 2024/11/05 17:18:51 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i += 1;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
	{
		i += 1;
	}
	return (i);
}
/*
int	main(void)
{
	char		dest[] = "Bonj";
	char		src[] = "Goodbye";
	char		dest2[]= "Bonj";
	unsigned int	size = 4;
	size_t		len;

	len = ft_strlcpy(dest, src, size);
	printf("ft_strlcpy : %s is %lu char long\n", src, len);
	printf("dest is %s\n", dest);
	len = strlcpy(dest2, src, size);
	printf("strlcpy : %s is %lu char long\n", src, len);
	printf("dest2 is %s\n", dest2);

	return (0);
}*/
