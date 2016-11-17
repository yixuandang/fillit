/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 00:37:27 by ydang             #+#    #+#             */
/*   Updated: 2016/10/29 00:37:28 by ydang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_block		*block;
	char		*reading;
	char		**result;

	if (argc != 2)
		ft_printerror();
	reading = ft_read(argv[1]);
	block = ft_storage(reading);
	block = ft_defaultxy(block);
	result = ft_result(block, ft_mapsize(block));
	free(block);
	while (*result)
		ft_putendl(*result++);
	return (0);
}
