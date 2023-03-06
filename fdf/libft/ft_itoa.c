/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:41:29 by pcordeir          #+#    #+#             */
/*   Updated: 2021/10/12 16:49:09 by pcordeir         ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int	ft_ilen(int n);
static char	*ft_put(char *ret, int n, int count, int sign);

char	*ft_itoa(int n)
{
	int		count;
	int		sign;
	char	*ret;

	count = 0;
	sign = 1;
	if (n < 0)
		sign = -1;
	count += ft_ilen(n);
	ret = (char *)malloc(count + 1);
	if (ret)
		return (ft_put(ret, n, count, sign));
	else
		return (NULL);
}

static int	ft_ilen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_put(char *ret, int n, int count, int sign)
{
	ret[count--] = '\0';
	while (count >= 0)
	{
		ret[count--] = sign * (n % 10) + 48;
		n /= 10;
	}
	if (sign == -1)
		ret[0] = '-';
	return (ret);
}
