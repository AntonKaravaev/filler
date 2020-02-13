/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 22:44:37 by crenly-b          #+#    #+#             */
/*   Updated: 2020/02/12 17:54:01 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_newmap(char **line, t_map *map)
{
	map->map = NULL;
	map->hight = 0;
	map->width = 0;
	map->enemy = -111;
	map->i = 0;
	map->j = 0;
	map->i_am = 0;
	if (get_next_line(0, &(*line)) <= 0)
		exit(-1);
	if (ft_strstr(*line, "$$$ exec p2") != NULL)
		map->i_am = 1;
	ft_strdel(line);
}

static void		ft_hight_width(char **line, t_map *map)
{
	char	**str;
	int		i;

	i = 0;
	if (get_next_line(0, &(*line)) <= 0)
		exit(-1);
	if (ft_strstr(*line, "Plateau") != NULL)
	{
		str = ft_strsplit(*line, ' ');
		map->hight = ft_atoi(str[1]);
		map->width = ft_atoi(str[2]);
		ft_str2del(&str);
		ft_strdel(line);
	}
}

static void		ft_createmapfirsttime(char **line, t_map *map, int i)
{
	map->onetime += 1;
	ft_newmap(line, map);
	ft_hight_width(line, map);
	if (!(map->map = (int **)malloc(sizeof(int *) * (map->hight))))
		exit(-1);
	if (get_next_line(0, &(*line)) <= 0)
		exit(-1);
	ft_strdel(line);
	while (i < map->hight)
	{
		if (get_next_line(0, &(*line)) <= 0)
			exit(-1);
		if (!(map->map[i] = (int *)malloc(sizeof(int) * (map->width))))
			exit(-1);
		map->map[i] = ft_str4cpy(map->map[i], *line, map->i_am);
		i++;
		ft_strdel(line);
	}
}

void			ft_createmap(char **line, t_map *map)
{
	int i;

	i = 0;
	if (map->onetime == 0)
		ft_createmapfirsttime(line, map, i);
	else
	{
		if (get_next_line(0, &(*line)) <= 0)
			exit(-1);
		ft_strdel(line);
		if (get_next_line(0, &(*line)) <= 0)
			exit(-1);
		ft_strdel(line);
		while (i < map->hight)
		{
			if (get_next_line(0, &(*line)) <= 0)
				exit(-1);
			map->map[i] = ft_str4cpy(map->map[i], *line, map->i_am);
			i++;
			ft_strdel(line);
		}
	}
}
