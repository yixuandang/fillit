/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readnsave.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 00:17:19 by ydang             #+#    #+#             */
/*   Updated: 2016/10/29 00:17:21 by ydang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_block	*ft_storage(char *str)
{
	int		i;
	int		j;
	char	c;
	t_block *block;
	t_block *tmp;

	j = 0;
	c = 64;
	i = ft_basiccheck(str);
	if (!(block = (t_block*)malloc(sizeof(t_block))))
		return (NULL);
	tmp = block;
	while (i-- > 0)
	{
		tmp->str = ft_strndup(&str[j], 20);
		ft_recheck(tmp->str);
		tmp->c = ++c;
		j += 21;
		if (!(tmp->next = (t_block*)malloc(sizeof(t_block))))
			return (NULL);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (block);
}

/*
**Save the str read from the file to different blocks
*/

char	*ft_read(char *file)
{
	int		fd;
	int		read_stat;
	int		i;
	char	tmp[545];
	char	buffer[1];

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error();
	while ((read_stat = read(fd, buffer, 1)))
	{
		tmp[i++] = buffer[0];
		if (i > 545)
			ft_error();
	}
	tmp[i] = '\0';
	if (close(fd) == -1)
		ft_error();
	return (ft_strdup(tmp));
}

/*
**Read file from standard read
**O_RDONLY means read only also with some input error check
*/
