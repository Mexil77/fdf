/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inimap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:29:25 by emgarcia          #+#    #+#             */
/*   Updated: 2022/02/20 18:14:12 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_calcdim(int fd, size_t *w, size_t *h)
{
	char	*line;
	char	**split;

	split = NULL;
	line = get_next_line(fd);
	if (line)
		split = ft_split(line, ' ');
	*w = ft_splitlen(split);
	while (line)
	{
		(*h)++;
		free (line);
		line = get_next_line(fd);
	}
	ft_freesplit(split);
}

void	ft_inicords(t_general *g)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < g->h)
	{
		j = -1;
		while (++j < g->w)
		{
			g->map[i][j].x = j;
			g->map[i][j].y = i;
			g->map[i][j].z = 0;
			g->map[i][j].content = NULL;
		}
	}
}

void	ft_inimap(t_general *g, char *map)
{
	int		fd;
	size_t	i;

	fd = open(map, O_RDWR);
	if (fd < 0)
		return ;
	g->h = 0;
	g->w = 0;
	ft_calcdim(fd, &g->w, &g->h);
	g->map = ft_calloc(sizeof(t_point *), (g->h + 1));
	if (!g->map)
		return ;
	i = -1;
	while (++i < g->h)
	{
		g->map[i] = ft_calloc(sizeof(t_point), (g->w + 1));
		if (!g->map[i])
			return (ft_freemap(g));
	}
	ft_inicords(g);
	close (fd);
}

void	ft_fillpoint(t_general *g, char **split, size_t i)
{
	size_t	j;
	char	**auxsplit;

	j = -1;
	while (++j < ft_splitlen(split))
	{
		auxsplit = ft_split(split[j], ',');
		g->map[i][j].z = ft_atoi(auxsplit[0]);
		if (ft_splitlen(auxsplit) != 1)
			g->map[i][j].content = ft_strdup(auxsplit[1]);
		ft_freesplit(auxsplit);
	}
}

void	ft_fillmap(t_general *g, char *map)
{
	int		fd;
	size_t	i;
	char	*line;
	char	**split;

	fd = open(map, O_RDWR);
	if (fd < 0)
		return ;
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		split = ft_split(line, ' ');
		ft_fillpoint(g, split, i);
		ft_freesplit(split);
		free (line);
		line = get_next_line(fd);
		i++;
	}
	close (fd);
}
