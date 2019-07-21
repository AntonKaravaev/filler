/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 23:20:33 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/22 00:42:45 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_newpiece(t_p *p)
{
	p->map = NULL;
	p->hight = 0;
	p->width = 0;
	p->connection = 0;
	p->temp_i = 0;
	p->temp_j = 0;
	p->tempsum = 0;
	p->best_i = 0;
	p->best_j = 0;
	p->bestsum = 100000;
}

static void		ft_catchpiece(char *line, t_p *p)
{
	get_next_line(0, &line);
	dprintf(3, "%s\n", line);
	p->map = ft_strsplit(line, ' ');
	p->hight = ft_atoi(p->map[1]);
	p->width = ft_atoi(p->map[2]);
	dprintf(3, "p->hight= %d\n", p->hight);
	dprintf(3, "p->width= %d\n", p->width);
	ft_str2del(&p->map);
}

void		ft_createpiece(char *line, t_p *p)
{
	int i;

	i = 0;
	ft_newpiece(p);
	ft_catchpiece(line, p);
	if (!(p->map = (char **)malloc(sizeof(char *) * p->hight)))
		exit (-1);
	p->map[p->hight] = NULL;
	while (i < p->hight)
	{
		get_next_line(0, &line);
		p->map[i] = ft_strdup(line);
		dprintf(3, "p->map[%d]= %s\n", i, p->map[i]);
		i++;
	}
}
