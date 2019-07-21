/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:33:09 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/22 00:42:47 by crenly-b         ###   ########.fr       */
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
	fd = open("file.txt", O_RDWR);
	ft_parsing(line, &map, &p);
	close(fd);
	return (0);
}
