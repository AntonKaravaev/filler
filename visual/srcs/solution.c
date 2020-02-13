/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:59:53 by crenly-b          #+#    #+#             */
/*   Updated: 2020/02/12 17:13:08 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

static char	*ft_player_sup(char *line)
{
	char *str;

	str = line;
	str += 15;
	while (ft_strchr(str, '/') != NULL)
		str = ft_strchr(str, '/') + 1;
	return (str);
}

void		ft_catch_players(char **line, int fd, char n1[100], char n2[100])
{
	int		i;

	n1[0] = '\0';
	n2[0] = '\0';
	i = -1;
	while (++i < 7)
		ft_catch_players_sup(line, fd, i, 6);
	if (ft_strstr(*line, "$$$ exec p1 : [") != NULL)
	{
		ft_strcat(n1, ft_player_sup(*line));
		n1[ft_strlen(n1) - 1] = '\0';
	}
	ft_strdel(line);
	while (++i < 10)
		ft_catch_players_sup(line, fd, i, 9);
	if (ft_strstr(*line, "$$$ exec p2 : [") != NULL)
	{
		ft_strcat(n2, ft_player_sup(*line));
		n2[ft_strlen(n2) - 1] = '\0';
	}
	ft_strdel(line);
}

void		ft_hight_width(char **l, int fd, int *hight, int *width)
{
	char	str[10];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (get_next_line(fd, &(*l)) <= 0)
		ft_error("Some problems with gnl\n");
	while (((*l)[i] < '1' || (*l)[i] > '9') && ((*l)[i]) != '\0')
		i++;
	while (((*l)[i] >= '0' && (*l)[i] <= '9') && ((*l)[i]) != '\0')
		str[j++] = (*l)[i++];
	str[j] = '\0';
	*hight = ft_atoi(str);
	j = 0;
	while (((*l)[i] < '1' || (*l)[i] > '9') && ((*l)[i]) != '\0')
		i++;
	while (((*l)[i] >= '0' && (*l)[i] <= '9') && ((*l)[i]) != '\0')
		str[j++] = (*l)[i++];
	str[j] = '\0';
	*width = ft_atoi(str);
	ft_strdel(l);
}

int			key_hook(int k, t_map *map)
{
	if (k == KVK_ESCAPE)
		exit(0);
	else if (k == SPACE && map->space_flag != 2)
	{
		map->space_flag = 1;
		ft_read_map_and_print(map, &map->line);
	}
	else if (k == AR_RIGHT && map->step_flag != 2)
	{
		map->step_flag = 1;
		ft_read_map_and_print(map, &map->line);
		map->step_flag = 0;
	}
	return (0);
}

void		ft_solution(t_map *m)
{
	m->line = NULL;
	ft_catch_players(&m->line, m->fd, m->name1, m->name2);
	ft_hight_width(&m->line, m->fd, &m->hight, &m->width);
	ft_init_map(m);
	ft_init_and_print_board(m);
	print_menu(m);
	ft_print_lines(m);
	ft_read_map_and_print(m, &m->line);
	mlx_hook(m->win_ptr, 2, 0, key_hook, m);
	mlx_hook(m->win_ptr, 17, 0, closee, m);
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->img, 0, 0);
	mlx_loop(m->mlx_ptr);
}
