/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xycorrdinate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 23:39:41 by ydang             #+#    #+#             */
/*   Updated: 2016/10/28 23:39:43 by ydang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_block			*ft_updatexy(t_block *block, int x, int y)
{
	int		xmin;
	int		ymin;
	int		i;

	xmin = 200;
	ymin = 200;
	i = 0;
	while (i != 4)
	{
		if (block->x[i] < xmin)
			xmin = block->x[i];
		if (block->y[i] < ymin)
			ymin = block->y[i];
		i++;
	}
	i = 0;
	while (i != 4)
	{
		block->x[i] = block->x[i] - xmin + x;
		block->y[i] = block->y[i] - ymin + y;
		i++;
	}
	return (block);
}

/*
**Whenever we had a input, during the solution process,
**it will loop a lot of times to update xy's cor
*/

static t_block	*ft_blockxy(t_block *block, char **s)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (s[y])
	{
		x = 0;
		while (s[y][x])
		{
			if (s[y][x] == '#')
			{
				block->x[i] = x;
				block->y[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
	return (block);
}

/*
**Record the x,y corrdinates of every '#'
*/

t_block			*ft_defaultxy(t_block *block)
{
	t_block *tmp;

	tmp = block;
	while (block->next)
	{
		block = ft_blockxy(block, ft_strsplit(block->str, '\n'));
		free(block->str);
		block = block->next;
	}
	return (tmp);
}

/*
**Strsplit the blockstr into 4 row_str
*/
