/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:08:56 by emgarcia          #+#    #+#             */
/*   Updated: 2022/02/12 23:28:46 by emgarcia         ###   ########.fr       */
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
	int		winh;
	int		winw;
	size_t	h;
	size_t	w;
	size_t	scale;
}	t_general;

/* Utils */
void	ft_draworiginal(int w, int h, t_general *g);
void	ft_drawisometric(int w, int h, t_general *g);
size_t	ft_splitlen(char **split);
void	ft_freesplit(char **split);
void	ft_freemap(t_point **map);

/* Utils2 */
void	ft_printsplit(char **split);
void	ft_drawline(t_general *g, t_point p1, t_point p2);
void	ft_drawpoints(t_general *g);
void	ft_drawlines(t_general *g);

/* Inimap */
void	ft_calcdim(int fd, size_t *w, size_t *h);
void	ft_inimap(t_general *g, char *map);
void	ft_fillmap(t_general *g, char *map);

/* Isometric */
void	ft_isometricconvert(t_general *g);

#endif