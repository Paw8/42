/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:27:10 by pcordeir          #+#    #+#             */
/*   Updated: 2021/05/18 17:27:24 by pcordeir         ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char		*ft_itoa(int n);
size_t		ft_strlen(const char *s);

void	ft_putnbr(int n)
{
	char	*res;

	res = ft_itoa(n);
	write(1, res, ft_strlen(res));
}
