/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:08:56 by emgarcia          #+#    #+#             */
/*   Updated: 2022/02/08 14:06:33 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "Libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <mlx.h>
# include <time.h>
# include <math.h>

# ifndef MPI
#  define MPI 3.14159265358979323846
# endif

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	char	*content;
}	t_point;

typedef struct s_general
{
	t_point	**map;
	t_point	c;
	void	*mlx;
	void	*win;
}	t_general;

#endif