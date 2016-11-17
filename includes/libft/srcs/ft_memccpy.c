/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 15:40:48 by ydang             #+#    #+#             */
/*   Updated: 2016/09/23 15:40:50 by ydang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	while (len)
	{
		*((char*)dst) = *((char*)src);
		dst = (void*)((char*)dst + 1);
		src = (void*)((char*)src + 1);
		if ((char)(c) == *((char*)dst - 1))
		{
			return (dst);
		}
		len--;
	}
	return (NULL);
}
