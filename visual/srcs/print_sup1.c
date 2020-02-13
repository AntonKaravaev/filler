/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sup1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:05:18 by crenly-b          #+#    #+#             */
/*   Updated: 2020/02/12 17:13:36 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

void	ft_draw_sq_x(t_map *m, int i, int j, int col)
{
	t_point	pos;
	t_point	fin;
	int		iter;
	int		finish;

	pos.x = m->ini_s.x + i * m->param + 1;
	pos.y = m->ini_s.y + j * m->param;
	fin.y = pos.y;
	iter = pos.x - 1;
	finish = pos.x + m->param - 1;
	fin.x = finish - 1;
	while (++iter < finish)
	{
		pos.y++;
		fin.y++;
		draw_line(m, pos, fin, col);
	}
}

void	ft_draw_sq_o(t_map *m, int i, int j, int col)
{
	t_point	pos;
	t_point	fin;
	int		iter;
	int		finish;

	pos.x = m->ini_s.x + i * m->param + 1;
	pos.y = m->ini_s.y + j * m->param;
	fin.y = pos.y;
	iter = pos.x - 1;
	finish = pos.x + m->param - 1;
	fin.x = finish - 1;
	while (++iter < finish)
	{
		pos.y++;
		fin.y++;
		draw_line(m, pos, fin, col);
	}
}

int		closee(t_map *m)
{
	mlx_destroy_window(m->mlx_ptr, m->win_ptr);
	exit(0);
}

void	readprint_sup(t_map *m, char **l, int param)
{
	if (param < 0)
		ft_error("Some problems with gnl\n");
	if (*l != NULL && ft_strstr(*l, "== ") != NULL
		&& m->space_flag != 2 && m->step_flag != 2)
	{
		m->p1_res = ft_catch_num(l);
		ft_strdel(l);
		if ((get_next_line(m->fd, l)) < 0)
			ft_error("Some problems with gnl\n");
		m->p2_res = ft_catch_num(l);
		ft_strdel(l);
		print_menu_sup2(m, &m->i, m->mlx_ptr, m->win_ptr);
		if (m->space_flag == 1)
			mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->img, 0, 0);
		m->space_flag = 2;
		m->step_flag = 2;
	}
}

void	ft_catch_players_sup(char **line, int fd, int i, int fin)
{
	if (get_next_line(fd, &(*line)) <= 0)
		ft_error("Some problems with gnl\n");
	if (i < fin)
		ft_strdel(line);
}
