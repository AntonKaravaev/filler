/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:35:46 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/19 18:58:18 by crenly-b         ###   ########.fr       */
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
	char	**map;
	size_t	length;
	int		hight;
	int		width;
	int		i;
	enum {
			player1,
			player2
	}		i_am;
}				t_map;

typedef struct	s_piece
{
	char	**map;
	int		hight;
	int		width;
}				t_p;

void	ft_mapcreate(char *line, t_map *map);
void	ft_catchpiece(char *line, t_p *p);

#endif
