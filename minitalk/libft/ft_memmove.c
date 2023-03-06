/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:58:18 by pcordeir          #+#    #+#             */
/*   Updated: 2022/04/20 11:24:39 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*set;
	const char	*cpy;

	set = dest;
	cpy = src;
	if (set > cpy)
	{
		set += n;
		cpy += n;
		while (n--)
			*--set = *--cpy;
		return (dest);
	}
	else
		return (ft_memcpy(dest, src, n));
}
