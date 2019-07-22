/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:35:46 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/23 01:35:48 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_map
{
	int		**map;
	char	str[5];
	int		hight;
	int		width;
	int		enemy;
	int		onetime;
	int		num;
	int		i;
	int		j;
	int		i_am : 1;
}				t_map;

typedef struct	s_p
{
	char	**map;
	int		hight;
	int		width;
	int		connection;
	int		tempsum;
	int 	max_i;
	int		max_j;
	int		best_i;
	int		best_j;
	int		help_i;
	int		help_j;
	int		mayak;
	int		bestsum;
}				t_p;


void	ft_working(char *line, t_map *map, t_p *p);
void	ft_createpiece(char *line, t_p *p);
void	ft_heatmap(t_map *map);
int		*ft_str4cpy(int *dst, char *src, int who);
void	ft_printmap(t_map *map); // delete after finishing project

void	ft_findposition(t_map *map, t_p *p);
void	ft_str2del(char ***str);
void	ft_intstr2del(t_map *map, int ***str);
int		ft_strlen_num(int num);

#endif
