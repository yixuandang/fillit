/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 23:07:40 by ydang             #+#    #+#             */
/*   Updated: 2016/10/28 23:07:42 by ydang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_resetdot(char **tab, t_block *block, int max)
{
	int		x;
	int		y;

	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (tab[y][x] == block->c)
				tab[y][x] = '.';
			x++;
		}
		y++;
	}
	return (tab);
}

/*
**Resetdot is to reset the spot from
**characters to dot again for backtracking solve
*/

static char		**ft_tmpsave(char **tab, t_block *block, int max)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (block->x[i] == x && block->y[i] == y)
			{
				tab[y][x] = block->c;
				i++;
			}
			x++;
		}
		y++;
	}
	tab[y] = NULL;
	return (tab);
}

/*
**Tmpsave temporarily save the tab and
**turn the '#' to character 'A' ~'Z'
*/

static int		ft_check(char **tab, t_block *block, int max)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (block->x[i] == x && block->y[i] == y && tab[y][x] != '.')
				return (0);
			else if (block->x[i] == x && block->y[i] == y)
				i++;
			x++;
		}
		y++;
	}
	if (i < 4)
		return (0);
	return (1);
}

/*
**Core checking algorithm(T-T)
*/

static char		**ft_solu(char **tab, t_block *block, int max)
{
	int		x;
	int		y;
	char	**tmp;

	if (!block->next)
		return (tab);
	tmp = NULL;
	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			block = ft_updatexy(block, x, y);
			if (ft_check(tab, block, max))
				tmp = ft_solu(ft_tmpsave(tab, block, max), block->next, max);
			if (tmp)
				return (tmp);
			tab = ft_resetdot(tab, block, max);
			++x;
		}
		++y;
	}
	return (NULL);
}

/*
**Recursion and backtracking method to solve the puzzle zzzzzzz
*/

char			**ft_result(t_block *block, int max)
{
	char	**tab;

	tab = NULL;
	while (!tab)
	{
		tab = ft_filldots(tab, max);
		tab = ft_solu(tab, block, max);
		max++;
	}
	return (tab);
}

/*
**The function calls ft_solu function
*/
