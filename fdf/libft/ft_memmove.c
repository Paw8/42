/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:58:18 by pcordeir          #+#    #+#             */
/*   Updated: 2021/10/04 14:07:07 by pcordeir         ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);

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
