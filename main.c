/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:02:14 by emgarcia          #+#    #+#             */
/*   Updated: 2022/02/20 16:23:02 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_myputpixel(t_general *g, int x, int y, int color)
{
	char	*dst;

	dst = g->addr + (y * g->linelenght + x * (g->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_inigeneral(t_general *g, char *map)
{
	g->winw = 2000;
	g->winh = 1000;
	g->scale = 30;
	g->neutral = ft_getcolor(0, 247, 237, 49);
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->winw, g->winh, "so_long");
	if (!g->win)
		printf("Fallo al crear la ventana");
	g->c.x = g->winw / 2;
	g->c.y = g->winh / 10;
	g->c.z = 0;
	g->c.content = NULL;
	ft_inimap(g, map);
	g->img = mlx_new_image(g->mlx, g->winw, g->winh);
	g->addr = mlx_get_data_addr(g->img, &g->bpp, &g->linelenght, &g->endian);
}

void	ft_printgeneral(t_general *g)
{
	size_t	i;
	size_t	j;

	printf("c.x : %f\n", g->c.x);
	printf("c.y : %f\n", g->c.y);
	printf("c.z : %f\n", g->c.z);
	printf("c.content : %s\n", g->c.content);
	printf("c.h : %zu\n", g->h);
	printf("c.w : %zu\n", g->w);
	printf("c.winh : %d\n", g->winh);
	printf("c.winw : %d\n", g->winw);
	i = -1;
	while (++i < g->h)
	{
		j = -1;
		while (++j < g->w)
			printf("map[%zu][%zu] : (%f, %f, %f, %s)\n",
				i, j, g->map[i][j].x, g->map[i][j].y, g->map[i][j].z,
				g->map[i][j].content);
	}
}

/* ft_printgeneral(&general); */
int	main(int argc, char **argv)
{
	t_general	general;

	if (argc != 2)
	{
		printf("Fallo de argumentos %s\n", argv[0]);
		return (0);
	}
	ft_inigeneral(&general, argv[1]);
	ft_fillmap(&general, argv[1]);
	//ft_drawisometric(&general);
	ft_isometricconvert(&general);
	ft_drawlines(&general);
	//ft_printgeneral(&general);
	mlx_put_image_to_window(general.mlx, general.win, general.img, 0, 0);
	mlx_loop(general.mlx);
	return (0);
}
