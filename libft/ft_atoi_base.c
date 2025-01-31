/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:35:32 by achantra          #+#    #+#             */
/*   Updated: 2024/12/02 00:52:07 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_base(const char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (i);
}

static int	ft_convert_int(const char *str, const char *base, int len_base)
{
	int	i;
	int	j;
	int	res;
	int	i_base;

	i = 0;
	res = 0;
	i_base = 0;
	while (str[i])
	{
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
			{
				i_base = j;
				break ;
			}
			j++;
		}
		res = res * len_base + i_base;
		i++;
	}
	return (res);
}

int	ft_atoi_base(const char *str, const char *base)
{
	int	len_base;
	int	s;
	int	res;
	int	i;

	i = 0;
	s = 1;
	len_base = check_base(base);
	if (len_base < 2)
		return (0);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1 * s;
		i++;
	}
	res = ft_convert_int(str + i, base, len_base);
	return (s * res);
}

/*int	main(void)
{
	char	str[] = "12035";
	char	base[] = "0123456789";
	int		i;

	i = ft_atoi_base(str, base);
	printf ("str %s en %s donne %d en base decimal", str, base, i);
	return (0);
}*/
