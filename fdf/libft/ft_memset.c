/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:40:15 by pcordeir          #+#    #+#             */
/*   Updated: 2021/10/02 13:42:30 by pcordeir         ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*set;

	set = s;
	while (n--)
		*set++ = c;
	return (s);
}
