/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:56:33 by crenly-b          #+#    #+#             */
/*   Updated: 2020/02/12 17:03:15 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

static void	ft_x_or_o(t_map *m, char **l, int j)
{
	int i;

	i = 3;
	while (++i < m->width + 4)
	{
		if ((*l)[i] == 'X')
			ft_draw_sq_x(m, i - 4, j, 0x9966CC);
		else if ((*l)[i] == 'x')
			ft_draw_sq_x(m, i - 4, j, 0x943391);
		else if ((*l)[i] == 'O')
			ft_draw_sq_o(m, i - 4, j, 0x007D34);
		else if ((*l)[i] == 'o')
			ft_draw_sq_o(m, i - 4, j, 0x7FFF00);
	}
	ft_strdel(l);
}

static int	gnl_ch1(int *param, int fd, char **line)
{
	if (fd <= 0)
		return (0);
	if (((*param = get_next_line(fd, &(*line))) > 0)
		&& ft_strstr(*line, "== ") == NULL)
		return (1);
	return (0);
}

static int	gnl_ch2(int *param, int fd, char **line)
{
	if (((*param = get_next_line(fd, &(*line))) > 0)
		&& ft_strstr(*line, "Piece") == NULL)
		return (1);
	return (0);
}

int			ft_catch_num(char **l)
{
	char	str[10];
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_bzero(str, 10);
	while (((*l)[i] < '1' || (*l)[i] > '9') && ((*l)[i]) != '\0')
		i++;
	while (((*l)[i] >= '0' && (*l)[i] <= '9') && ((*l)[i]) != '\0')
		str[j++] = (*l)[i++];
	str[j] = '\0';
	return (ft_atoi(str));
}

void		ft_read_map_and_print(t_map *m, char **l)
{
	int param;
	int	j;

	param = 0;
	while (gnl_ch1(&param, m->fd, l) == 1)
	{
		j = -1;
		if (ft_strstr(*l, "    0123456789") != NULL)
		{
			ft_strdel(l);
			while (gnl_ch2(&param, m->fd, l) == 1)
				ft_x_or_o(m, l, ++j);
			ft_strdel(l);
			if (m->step_flag == 1)
			{
				mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->img, 0, 0);
				break ;
			}
			else if (m->space_flag == 0)
				break ;
		}
		ft_strdel(l);
	}
	readprint_sup(m, l, param);
}
