/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writept1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:25:01 by pcordeir          #+#    #+#             */
/*   Updated: 2021/11/03 10:25:06 by pcordeir         ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	rn_putchar(char c)
{
	return (write(1, &c, 1));
}

int	rn_string(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
		i++;
	return (write(1, s, i));
}

int	rn_int(int nbr)
{
	int		i;

	i = 0;
	if (nbr < -9 || nbr > 9)
		i += rn_int(nbr / 10);
	else if (nbr < 0)
		i += rn_putchar('-');
	if (nbr < 0)
		i += rn_putchar((nbr % 10 * -1) + '0');
	else if (nbr >= 0)
		i += rn_putchar(nbr % 10 + '0');
	return (i);
}

int	rn_usgn(unsigned int nbr)
{
	int		i;

	i = 0;
	if (nbr > 9)
		i += rn_usgn(nbr / 10);
	i += rn_putchar(nbr % 10 + '0');
	return (i);
}
