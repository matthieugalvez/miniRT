/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:37:52 by achantra          #+#    #+#             */
/*   Updated: 2025/02/01 12:47:57 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "struct.h"

# define HEXA "0123456789abcdef"

# define WIN_W 1000
# define WIN_H 1000

# define INCR_TRAN 1
# define INCR_ROT 0.1
# define INCR_EL 0.1
# define INCR_ZOOM 1

# define DBLUE 0x00008b
# define LBLUE 0x1e90ff
# define TBLUE 0x40e0d0

# define KEY_ESC 65307
# define KEY_PLUS 65451
# define KEY_MINUS 65453
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_X 120
# define KEY_Y 121
# define KEY_Z 122
# define KEY_A 97
# define KEY_B 98
# define KEY_C 99
# define KEY_I 105
# define KEY_P 112
# define KEY_K 107
# define KEY_D 100
# define KEY_E 101

int check_entry(int ac, char **av);
int parse_file(char *path, t_env *env);
t_env   *init_env();
void    clean_env(t_env *env);

#endif