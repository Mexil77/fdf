/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:03:30 by emgarcia          #+#    #+#             */
/*   Updated: 2022/02/12 22:45:32 by emgarcia         ###   ########.fr       */
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

void	ft_drawline(t_general *g, t_point p1, t_point p2)
{
	float	m;
	float	y;
	float	x;

	m = (p2.y - p1.y) / (p2.x - p1.x);
	x = p1.x;
	while (x < 0)
		x++;
	y = (m * (x - p1.x)) + p1.y;
	while (x < g->winw && y < g->winh && x < p2.x)
	{
		mlx_pixel_put(g->mlx, g->win, x++, y, 250);
		y = (m * (x - p1.x)) + p1.y;
	}
}
