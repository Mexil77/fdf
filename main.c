/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:02:14 by emgarcia          #+#    #+#             */
/*   Updated: 2022/02/12 17:58:13 by emgarcia         ###   ########.fr       */
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

	x = (float)(g->c.x);
	y = ((tan(MPI / 6) * (x - (g->c.x))) + (g->c.y));
	xend = (h + (w * tanf(MPI / 6))) / (2 * tanf(MPI / 6));
	while (x < w && y < h && x < xend)
	{
		mlx_pixel_put(g->mlx, g->win, x++, y, 250);
		y = ((tan(MPI / 6) * (x - (g->c.x))) + (g->c.y));
	}
	x = (h + (w * tanf(5 * MPI / 6))) / (2 * tanf(5 * MPI / 6));
	y = ((tan(5 * MPI / 6) * (x - (g->c.x))) + (g->c.y));
	xend = g->c.x;
	while (x < 0)
		x++;
	while (x < xend)
	{
		mlx_pixel_put(g->mlx, g->win, x++, y, 250);
		y = ((tan(5 * MPI / 6) * (x - (g->c.x))) + (g->c.y));
	}
	x = g->c.x;
	y = g->c.y;
	while (y > 0)
		mlx_pixel_put(g->mlx, g->win, x, y--, 250);
}

int	main(int argc, char **argv)
{
	t_general	general;
	int			h;
	int			w;

	if (argc != 1)
		printf("Fallo de argumentos %s\n", argv[0]);
	h = 500;
	w = 1000;
	general.mlx = mlx_init();
	general.win = mlx_new_window(general.mlx, w, h, "so_long");
	if (!general.win)
		printf("Fallo al crear la ventana");
	general.c.x = w / 2;
	general.c.y = h / 2;
	general.c.z = 0;
	general.c.content = NULL;
	ft_draworiginal(w, h, &general);
	ft_drawisometric(w, h, &general);
	mlx_loop(general.mlx);
	return (0);
}
