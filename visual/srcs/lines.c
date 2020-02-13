/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:12:51 by crenly-b          #+#    #+#             */
/*   Updated: 2020/02/12 15:19:53 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

static int	divis_right(int param, int *bug)
{
	int i;

	if (param < 20)
		i = 800;
	else if (param < 30)
		i = 900;
	else
		i = 990;
	while (i % param != 0)
		i--;
	*bug = i;
	return (i);
}

static int	ft_lines_sup(int hight, int width, int *bug)
{
	int param;

	param = 1;
	if (hight < 999 && width < 999)
	{
		if (hight < width)
			param = width;
		else
			param = hight;
	}
	else
		ft_error("Problem!(hight or width)\n");
	return ((int)divis_right(param, bug) / param);
}

static void	ft_initial_points(t_map *m)
{
	m->s.z = 0;
	m->f.z = 0;
	m->s.x = (int)((WOI - m->param * m->width) / 2);
	m->ini_s.x = m->s.x;
	m->f.x = m->s.x + m->param * m->width;
}

static void	ft_print_lines_y(t_map *m)
{
	int i;

	i = -1;
	m->s.y = (int)((HOI - m->param * m->hight) / 2);
	m->ini_s.y = m->s.y;
	m->f.y = m->ini_s.y + m->hight * m->param;
	while (++i <= m->width)
	{
		if (i == m->width)
		{
			if ((WOI - m->param * m->width) % 2 == 0)
				m->s.x = WOI - (int)((WOI - m->param * m->width) / 2);
			else
				m->s.x = WOI - (int)((WOI - m->param * m->width) / 2) - 1;
			m->f.x = m->s.x;
		}
		else
		{
			m->s.x = m->param * i + (int)((WOI - m->param * m->width) / 2);
			m->f.x = m->s.x;
		}
		draw_line(m, m->s, m->f, 0x808080);
	}
}

void		ft_print_lines(t_map *m)
{
	int i;

	m->param = ft_lines_sup(m->hight, m->width, &m->bug);
	ft_initial_points(m);
	i = -1;
	while (++i <= m->hight)
	{
		if (i == m->hight)
		{
			if ((HOI - m->param * m->hight) % 2 == 0)
				m->s.y = HOI - (int)((HOI - m->param * m->hight) / 2);
			else
				m->s.y = HOI - (int)((HOI - m->param * m->hight) / 2) - 1;
			m->f.y = m->s.y;
		}
		else
		{
			m->s.y = m->param * i + (int)((HOI - m->param * m->hight) / 2);
			m->f.y = m->s.y;
		}
		draw_line(m, m->s, m->f, 0x808080);
	}
	ft_print_lines_y(m);
}
