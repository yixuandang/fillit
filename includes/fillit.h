/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 22:53:37 by ydang             #+#    #+#             */
/*   Updated: 2016/10/28 22:53:39 by ydang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/includes/libft.h"

typedef struct		s_block
{
	char				c;
	char				*str;
	int					x[4];
	int					y[4];
	struct s_block		*next;
}					t_block;

void				ft_recheck(char *s);
int					ft_basiccheck(char *s);
char				**ft_result(t_block *block, int max);
t_block				*ft_updatexy(t_block *block, int x, int y);
t_block				*ft_defaultxy(t_block *block);
char				**ft_filldots(char **tab, int max);
int					ft_mapsize(t_block *block);
t_block				*ft_storage(char *str);
char				*ft_read(char *file);
void				ft_error(void);
void				ft_printerror(void);
#endif
