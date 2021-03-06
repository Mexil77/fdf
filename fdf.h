/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:08:56 by emgarcia          #+#    #+#             */
/*   Updated: 2022/02/20 19:31:33 by emgarcia         ###   ########.fr       */
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
	int		neutral;
	void	*img;
	char	*addr;
	int		bpp;
	int		linelenght;
	int		endian;
	size_t	h;
	size_t	w;
	size_t	scale;
}	t_general;

/* Main */

/* Utils */
void	ft_draworiginal(int w, int h, t_general *g);
void	ft_drawisometric(t_general *g);
size_t	ft_splitlen(char **split);
void	ft_freesplit(char **split);
void	ft_freemap(t_general *g);

/* Utils2 */
void	ft_printsplit(char **split);
int		ft_hextoint(char *num, char *newbase);

/* Draw */
void	ft_drawline(t_general *g, t_point p1, t_point p2);
void	ft_drawpoints(t_general *g);
void	ft_drawlines(t_general *g);
int		ft_getcolor(int t, int r, int g, int b);
void	ft_myputpixel(t_general *g, int x, int y, int color);

/* Inimap */
void	ft_calcdim(int fd, size_t *w, size_t *h);
void	ft_inimap(t_general *g, char *map);
void	ft_fillmap(t_general *g, char *map);

/* Isometric */
void	ft_isometricconvert(t_general *g);

#endif