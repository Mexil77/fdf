/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:02:14 by emgarcia          #+#    #+#             */
/*   Updated: 2022/02/12 22:46:22 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_inigeneral(t_general *g, char *map)
{
	g->winh = 500;
	g->winw = 1000;
	g->scale = 20;
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->winw, g->winh, "so_long");
	if (!g->win)
		printf("Fallo al crear la ventana");
	g->c.x = g->winw / 3;
	g->c.y = g->winh / 4;
	g->c.z = 0;
	g->c.content = NULL;
	ft_inimap(g, map);
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
		while (++j < g->h)
			printf("map[%zu][%zu] : (%f, %f, %f, %s)\n",
				j, i, g->map[i][j].x, g->map[i][j].y, g->map[i][j].z,
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
	//ft_draworiginal(general.winw, general.winh, &general);
	ft_drawisometric(general.winw, general.winh, &general);
	mlx_loop(general.mlx);
	return (0);
}
