/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:53:39 by emgarcia          #+#    #+#             */
/*   Updated: 2022/02/12 23:25:30 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometricconvert(t_general *g)
{
	size_t	i;
	size_t	j;
	float	xr;
	float	yr;

	i = -1;
	while (++i < g->h)
	{
		xr = g->c.x - (g->scale * i * cosf(MPI / 6));
		yr = g->c.y + (g->scale * i * sinf(MPI / 6));
		j = -1;
		while (++j < g->w)
		{
			g->map[i][j].x = xr + (g->scale * j * cosf(MPI / 6));
			g->map[i][j].y = yr + (g->scale * j * sinf(MPI / 6));
			g->map[i][j].y -= g->map[i][j].z;
		}
	}
}
