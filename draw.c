/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:09:34 by emgarcia          #+#    #+#             */
/*   Updated: 2022/02/20 19:31:25 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawpoints(t_general *g)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < g->h)
	{
		j = -1;
		while (++j < g->w)
			mlx_pixel_put(g->mlx, g->win, g->map[i][j].x, g->map[i][j].y, 250);
	}
}

int	ft_getcolor(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_drawline(t_general *g, t_point p1, t_point p2)
{
	float	m;
	float	y;
	float	x;
	int		color;

	m = (p2.y - p1.y) / (p2.x - p1.x);
	x = p1.x;
	while (x < 0)
		x++;
	y = (m * (x - p1.x)) + p1.y;
	while (y >= g->winh && ++x < p2.x)
		y = (m * (x - p1.x)) + p1.y;
	while (x < g->winw && x < p2.x && y < g->winh)
	{
		if (p1.z > 0)
			color = g->neutral * p1.z;
		else if (p1.z < 0)
			color = g->neutral * -p1.z + 3000;
		else
			color = g->neutral;
		ft_myputpixel(g, x, y, color);
		x += 0.1;
		y = (m * (x - p1.x)) + p1.y;
	}
}

void	ft_drawlines(t_general *g)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < g->h)
	{
		j = -1;
		while (++j < g->w - 1)
			ft_drawline(g, g->map[i][j], g->map[i][j + 1]);
	}
	j = -1;
	while (++j < g->w)
	{
		i = -1;
		while (++i < g->h - 1)
			ft_drawline(g, g->map[i + 1][j], g->map[i][j]);
	}
}

void	ft_myputpixel(t_general *g, int x, int y, int color)
{
	char	*dst;

	dst = g->addr + (y * g->linelenght + x * (g->bpp / 8));
	*(unsigned int *)dst = color;
}
