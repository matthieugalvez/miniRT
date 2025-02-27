/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:16:26 by achantra          #+#    #+#             */
/*   Updated: 2025/02/27 14:28:59 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	equal_double(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (1);
	return (0);
}

void	double_decrement(double *d)
{
	if (!equal_double(*d, __DBL_MAX__ * -1))
	{
		if (*d < __DBL_MAX__ * -1 + 1)
			*d = __DBL_MAX__ * -1 + 1;
		else
			*d -= 1;
	}
}

void	double_increment(double *d)
{
	if (!equal_double(*d, __DBL_MAX__))
	{
		if (*d > __DBL_MAX__ - 1)
			*d = __DBL_MAX__;
		else
			*d += 1;
	}
}
