/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:09:00 by crenly-b          #+#    #+#             */
/*   Updated: 2020/02/12 15:45:00 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

void	ft_usage(void)
{
	ft_putstr("____________________________________________\n");
	ft_putstr("|                                          |\n");
	ft_putstr("|     Usage: ./filler_visual <name.txt>    |\n");
	ft_putstr("|__________________________________________|\n\n");
}

void	ft_error(char *str)
{
	ft_putstr(str);
	exit(-1);
}

int		ft_is_it_file(char *str)
{
	int len;

	len = (int)ft_strlen(str);
	if (len > 4 && (ft_strnstr(str, ".", len - 4) == NULL
		|| ft_strnstr(str, "../", 4) != NULL))
	{
		str += len - 4;
		return (ft_strequ(str, ".txt") == 1);
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	t_map	map;

	if (argc == 2 && ft_is_it_file(argv[1]))
	{
		if ((map.fd = open(argv[1], O_RDWR)) > 2)
			ft_solution(&map);
		else
			ft_error("It's not a correct fd!\n");
	}
	else
		ft_usage();
	return (0);
}
