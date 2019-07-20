/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:09:18 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/20 22:27:41 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

void	ft_hight_width(char *line, t_map *map)
{
	char **str;
	int i;

	i = 0;
	str = ft_strsplit(line, ' ');
	map->hight = ft_atoi(str[1]);
	map->width = ft_atoi(str[2]);
	dprintf(3, "map->hight= %d\n", map->hight);
	dprintf(3, "map->width= %d\n", map->width);
	ft_str2del(&str);
}

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

void	ft_mapcreate(char *line, t_map *map)
{
	int i;

	i = 0;
	map->i_am = 0;
	map->enemy = 1000;
	get_next_line(0, &line);
	if (ft_strstr(line, "$$$ exec p2") != NULL)
	{
		map->i_am = 1;
		dprintf(3, "%s\n", "I am player 2\n");
	}
	else
		dprintf(3, "%s\n", "I am player 1\n");
	get_next_line(0, &line);
	ft_hight_width(line, map);
	get_next_line(0, &line);
	if (!(map->map = (int **)malloc(sizeof(int *) * (map->hight + 1))))
		exit (-1);
	map->map[map->hight] = NULL;
	while (i < map->hight)
	{
		get_next_line(0, &line);
		if (!(map->map[i] = (int *)malloc(sizeof(int) * (map->width))))
			exit (-1);
		map->map[i] = ft_str4cpy(map->map[i], line, map->i_am);
		// dprintf(3, "%6c", (char)(map->map[i][0] + 48));
		// dprintf(3, "%6c", (char)(map->map[i][1] + 48));
		// dprintf(3, "%6c", (char)(map->map[i][2] + 48));
		// dprintf(3, "%6c", (char)(map->map[i][3] + 48));
		// dprintf(3, "%6c", (char)(map->map[i][4] + 48));
		// dprintf(3, "%6c", (char)(map->map[i][5] + 48));
		// dprintf(3, "%6c", (char)(map->map[i][6] + 48));
		// dprintf(3, "%6c", (char)(map->map[i][7] + 48));
		// dprintf(3, "%6c", (char)(map->map[i][8] + 48));
		// dprintf(3, "%6c", (char)(map->map[i][9] + 48));
		// dprintf(3, "%6c", (char)(map->map[i][10] + 48));
		// dprintf(3, "%6c", (char)(map->map[i][11] + 48));
		// dprintf(3, "%6c", (char)(map->map[i][12] + 48));
		// dprintf(3, "%6c", (char)(map->map[i][13] + 48));
		// dprintf(3, "%6c", (char)(map->map[i][14] + 48));
		// dprintf(3, "%6c", (char)(map->map[i][15] + 48));
		// dprintf(3, "%6c\n", (char)(map->map[i][16] + 48));
		i++;
	}
}

void	ft_catchpiece(char *line, t_p *p)
{
	int i;

	i = 0;
	get_next_line(0, &line);
	p->map = ft_strsplit(line, ' ');
	p->hight = ft_atoi(p->map[1]);
	p->width = ft_atoi(p->map[2]);
	dprintf(3, "map->hight= %d\n", p->hight);
	dprintf(3, "map->width= %d\n", p->width);
	ft_str2del(&p->map);
	if (!(p->map = (char **)malloc(sizeof(char *) * p->hight)))
		exit (-1);
	p->map[p->hight] = NULL;
	while (i < p->hight)
	{
		get_next_line(0, &line);
		p->map[i] = ft_strdup(line);
		dprintf(3, "%s\n", p->map[i]);
		i++;
	}
}
