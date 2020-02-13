/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:54:41 by crenly-b          #+#    #+#             */
/*   Updated: 2020/02/12 15:21:23 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

void	ft_init_map(t_map *m)
{
	m->mlx_ptr = NULL;
	m->win_ptr = NULL;
	m->img = NULL;
	m->img_data = NULL;
	m->mlx_ptr = mlx_init();
	if (!(m->win_ptr =
		mlx_new_window(m->mlx_ptr, WOW, HOW, "anton's fractol")))
		ft_error("Problems with mlx_new_window!\n");
	if (!(m->img = (mlx_new_image(m->mlx_ptr, WOI, HOI))))
		ft_error("Problems with mlx_new_image!\n");
	m->img_data = (mlx_get_data_addr(m->img,
		&m->bpp, &m->sl, &m->endian));
	m->p1_res = 0;
	m->p2_res = 0;
	m->step_flag = 0;
	m->space_flag = 0;
}
