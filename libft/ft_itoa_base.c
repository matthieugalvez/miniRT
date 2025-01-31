/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:40:17 by achantra          #+#    #+#             */
/*   Updated: 2024/12/02 00:51:30 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

static char	*convert_to_char(int nbr, char *base, int len_nbr_base,
		char *nbr_base)
{
	int	q;
	int	s;
	int	len_base;

	len_base = ft_strlen(base);
	s = 1;
	if (nbr < 0)
	{
		nbr_base[0] = '-';
		s = -1;
	}
	nbr_base[len_nbr_base] = '\0';
	q = nbr;
	while (len_nbr_base > 1)
	{
		nbr_base[len_nbr_base - 1] = base[s * (q % len_base)];
		len_nbr_base--;
		q = q / len_base;
	}
	if (nbr >= 0)
		nbr_base[0] = base[(q % len_base)];
	return (nbr_base);
}

char	*ft_itoa_base(int nbr, char *base)
{
	int		len_base;
	char	*nbr_base;
	int		len_nbr_base;
	int		q;

	if (!check_base(base))
		return (NULL);
	len_base = ft_strlen(base);
	len_nbr_base = 0;
	if (nbr == 0)
		len_nbr_base++;
	q = nbr;
	while (q != 0)
	{
		q = q / len_base;
		len_nbr_base++;
	}
	if (nbr < 0)
		len_nbr_base += 1;
	nbr_base = malloc((sizeof(char) * (len_nbr_base + 1)));
	if (!nbr_base)
		return (NULL);
	return (convert_to_char(nbr, base, len_nbr_base, nbr_base));
}

/*
int	main(void)
{
	int i = -1;
	char	base[] = "01";
	char    *res;

	res = ft_itoa_base(i, base);
	printf ("str %d en base decimal donne %s en base %s", i, res, base);
	free(res);
	return (0);
}*/