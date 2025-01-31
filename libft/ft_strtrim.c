/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:49:54 by achantra          #+#    #+#             */
/*   Updated: 2024/11/13 18:58:10 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_char(char c, char const *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i ++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;

	if (!s1)
		return (NULL);
	if (!set || ft_strlen(set) == 0)
		return (ft_strdup(s1));
	start = 0;
	while (s1[start] && find_char(s1[start], set))
		start ++;
	end = ft_strlen(s1);
	if (start == end)
		return (ft_strdup("\0"));
	while (find_char(s1[end - 1], set) && end > 0)
		end --;
	return (ft_substr(s1, start, end - start));
}
