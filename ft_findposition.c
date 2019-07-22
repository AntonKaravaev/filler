/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findposition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 21:33:53 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/23 01:53:07 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_putpiece2(t_map *map, t_p *p)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < p->hight)
	{
		if (map->i + p->max_i >= map->hight)
			return 1;
		j = 0;
		while(j < p->width)
		{
			if (map->j + p->max_j >= map->width)
				return 1;
			if (p->map[i][j] == '.')
			{
				if ((map->i + i < map->hight) && (map->j + j < map->width))
				{
					if (map->map[map->i + i][map->j + j] != -222)
						p->tempsum += map->map[map->i + i][map->j + j];
				}
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
			j++;
		}
		i++;
	}
	return (0);
}

void		ft_putpiece(t_map *map, t_p *p)
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

int			ft_strlen_num(int num)
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

void		ft_supforwrite(t_p *p)
{
	char	str[10];
	int		i;
	int		del;

	i = 0;
	//dprintf(3, "p->bestsum= %-5d p->best_i= %-5d p->best_j= %-5d\n",
//	p->bestsum, p->best_i, p->best_j);
	if (p->best_i != -1 && p->best_j != -1)
	{
		del = ft_strlen_num(p->best_i);
		while (del > 0)
		{
			str[i++] = (p->best_i / del) + '0';
			p->best_i = p->best_i % del;
			del = del / 10;
		}
		str[i++] = ' ';
		del = ft_strlen_num(p->best_j);
		while (del > 0)
		{
			str[i++] = (p->best_j / del) + '0';
			p->best_j = p->best_j % del;
			del = del / 10;
		}
		str[i++] = '\n';
		str[i] = '\0';
		write(1, str, ft_strlen(str));
	}
	else
	{
		write(1, "-1 -1\n", 6);
	}
}

void		ft_findposition(t_map *map, t_p *p)
{
	p->bestsum = 100000;
	p->best_i = -1;
	p->best_j = -1;
	p->mayak = 0;
	p->help_i = -1;
	p->help_j = -1;
	//dprintf(3, "map->hight= %-5d map->width= %-5d\n", map->hight, map->width);
	//dprintf(3, "map->i= %-5d map->j= %-5d\n", map->i, map->j);
	//dprintf(3, "map->enemy %-5d\n", map->enemy);
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
	ft_supforwrite(p);
	// ft_str2del(&p->map);
}
