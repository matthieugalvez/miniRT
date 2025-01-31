/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:54:39 by achantra          #+#    #+#             */
/*   Updated: 2024/12/06 17:23:23 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strndup(char *dest, const char *str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = str[i];
		i ++;
	}
	dest[n] = '\0';
	return ;
}

static int	count_word(const char *str, char c)
{
	int	i;
	int	count;

	if (!str[0])
		return (0);
	if (str[0] == c)
		count = 0;
	else
		count = 1;
	i = 1;
	while (str[i])
	{
		if (str[i] != c && str[i - 1] == c)
			count ++;
		i ++;
	}
	return (count);
}

static char	**ft_cpy_word(char **split, const char *str, char c, int cword)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < cword)
	{
		k = 0;
		while (str[j] && str[j] == c)
			j ++;
		while (str[j + k] && str[j + k] != c)
			k ++;
		split[i] = malloc((sizeof(char) * (k + 1)));
		if (!split[i])
		{
			ft_free_tab(split);
			return (NULL);
		}
		ft_strndup(split[i], &str[j], k);
		j = j + k;
		i ++;
	}
	split[cword] = 0;
	return (split);
}

char	**ft_split(char const *str, char c)
{
	int		cword;
	char	**split;

	if (!str)
		return (NULL);
	cword = count_word(str, c);
	split = malloc((sizeof(char *) * (cword + 1)));
	if (!split)
		return (NULL);
	split = ft_cpy_word(split, str, c, cword);
	return (split);
}
/*
int	main(void)
{
	ft_split(NULL, 'r');
}*/
