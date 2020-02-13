/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 22:47:31 by crenly-b          #+#    #+#             */
/*   Updated: 2020/02/12 16:55:04 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

static void		ft_iapb(t_boarder *bor)
{
	bor->p[0].x = 0;
	bor->p[0].y = 0;
	bor->p[0].z = 0;
	bor->p[0].color = COB;
	bor->p[1].x = 999;
	bor->p[1].y = 0;
	bor->p[1].z = 0;
	bor->p[1].color = COB;
	bor->p[2].x = 0;
	bor->p[2].y = 999;
	bor->p[2].z = 0;
	bor->p[2].color = COB;
	bor->p[3].x = 999;
	bor->p[3].y = 999;
	bor->p[3].z = 0;
	bor->p[3].color = COB;
}

void			ft_init_and_print_board(t_map *map)
{
	t_boarder	bor;
	t_point		s;
	t_point		f;

	ft_iapb(&bor);
	s = bor.p[0];
	f = bor.p[1];
	draw_line(map, s, f, COB);
	s = bor.p[0];
	f = bor.p[2];
	draw_line(map, s, f, COB);
	s = bor.p[2];
	f = bor.p[3];
	draw_line(map, s, f, COB);
	s = bor.p[1];
	f = bor.p[3];
	draw_line(map, s, f, COB);
}

void			print_menu_sup2(t_map *map, int *i, void *m, void *w)
{
	char	*str;
	char	*str2;

	mlx_string_put(m, w, 1180, *i += 30, COB, "RESULTS: ");
	str = ft_itoa(map->p1_res);
	str2 = ft_strjoin("Player1 = ", str);
	mlx_string_put(m, w, 1040, *i += 30, COB, str);
	ft_strdel(&str);
	ft_strdel(&str2);
	str = ft_itoa(map->p2_res);
	str2 = ft_strjoin("Player2 = ", str);
	mlx_string_put(m, w, 1040, *i += 30, COB, str);
	ft_strdel(&str);
	ft_strdel(&str2);
	mlx_string_put(m, w, 1155, *i += 70, COB, "THE WINNER IS : ");
	if (map->p1_res > map->p2_res)
		mlx_string_put(m, w, 1150, *i += 30, 0x007D34, map->name1);
	else
		mlx_string_put(m, w, 1150, *i += 30, 0x9966CC, map->name2);
}

static void		print_menu_sup1(t_map *map, int *i, void *m, void *w)
{
	char	*str;
	char	*str2;

	str = ft_strjoin("Player1     ", map->name1);
	mlx_string_put(m, w, 1040, *i += 30,
		0x007D34, str);
	ft_strdel(&str);
	str = ft_strjoin("Player2     ", map->name2);
	mlx_string_put(m, w, 1040, *i += 30,
		0x9966CC, str);
	ft_strdel(&str);
	mlx_string_put(m, w, 1165, *i += 60, COB, "MAPS PARAM:");
	str2 = ft_itoa(map->hight);
	str = ft_strjoin("hight = ", str2);
	mlx_string_put(m, w, 1040, *i += 30, COB, str);
	ft_strdel(&str);
	ft_strdel(&str2);
	str2 = ft_itoa(map->width);
	str = ft_strjoin("width = ", str2);
	mlx_string_put(m, w, 1040, *i += 30, COB, str);
	ft_strdel(&str);
	ft_strdel(&str2);
}

void			print_menu(t_map *map)
{
	int		i;
	void	*m;
	void	*w;

	i = 0;
	m = map->mlx_ptr;
	w = map->win_ptr;
	mlx_clear_window(m, w);
	mlx_string_put(m, w, 1150, i += 35, COB, "  Filler game");
	mlx_string_put(m, w, 1200, i += 65, COB, "MENU");
	mlx_string_put(m, w, 1040, i += 30, COB, "Put space - to show result");
	mlx_string_put(m, w, 1040, i += 30, COB,
			"Put right_arrow - to do one step");
	mlx_string_put(m, w, 1180, i += 60, COB, "PLAYERS :");
	print_menu_sup1(map, &i, m, w);
	map->i = i;
}
