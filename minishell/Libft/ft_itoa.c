/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:53:19 by mokatova          #+#    #+#             */
/*   Updated: 2021/12/02 17:19:00 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*string;
	size_t	count;
	long	number;

	number = n;
	count = ft_count_digits(n);
	string = (char *)malloc(sizeof(*string) * (count + 1));
	if (!string)
		return (0);
	if (number == 0)
		string[0] = '0';
	if (number < 0)
	{
		string[0] = '-';
		number *= -1;
	}
	string[count--] = '\0';
	while (number != 0)
	{
		string[count] = (number % 10) + '0';
		number /= 10;
		count--;
	}
	return (string);
}
