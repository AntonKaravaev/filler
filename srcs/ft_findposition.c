/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findposition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 21:33:53 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/23 19:40:29 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_putpiece3(t_map *map, t_p *p, int i, int j)
{
	if (p->map[i][j] == '.')
	{
		if ((map->i + i < map->hight) && (map->j + j < map->width))
			if (map->map[map->i + i][map->j + j] != -222)
				p->tempsum += map->map[map->i + i][map->j + j];
	}
	else if (p->map[i][j] == '*')
	{
		if ((map->i + i < map->hight) && (map->j + j < map->width))
		{
			if (map->map[map->i + i][map->j + j] == -111)
				return (1);
			else if (map->map[map->i + i][map->j + j] == -222)
			{
				p->connection++;
				if (p->connection > 1)
					return (1);
			}
			else
				p->tempsum += map->map[map->i + i][map->j + j];
		}
	}
	return (0);
}

static int		ft_putpiece2(t_map *map, t_p *p)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < p->hight)
	{
		if (map->i + p->max_i >= map->hight)
			return (1);
		j = 0;
		while (j < p->width)
		{
			if ((map->j + p->max_j >= map->width) ||
				(ft_putpiece3(map, p, i, j) == 1))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void		ft_putpiece(t_map *map, t_p *p)
{
	if (ft_putpiece2(map, p) == 1)
		return ;
	if (p->tempsum != 0 && (p->tempsum < p->bestsum) && p->connection == 1)
	{
		p->bestsum = p->tempsum;
		p->best_i = map->i;
		p->best_j = map->j;
	}
	else if ((p->tempsum < p->bestsum) && p->connection == 1)
	{
		p->mayak = 1;
		p->help_i = map->i;
		p->help_j = map->j;
	}
}

void			ft_findposition(t_map *map, t_p *p)
{
	p->bestsum = 100000;
	p->best_i = -1;
	p->best_j = -1;
	p->mayak = 0;
	p->help_i = -1;
	p->help_j = -1;
	while (map->i < map->hight)
	{
		map->j = 0;
		while (map->j < map->width)
		{
			p->connection = 0;
			p->tempsum = 0;
			ft_putpiece(map, p);
			map->j++;
		}
		map->i++;
	}
	map->i = 0;
	map->j = 0;
	if (p->bestsum == 100000 && p->mayak == 1)
	{
		p->best_i = p->help_i;
		p->best_j = p->help_j;
	}
}
