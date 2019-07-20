/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findposition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 21:33:53 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/21 01:02:48 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_putpiece(t_map *map, t_p *p)
{
	int i;
	int j;

	i = 0;
	p->tempsum = 0;
	p->temp_i = 0;
	p->temp_j = 0;
	p->connection = 0;
	if ((map->i + p->hight < map->hight) && (map->j + p->width < map->width))
	{
		while (i < p->hight)
		{
			j = 0;
			while (j < p->width && map->map[map->i + i][map->j + j] != map->enemy)
			{
				if (p->map[i][j] == '.')
				{
				}
				else if (p->map[i][j] == '*')
				{
					if (map->map[map->i + i][map->j + j] == 2000)
					{
						p->connection++;
						if (p->connection <= 1)
						{
							p->temp_i = map->i + i;
							p->temp_j = map->j + j;							}
						else
							return;
					}
					else
						p->tempsum = p->tempsum + map->map[map->i + i][map->j + j];
				}
				j++;
			}
			i++;
		}
		if (p->tempsum < p->bestsum && p->connection == 1)
		{
			p->bestsum = p->tempsum;
			p->best_i = map->i;
			p->best_j = map->j;
		}
	}
	else
		return ;
}

void		ft_findposition(t_map *map, t_p *p)
{
	p->bestsum = 100000;
	p->best_i = 0;
	p->best_j = 0;
	map->i = 0;
	while (map->i < map->hight)
	{
		map->j = 0;
		while (map->j < map->width)
		{
			ft_putpiece(map, p);
			map->j++;
		}
		map->i++;
	}
	dprintf(1, "%d %d", p->best_i, p->best_j);
}
