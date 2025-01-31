/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:32:18 by achantra          #+#    #+#             */
/*   Updated: 2024/12/05 21:22:12 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*d;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		d = malloc (sizeof(char));
		if (!d)
			return (NULL);
		d[0] = '\0';
		return (d);
	}
	d = malloc(sizeof(char) * (ft_min(ft_strlen(&s[start]), len) + 1));
	if (!d)
		return (NULL);
	i = 0;
	while (i < (unsigned int) len && s[start + i])
	{
		d[i] = s[start + i];
		i ++;
	}
	d[i] = '\0';
	return (d);
}
/*
int	main(void)
{
	printf("%s\n", ft_substr(NULL, 5, 20));
}*/