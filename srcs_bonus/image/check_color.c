/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:59:16 by achantra          #+#    #+#             */
/*   Updated: 2025/02/26 15:05:05 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static  int is_odd_sp(t_hitpoint *hitpoint, t_element *figure)
{
    double  theta;
    double  phi;
    double  u;
    double  v;
    int     x_value;
    int     y_value;

    theta = atan2(hitpoint->coord->y, hitpoint->coord->x);
    phi = acos(2 * hitpoint->coord->z / figure->diameter);

    u = 20 * (theta + M_PI) / (2 * M_PI);
    v = 20 * (phi + M_PI_2) / M_PI;
    x_value = (int) u % 2;
    y_value = (int) v % 2;

    return ((x_value + y_value) % 2);
}

static  int is_odd_cy(t_hitpoint *hitpoint, t_element *figure)
{
    double  theta;
    double  z;
    double  u;
    double  v;
    int     x_value;
    int     y_value;

    theta = atan2(hitpoint->coord->y, hitpoint->coord->x);
    z = hitpoint->coord->z;

    u = 20 * (theta + M_PI) / (2 * M_PI);
    v = 20 * z / figure->height;
    x_value = (int) u % 2;
    y_value = (int) v % 2;

    return ((x_value + y_value) % 2);
}

static  int is_odd_coord(t_hitpoint *hitpoint, t_element *figure)
{
    if (figure->id == SPHERE)
        return (is_odd_sp(hitpoint, figure));
    if (figure->id == CYLINDER)
        return (is_odd_cy(hitpoint, figure));
    
    return (1);
}

void    find_hitpoint_color(t_hitpoint *hitpoint, t_element *figure)
{
    if (!figure->colorbis)
        hitpoint->color = figure->color;
    else
    {
        if (is_odd_coord(hitpoint, figure))
            hitpoint->color = figure->color;
        else
            hitpoint->color = figure->colorbis;
    }
}