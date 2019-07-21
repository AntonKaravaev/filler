/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findposition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 21:33:53 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/22 00:40:30 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_putpiece(t_map *map, t_p *p)
{
	int i;
	int j;

	i = -1;
	if ((map->i + p->hight < map->hight) && (map->j + p->width < map->width))
	{
		while (++i < p->hight)
		{
			j = -1;
			while (++j < p->width && map->map[map->i + i][map->j + j] != map->enemy)
			{
				if (p->map[i][j] == '.')
				{
					if (map->map[map->i + i][map->j + j] == 2000
							|| map->map[map->i + i][map->j + j] == 1000)
						return ;
				}
				else if (p->map[i][j] == '*')
				{
					if (map->map[map->i + i][map->j + j] == 2000)
					{
						p->connection++;
						if (p->connection <= 1)
						{
							p->temp_i = map->i + i;
							p->temp_j = map->j + j;
						}
						else
							return;
					}
					else
						p->tempsum = p->tempsum + map->map[map->i + i][map->j + j];
				}
			}
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

void	ft_supforwrite(t_p *p)
{
	char	str[10];
	int 	i;
	int		del;

	i = 0;
	dprintf(3, "p->bestsum= %-5d p->best_i= %-5d p->best_j= %-5d\n", p->bestsum, p->best_i, p->best_j);
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
	str[i] = '\0';
	write(1, str, ft_strlen(str));
}

void		ft_findposition(t_map *map, t_p *p)
{
	while (map->i < map->hight)
	{
		map->j = 0;
		while (map->j < map->width)
		{
			p->tempsum = 0;
			p->temp_i = 0;
			p->temp_j = 0;
			p->connection = 0;
			p->bestsum = 100000;
			ft_putpiece(map, p);
			map->j++;
		}
		map->i++;
	}
	ft_supforwrite(p);
}
