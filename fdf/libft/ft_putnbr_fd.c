/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:18:24 by pcordeir          #+#    #+#             */
/*   Updated: 2021/10/12 20:24:27 by pcordeir         ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char		*ft_itoa(int n);
size_t		ft_strlen(const char *s);

void	ft_putnbr_fd(int n, int fd)
{
	char	*res;

	res = ft_itoa(n);
	write(fd, res, ft_strlen(res));
}
