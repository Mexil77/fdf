/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:02:48 by emgarcia          #+#    #+#             */
/*   Updated: 2022/02/12 22:44:25 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draworiginal(int w, int h, t_general *g)
{
	float		x;
	float		y;

	x = 0.0;
	while (x < w)
		mlx_pixel_put(g->mlx, g->win, x++, g->c.y, 250);
	y = 0.0;
	while (y < h)
		mlx_pixel_put(g->mlx, g->win, g->c.x, y++, 250);
}

void	ft_drawisometric(int w, int h, t_general *g)
{
	float	x;
	float	y;
	float	xend;
	t_point	p1;
	t_point	p2;

	p1.x = g->c.x;
	p1.y = g->c.y;
	p2.x = ((h - g->c.y) / tanf(MPI / 6) + g->c.x);
	p2.y = ((tan(MPI / 6) * (p2.x - (g->c.x))) + (g->c.y));
	ft_drawline(g, p1, p2);
	p1.x = ((h - g->c.y) / tanf(5 * MPI / 6) + g->c.x);
	p1.y = ((tan(5 * MPI / 6) * (p1.x - (g->c.x))) + (g->c.y));
	p2.x = g->c.x;
	p2.y = g->c.y;
	ft_drawline(g, p1, p2);
	w = 0;
	xend = 0;
	x = g->c.x;
	y = g->c.y;
	while (y > 0)
		mlx_pixel_put(g->mlx, g->win, x, y--, 250);
}

size_t	ft_splitlen(char **split)
{
	size_t	i;

	if (!split)
		return (0);
	i = 0;
	while (split[i])
		i++;
	return (i);
}

void	ft_freesplit(char **split)
{
	size_t	i;

	i = -1;
	while (split[++i])
		free (split[i]);
	free (split);
}

void	ft_freemap(t_point **map)
{
	size_t	i;

	i = -1;
	while (map[++i])
		free (map[i]);
	free (map);
}
