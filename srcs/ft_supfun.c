/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supfun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 23:19:04 by crenly-b          #+#    #+#             */
/*   Updated: 2020/02/07 15:41:28 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		*ft_str4cpy(int *dst, char *src, int who)
{
	size_t i;
	size_t j;

	i = 0;
	j = 3;
	while (src[++j] != '\0')
	{
		if (src[j] == '.')
			dst[i] = 0;
		else if (who == 0)
		{
			dst[i] = (src[j] == 'X' || src[j] == 'x') ? -111 : dst[i];
			dst[i] = (src[j] == 'O' || src[j] == 'o') ? -222 : dst[i];
		}
		else
		{
			dst[i] = (src[j] == 'X' || src[j] == 'x') ? -222 : dst[i];
			dst[i] = (src[j] == 'O' || src[j] == 'o') ? -111 : dst[i];
		}
		i++;
	}
	return (dst);
}

void	ft_str2del(char ***str)
{
	int i;

	i = 0;
	if (*str != NULL)
	{
		while ((*str)[i] != NULL)
		{
			ft_strdel(&((*str)[i]));
			i++;
		}
		free(*str);
	}
}
