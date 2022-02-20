/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:03:30 by emgarcia          #+#    #+#             */
/*   Updated: 2022/02/20 19:43:22 by emgarcia         ###   ########.fr       */
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

int	ft_getvalue(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] && c != base[i])
		i++;
	return (i);
}

int	ft_hextoint(char *num, char *newbase)
{
	size_t	maxpow;
	size_t	base;
	size_t	i;
	int		res;

	maxpow = ft_strlen(num) - 1;
	base = ft_strlen(newbase);
	res = 0;
	i = -1;
	while (num[++i])
		res += (ft_getvalue(num[i], newbase) * pow(base, maxpow - i));
	return (res);
}
