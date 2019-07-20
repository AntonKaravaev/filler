/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:33:09 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/20 23:53:51 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_strlen_num(int num)
{
	int length;

	length = 1;
	if (num > 9)
	{
		while (num > 9)
		{
			num = num / 10;
			length = length * 10;
		}
	}
	return (length);
}

char	*ft_fromnbrtos(int n, t_map *map)
{
	int		i;
	int		del;
	int		num;

	num = 0;
	if (n >= 0)
		i = n;
	else
	{
		i = (-1) * n;
		map->str[num++] = '-';
	}
	del = ft_strlen_num(i);
	while (del > 0)
	{
		map->str[num++] = (i / del) + '0';
		i = i % del;
		del = del / 10;
	}
	map->str[num] = '\0';
	return (map->str);
}

void ft_fillinheatmap(t_map *map, int i, int j)
{
	if ((j + 1 < map->width) && map->map[i][j + 1] == 0)
		map->map[i][j + 1] = map->num;
	if ((j - 1 >= 0) && map->map[i][j - 1] == 0)
		map->map[i][j - 1] = map->num;
	if (i == 0 && (i + 1 < map->hight))
	{
		if (map->map[i + 1][j] == 0)
			map->map[i + 1][j] = map->num;
		if ((j + 1 < map->width) && map->map[i + 1][j + 1] == 0)
			map->map[i + 1][j + 1] = map->num;
		if ((j - 1 >= 0) && map->map[i + 1][j - 1] == 0)
			map->map[i + 1][j - 1] = map->num;
	}
	else if ((i - 1 >= 0) && (i == map->hight - 1))
	{
		if (map->map[i - 1][j] == 0)
			map->map[i - 1][j] = map->num;
		if ((j + 1 < map->width) && map->map[i - 1][j + 1] == 0)
			map->map[i - 1][j + 1] = map->num;
		if ((j - 1 >= 0) && map->map[i - 1][j - 1] == 0)
			map->map[i - 1][j - 1] = map->num;
	}
	else
	{
		if (map->map[i + 1][j] == 0)
			map->map[i + 1][j] = map->num;
		if ((j + 1 < map->width) && map->map[i + 1][j + 1] == 0)
			map->map[i + 1][j + 1] = map->num;
		if ((j - 1 >= 0) && map->map[i + 1][j - 1] == 0)
			map->map[i + 1][j - 1] = map->num;
		if (map->map[i - 1][j] == 0)
			map->map[i - 1][j] = map->num;
		if ((j + 1 < map->width) && map->map[i - 1][j + 1] == 0)
			map->map[i - 1][j + 1] = map->num;
		if ((j - 1 >= 0) && map->map[i - 1][j - 1] == 0)
			map->map[i - 1][j - 1] = map->num;
	}
}

void ft_heatmap(t_map *map, t_p *p)
{
	int i;
	int j;
	int z;
	int check;

	i = 0;
	z = 0;
	map->num = 1;
	check = 1000;
	while (z < map->hight)
	{
		while (i < map->hight)
		{
			j = 0;
			while (j < map->width)
			{
				if (map->map[i][j] == check + z)
					ft_fillinheatmap(map, i, j);
				j++;
			}
			i++;
		}
		map->num += 1;
		check = 0;
		i = 0;
		z++;
	}
	z = 0;
	dprintf(3, "         0     1     2     3     4     5     6     7     8     9    10    11    12    13    14    15    16\n");
	dprintf(3, "__________________________________________________________________________________________________________\n");
	while (z < map->hight)
	{
		dprintf(3, "|%2d|", z);
		dprintf(3, "%6s", ft_fromnbrtos(map->map[z][0], map));
		dprintf(3, "%6s", ft_fromnbrtos(map->map[z][1], map));
		dprintf(3, "%6s", ft_fromnbrtos(map->map[z][2], map));
		dprintf(3, "%6s", ft_fromnbrtos(map->map[z][3], map));
		dprintf(3, "%6s", ft_fromnbrtos(map->map[z][4], map));
		dprintf(3, "%6s", ft_fromnbrtos(map->map[z][5], map));
		dprintf(3, "%6s", ft_fromnbrtos(map->map[z][6], map));
		dprintf(3, "%6s", ft_fromnbrtos(map->map[z][7], map));
		dprintf(3, "%6s", ft_fromnbrtos(map->map[z][8], map));
		dprintf(3, "%6s", ft_fromnbrtos(map->map[z][9], map));
		dprintf(3, "%6s", ft_fromnbrtos(map->map[z][10], map));
		dprintf(3, "%6s", ft_fromnbrtos(map->map[z][11], map));
		dprintf(3, "%6s", ft_fromnbrtos(map->map[z][12], map));
		dprintf(3, "%6s", ft_fromnbrtos(map->map[z][13], map));
		dprintf(3, "%6s", ft_fromnbrtos(map->map[z][14], map));
		dprintf(3, "%6s", ft_fromnbrtos(map->map[z][15], map));
		dprintf(3, "%6s|\n", ft_fromnbrtos(map->map[z][16], map));

		z++;
	}
	(void)p;
	ft_findposition(map, p);
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
	ft_heatmap(&map, &p);
	return (0);
}
