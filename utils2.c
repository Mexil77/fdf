/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:03:30 by emgarcia          #+#    #+#             */
/*   Updated: 2022/02/13 06:37:04 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_printsplit(char **split)
{
	size_t	i;

	if (!split)
		return ;
	i = -1;
	while (split[++i])
		printf("%s\n", split[i]);
}

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
	while (y > g->winh && ++x < p2.x)
		y = (m * (x - p1.x)) + p1.y;
	while (x < g->winw && x < p2.x)
	{
		if (p1.z > 0)
			color = g->neutral * p1.z;
		else if (p1.z < 0)
			color = g->neutral * -p1.z + 3000;
		else
			color = g->neutral;
		mlx_pixel_put(g->mlx, g->win, x, y, color);
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
