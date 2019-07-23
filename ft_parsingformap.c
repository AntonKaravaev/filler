/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsingformap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 22:44:37 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/23 15:42:14 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_newmap(t_map *map)
{
	map->map = NULL;
	map->hight = 0;
	map->width = 0;
	map->enemy = -111;
	map->i = 0;
	map->j = 0;
	map->i_am = 0;
}

static void		ft_whoami(char *line, t_map *map)
{
	get_next_line(0, &line);
	if (ft_strstr(line, "$$$ exec p2") != NULL)
	{
		map->i_am = 1;
		//dprintf(3, "%s\n", "I am player 2\n");
	}
	//else
		//dprintf(3, "%s\n", "I am player 1\n");
}

static void		ft_hight_width(char *line, t_map *map)
{
	char **str;
	int i;

	i = 0;
	get_next_line(0, &line);
	if (ft_strstr(line, "Plateau") != NULL)
	{
		str = ft_strsplit(line, ' ');
		map->hight = ft_atoi(str[1]);
		map->width = ft_atoi(str[2]);
		//dprintf(3, "map->hight= %d\n", map->hight);
		//dprintf(3, "map->width= %d\n", map->width);
		ft_str2del(&str);
	}
}

static void		ft_createmap(char *line, t_map *map)
{
	int i;

	i = 0;
	if (map->onetime == 0)
	{
		map->onetime += 1;
		ft_newmap(map);
		ft_whoami(line, map);
		ft_hight_width(line, map);
		if (!(map->map = (int **)malloc(sizeof(int *) * (map->hight + 1))))
			exit (-1);
		map->map[map->hight] = NULL;
		get_next_line(0, &line);
		while (i < map->hight)
		{
			get_next_line(0, &line);
			if (!(map->map[i] = (int *)malloc(sizeof(int) * (map->width))))
				exit (-1);
			map->map[i] = ft_str4cpy(map->map[i], line, map->i_am);
			i++;
		}
	}
	else
	{
		if (get_next_line(0, &line) == 0)
		{
		//	dprintf(3, "What i am doing here\n");
			exit(-1);
		}
		//dprintf(3, "line= %s\n", line);
		get_next_line(0, &line);
		while (i < map->hight)
		{
			get_next_line(0, &line);
			map->map[i] = ft_str4cpy(map->map[i], line, map->i_am);
			i++;
		}
	}
	//ft_printmap(map);
}

void	ft_working(char *line, t_map *map, t_p *p)
{
	ft_createmap(line, map);
	ft_createpiece(line, p);
	ft_heatmap(map);
	ft_printmap(map);
	ft_findposition(map, p);
}
