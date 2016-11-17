/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 00:29:33 by ydang             #+#    #+#             */
/*   Updated: 2016/10/29 00:29:35 by ydang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

/*
**Regular error notification
*/

void	ft_printerror(void)
{
	ft_putstr("usage: ./fillit sample.fillit | cat -e\n");
	ft_putstr("       ./excecutablefile samplefile | cat -e\n");
	ft_putstr("       attention: only 1 input file is legal\n");
	exit(0);
}

/*
**Arguement num error notification
*/
