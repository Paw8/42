/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:15:52 by pcordeir          #+#    #+#             */
/*   Updated: 2021/10/04 12:19:00 by pcordeir         ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*set;
	const unsigned char	*cpy;

	set = dest;
	cpy = src;
	while (n--)
		*set++ = *cpy++;
	return (dest);
}
