/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:33:09 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/23 22:27:31 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_map	map;
	t_p		p;
	char	*line;
	int		fd;

	line = NULL;
	p.map = NULL;
	map.onetime = 0;
	fd = open("file.txt", O_RDWR);
	while (1)
	{
		ft_createmap(line, &map);
		ft_createpiece(line, &p);
		ft_heatmap(&map);
		ft_findposition(&map, &p);
		ft_str2del(&p.map);
		ft_get_cor_to_vrm(&p);
	}
	close(fd);
	return (0);
}
