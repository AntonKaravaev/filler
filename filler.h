/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:35:46 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/20 22:38:17 by crenly-b         ###   ########.fr       */
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

typedef struct	s_piece
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

void	ft_mapcreate(char *line, t_map *map);
void	ft_catchpiece(char *line, t_p *p);
char	*ft_fromnbrtos(int n, t_map *map);
void	ft_findposition(t_map *map, t_p *p);

#endif
