/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heatmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 23:29:54 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/23 19:40:28 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_fillinheatmap(t_map *map, int i, int j)
{
	if ((j + 1 < map->width) && map->map[i][j + 1] == 0)
		map->map[i][j + 1] = map->num;
	if ((j - 1 >= 0) && map->map[i][j - 1] == 0)
		map->map[i][j - 1] = map->num;
	if (i == 0 && (i + 1 < map->hight))
	{
		if (map->map[i + 1][j] == 0)
			map->map[i + 1][j] = map->num;
	}
	else if ((i - 1 >= 0) && (i == map->hight - 1))
	{
		if (map->map[i - 1][j] == 0)
			map->map[i - 1][j] = map->num;
	}
	else
	{
		if (map->map[i + 1][j] == 0)
			map->map[i + 1][j] = map->num;
		if (map->map[i - 1][j] == 0)
			map->map[i - 1][j] = map->num;
	}
}

void			ft_heatmap(t_map *map)
{
	int i;
	int j;
	int z;
	int check;

	i = -1;
	z = -1;
	map->num = 1;
	check = -111;
	while (++z < map->hight * map->hight)
	{
		while (++i < map->hight)
		{
			j = -1;
			while (++j < map->width)
			{
				if (map->map[i][j] == check + z)
					ft_fillinheatmap(map, i, j);
			}
		}
		map->num += 1;
		check = 0;
		i = 0;
	}
}
