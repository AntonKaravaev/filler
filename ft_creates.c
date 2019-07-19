/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:09:18 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/19 22:33:58 by crenly-b         ###   ########.fr       */
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

void	ft_mapcreate(char *line, t_map *map)
{
	int i;

	i = 0;
	map->i_am = 0;
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
	if (!(map->map = (char **)malloc(sizeof(char *) * (map->hight + 1))))
		exit (-1);
	map->map[map->hight] = NULL;
	while (i < map->hight + 1)
	{
		get_next_line(0, &line);
		//dprintf(3, "%s\n", line);
		if (!(map->map[i] = (char *)malloc(sizeof(char) * (map->width))))
			exit (-1);
		ft_bzero(map->map[i], map->width);
		map->map[i] = ft_strcpy(map->map[i], line);
		dprintf(3, "%s\n", map->map[i]);
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
