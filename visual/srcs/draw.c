/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 22:55:37 by crenly-b          #+#    #+#             */
/*   Updated: 2020/02/12 15:22:04 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

static void		put_pixel_menu(t_map *map, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < WOI && y >= 0 && y < HOI)
	{
		i = (x * map->bpp / 8) + (y * map->sl);
		map->img_data[i] = color;
		map->img_data[++i] = color >> 8;
		map->img_data[++i] = color >> 16;
		map->img_data[++i] = 0;
	}
}

void			draw_line(t_map *map, t_point s, t_point f, int c)
{
	t_point i_am;
	t_draw	draw;

	draw.dx = abs(f.x - s.x);
	draw.dy = abs(f.y - s.y);
	draw.sign_dx = s.x < f.x ? 1 : -1;
	draw.sign_dy = s.y < f.y ? 1 : -1;
	draw.err[0] = draw.dx - draw.dy;
	i_am = s;
	put_pixel_menu(map, i_am.x, i_am.y, c);
	while (i_am.x != f.x || i_am.y != f.y)
	{
		put_pixel_menu(map, i_am.x, i_am.y, c);
		if ((draw.err[1] = 2 * draw.err[0]) > -draw.dy)
		{
			draw.err[0] = draw.err[0] - draw.dy;
			i_am.x = i_am.x + draw.sign_dx;
		}
		if (draw.err[1] < draw.dx)
		{
			draw.err[0] = draw.err[0] + draw.dx;
			i_am.y = i_am.y + draw.sign_dy;
		}
	}
	put_pixel_menu(map, i_am.x, i_am.y, c);
}
