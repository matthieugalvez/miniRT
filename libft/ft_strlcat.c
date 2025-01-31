/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:16:53 by achantra          #+#    #+#             */
/*   Updated: 2024/11/26 23:06:49 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_dst;
	unsigned int	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = len_dst;
	j = 0;
	if (dstsize > 0)
	{
		while (src[j] && i < dstsize - 1)
		{
			dst[i] = src[j];
			i += 1;
			j += 1;
		}
		dst[i] = 0;
	}
	if (dstsize > len_dst)
	{
		return (len_dst + len_src);
	}
	else
		return (dstsize + len_src);
}

/*int	main(void)
{
	char	dest[100] = "Hello you";
	char	src[] = "Goodbye";
	char	dest2[100] = "Hello you";
	char	src2[] = "Goodbye";
	unsigned int	res;
	unsigned int	res2;
	unsigned int    n = 15;

	printf("size = %d - ", n);
	printf("src = %s dest = %s\n", src, dest);
	res = ft_strlcat(dest, src, n);
	printf("ft_strlcat : %i - ", res);
	printf("src = %s\n dest = %s\n", src, dest);

	printf("size = %d - ", n);
	printf("src2 = %s dest2 = %s\n", src2, dest2);
	res2 = strlcat(dest2, src2, n);
	printf("strlcat : %i - ", res2);
	printf("src2 = %s\n dest2 = %s\n", src2, dest2);
}*/
