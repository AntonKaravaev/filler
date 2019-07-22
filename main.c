/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:33:09 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/23 02:03:11 by crenly-b         ###   ########.fr       */
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
		ft_working(line, &map, &p);
	return (0);
}
