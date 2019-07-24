/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createpiece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 23:20:33 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/23 22:29:18 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_newpiece(t_p *p)
{
	p->hight = 0;
	p->width = 0;
	p->connection = 0;
	p->tempsum = 0;
	p->best_i = 0;
	p->best_j = 0;
	p->max_i = 0;
	p->max_j = 0;
	p->bestsum = 100000;
}

static void		ft_catchpiece(char *line, t_p *p)
{
	if (get_next_line(0, &line) <= 0)
		exit(-1);
	p->map = ft_strsplit(line, ' ');
	p->hight = ft_atoi(p->map[1]);
	p->width = ft_atoi(p->map[2]);
	ft_str2del(&p->map);
}

void			ft_critical_ij(t_p *p)
{
	int i;
	int j;

	p->max_i = 0;
	p->max_j = 0;
	i = -1;
	while (++i < p->hight)
	{
		j = -1;
		while (++j < p->width)
		{
			if (p->map[i][j] == '*')
			{
				p->max_i = (i > p->max_i) ? i : p->max_i;
				p->max_j = (j > p->max_j) ? j : p->max_j;
			}
		}
	}
}

void			ft_createpiece(char *line, t_p *p)
{
	int i;

	i = 0;
	ft_newpiece(p);
	ft_catchpiece(line, p);
	if (!(p->map = (char **)malloc(sizeof(char *) * (p->hight + 1))))
		exit(-1);
	p->map[p->hight] = NULL;
	while (i < p->hight)
	{
		if (get_next_line(0, &line) <= 0)
			exit(-1);
		p->map[i] = ft_strdup(line);
		i++;
	}
	ft_critical_ij(p);
}
