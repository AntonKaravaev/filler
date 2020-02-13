/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:33:09 by crenly-b          #+#    #+#             */
/*   Updated: 2020/02/12 17:44:46 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_map	map;
	t_p		p;
	char	*line;

	line = NULL;
	p.map = NULL;
	map.onetime = 0;
	while (1)
	{
		ft_createmap(&line, &map);
		ft_createpiece(&line, &p);
		ft_heatmap(&map);
		ft_findposition(&map, &p);
		ft_str2del(&p.map);
		ft_get_cor_to_vrm(&p);
	}
	return (0);
}
