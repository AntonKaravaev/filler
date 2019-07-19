/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:33:09 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/19 22:32:40 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


void ft_fillinheatmap(t_map *map, int i, int j)
{
	if ((j + 1 <= map->width + 3) && map->map[i][j + 1] == '.')
		map->map[i][j + 1] = '1';
	if ((j - 1 >= 4) && map->map[i][j - 1] == '.')
		map->map[i][j + 1] = '1';
	// if (i == 0 && (i + 1 <= map->hight - 1))
	// {
	// 	if (map->map[i + 1][j] == '.')
	// 		map->map[i + 1][j] = '1';
	// 	if (map->map[i + 1][j + 1] == '.' && (j + 1 <= map->width - 1))
	// 		map->map[i + 1][j + 1] = '1';
	// 	if (map->map[i + 1][j - 1] == '.' && (j - 1 >= 0))
	// 		map->map[i + 1][j - 1] = '1';
	// }
	// else if (i == map->hight - 1 && (i - 1 >= 0))
	// {
	// 	if (map->map[i - 1][j] == '.')
	// 		map->map[i - 1][j] = '1';
	// 	if (map->map[i - 1][j + 1] == '.' && (j + 1 <= map->width - 1))
	// 		map->map[i - 1][j + 1] = '1';
	// 	if (map->map[i - 1][j - 1] == '.' && (j - 1 >= 0))
	// 		map->map[i - 1][j - 1] = '1';
	// }
	// else
	// {
	// 	if (map->map[i + 1][j] == '.')
	// 		map->map[i + 1][j] = '1';
	// 	if (map->map[i + 1][j + 1] == '.' && (j + 1 <= map->width - 1))
	// 		map->map[i + 1][j + 1] = '1';
	// 	if (map->map[i + 1][j - 1] == '.' && (j - 1 >= 0))
	// 		map->map[i + 1][j - 1] = '1';
	// 	if (map->map[i - 1][j] == '.')
	// 		map->map[i - 1][j] = '1';
	// 	if (map->map[i - 1][j + 1] == '.' && (j + 1 <= map->width - 1))
	// 		map->map[i - 1][j + 1] = '1';
	// 	if (map->map[i - 1][j - 1] == '.' && (j - 1 >= 0))
	// 		map->map[i - 1][j - 1] = '1';
	// }

}

void ft_heatmap(t_map *map)
{
	int i;
	int j;

	i = 1;
	while (i < map->hight + 1)
	{
		j = 4;
		while (j < map->width + 4)
		{
			//dprintf(3, "Hello123\n");
			if (map->map[i][j] == 'X')
				ft_fillinheatmap(map, i, j);
			j++;
		}
		dprintf(3, "map->map[%2d] = %s\n", i, map->map[i]);
		i++;
	}
}

int		main(void)
{
	t_map	map;
	t_p		p;
	int		fd;
	char	*line;

	line = NULL;
	fd = open("file.txt", O_RDWR);
	ft_mapcreate(line ,&map);
	ft_catchpiece(line, &p);
	ft_heatmap(&map);
	return (0);
}
