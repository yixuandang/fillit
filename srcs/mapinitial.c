/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinitial.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 00:04:31 by ydang             #+#    #+#             */
/*   Updated: 2016/10/29 00:04:33 by ydang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_filldots(char **tab, int max)
{
	int		y;
	int		x;

	y = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (max + 1))))
		return (NULL);
	while (y < max)
	{
		tab[y] = ft_strnew(max);
		x = 0;
		while (x < max)
		{
			tab[y][x] = '.';
			x++;
		}
		y++;
	}
	tab[y] = NULL;
	return (tab);
}

/*
**Map initialization with '.'
*/

int		ft_mapsize(t_block *block)
{
	int		i;
	int		max;

	i = 0;
	max = 2;
	while (block->next && i++)
		block = block->next;
	while (max * max < i * 4)
		max++;
	return (max);
}

/*
**Map size initialization / will increase with the block increasing
*/
