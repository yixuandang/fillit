/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 21:44:35 by ydang             #+#    #+#             */
/*   Updated: 2016/10/28 21:44:37 by ydang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*ft_deepcheck(int i, char *s)
{
	if (s[i + 1] == '#')
	{
		s[i + 1] = 'x';
		s = ft_deepcheck(i + 1, s);
	}
	if (s[i - 1] >= 0 && s[i - 1] == '#')
	{
		s[i - 1] = 'x';
		s = ft_deepcheck(i - 1, s);
	}
	if (i + 5 <= 20 && s[i + 5] == '#')
	{
		s[i + 5] = 'x';
		s = ft_deepcheck(i + 5, s);
	}
	if (i - 5 >= 0 && s[i - 5] == '#')
	{
		s[i - 5] = 'x';
		s = ft_deepcheck(i - 5, s);
	}
	if (s[i] == '#')
		s[i] = 'x';
	return (s);
}

/*
**Go through recursively to check each '#'
**and replace them to 'x' for extra check
*/

static int		ft_countx(char *s)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (*s == 'x')
			count++;
		s++;
	}
	return (count);
}

static int		ft_countdot(char *s)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (*s == '.')
			count++;
		s++;
	}
	return (count);
}

/*
**After ft_deepcheck, count the number of 'x' for extra check
*/

void			ft_recheck(char *s)
{
	int		i;

	i = 0;
	if (ft_countdot(s) != 12)
		ft_error();
	while (s[i] && s[i] != '#')
		i++;
	s[i] = 'x';
	s = ft_deepcheck(i, s);
	if (ft_countx(s) != 4)
		ft_error();
	while (*s)
	{
		if (*s == 'x')
			*s = '#';
		s++;
	}
}

/*
**The recheck is replacing all of the 'x' to '#'(change back the '#')
*/

int				ft_basiccheck(char *s)
{
	int		dot;
	int		pound;
	int		endl;

	dot = 0;
	pound = 0;
	endl = 0;
	while (*s)
	{
		if (*s == '.')
			dot++;
		else if (*s == '#')
			pound++;
		else if (*s == '\n')
			endl++;
		else
			ft_error();
		s++;
	}
	if (pound < 4)
		ft_error();
	if (dot % 4 || pound % 4 || (endl + 1) % 5)
		ft_error();
	return (pound / 4);
}

/*
**The basic check will check the whole file through reading
*/
