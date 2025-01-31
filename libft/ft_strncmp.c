/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:09:21 by achantra          #+#    #+#             */
/*   Updated: 2024/11/05 17:09:26 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] == s2[i])
			i += 1;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
/*
int	main(void)
{
	char		s1[] = "Hello";
	char		s2[] = "Helloooo";
	char		s3[] = "Salut";
	size_t		n = 15;
	unsigned int	i = 0;

	i = ft_strncmp(s1, s2, n);
	printf("ft_strncmp = %d\n", i);
	i = strncmp(s1, s2, n);
	printf("strncmp = %d\n", i);
	i = ft_strncmp(s1, s3, n);
	printf("ft_strncmp = %d\n", i);
	i = strncmp(s1, s3, i);
	printf("strncmp = %d\n", i);
	i = ft_strncmp(s1, s1, n);
	printf("ft_strncmp = %d\n", i);
	i = strncmp(s1, s1, n);
	printf("strncmp = %d\n", i);
	return (0);
}*/
