/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cor_to_vrm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:10:47 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/23 22:30:41 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_strlen_num(int num)
{
	int length;

	length = 1;
	if (num > 9)
	{
		while (num > 9)
		{
			num = num / 10;
			length = length * 10;
		}
	}
	return (length);
}

static void		ft_supwrite(t_p *p, char *str, int i)
{
	int del;

	del = ft_strlen_num(p->best_i);
	while (del > 0)
	{
		str[i++] = (p->best_i / del) + '0';
		p->best_i = p->best_i % del;
		del = del / 10;
	}
	str[i++] = ' ';
	del = ft_strlen_num(p->best_j);
	while (del > 0)
	{
		str[i++] = (p->best_j / del) + '0';
		p->best_j = p->best_j % del;
		del = del / 10;
	}
	str[i++] = '\n';
	str[i] = '\0';
}

void			ft_get_cor_to_vrm(t_p *p)
{
	char	str[10];

	if (p->best_i != -1 && p->best_i != -1)
	{
		ft_supwrite(p, str, 0);
		write(1, str, ft_strlen(str));
	}
	else
		write(1, "-1 -1\n", 6);
}
