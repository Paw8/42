/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:54:53 by pcordeir          #+#    #+#             */
/*   Updated: 2022/02/15 11:01:16 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *dest, char *src)
{
	char	*ret;
	int		i;

	i = 0;
	if (dest)
	{
		ret = malloc(ft_strlen(dest) + 2);
		while (dest[i])
		{
			ret[i] = dest[i];
			i++;
		}
		ret[i++] = *src;
		ret[i] = '\0';
		free(src);
	}
	else
		ret = src;
	free(dest);
	return (ret);
}

long	ft_atoi(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str > 47 && *str < 58)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}

char	*ft_itobi(int nbr)
{
	char	*ret;
	char	*temp;

	if (nbr >= 0)
	{	
		ret = 0;
		temp = malloc(sizeof(char) + 1);
		if (nbr > 1)
			ret = ft_itobi(nbr / 2);
		*temp = nbr % 2 + '0';
		*(temp + 1) = '\0';
		ret = ft_strjoin(ret, temp);
		return (ret);
	}
	else
		return (NULL);
}
