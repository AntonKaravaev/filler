/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:35:46 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/22 00:18:40 by crenly-b         ###   ########.fr       */
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
	size_t	length;
	int		hight;
	int		width;
	int		enemy;
	int		num;
	int		i;
	int		j;
	enum {
			player1,
			player2
	}		i_am : 1;
}				t_map;

typedef struct	s_p
{
	char	**map;
	int		hight;
	int		width;
	int		connection;
	int		temp_i;
	int		temp_j;
	int		tempsum;
	int		best_i;
	int		best_j;
	int		bestsum;
}				t_p;


void	ft_parsing(char *line, t_map *map, t_p *p);
void	ft_createpiece(char *line, t_p *p);
void	ft_heatmap(t_map *map);
int		*ft_str4cpy(int *dst, char *src, int who);
void	ft_printmap(t_map *map); // delete after finishing project

void	ft_findposition(t_map *map, t_p *p);
void	ft_str2del(char ***str);
void	ft_intstr2del(t_map *map, int ***str);
int		ft_strlen_num(int num);

#endif
