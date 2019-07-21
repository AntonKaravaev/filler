/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supfun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 23:19:04 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/22 00:40:33 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		*ft_str4cpy(int *dst, char *src, int who)
{
	size_t i;
	size_t j;

	i = 0;
	j = 4;
	while (src[j] != '\0')
	{
		if (src[j] == '.')
			dst[i] = 0;
		else if (who == 0)
		{
			if (src[j] == 'X' || src[j] == 'x')
				dst[i] = 1000;
			else if (src[j] == 'O' || src[j] == 'o')
				dst[i] = 2000;
		}
		else
		{
			if (src[j] == 'X' || src[j] == 'x')
				dst[i] = 2000;
			else if (src[j] == 'O' || src[j] == 'o')
				dst[i] = 1000;
		}
		i++;
		j++;
	}
	return (dst);
}

void	ft_str2del(char ***str)
{
	int i;

	i = 0;
	while ((*str)[i] != NULL)
	{
		ft_strdel(&((*str)[i]));
		i++;
	}
	free(*str);
}

void	ft_intstrdel(int **as)
{
	if (as)
	{
		if (*as != NULL)
		{
			free(*as);
			*as = NULL;
		}
	}
}

void	ft_intstr2del(t_map *map, int ***str)
{
	int i;

	i = 0;
	while (i < map->hight)
	{
		ft_intstrdel(&((*str)[i]));
		i++;
	}
	free(*str);
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

void		ft_printmap(t_map *map)
{
	int z;

	z = 0;
	dprintf(3, "         0     1     2     3     4     5     6     7     8     9    10    11    12    13    14    15    16\n");
	dprintf(3, "|--|------------------------------------------------------------------------------------------------------|\n");
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
	dprintf(3, "|--|------------------------------------------------------------------------------------------------------|\n");
}
