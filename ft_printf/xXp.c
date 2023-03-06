/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xXp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:25:15 by pcordeir          #+#    #+#             */
/*   Updated: 2021/11/24 12:20:43 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	rn_putchar(char c);

int	rn_hexl(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr > 15)
		i += rn_hexl(nbr / 16);
	nbr %= 16;
	if (nbr < 10)
		i += rn_putchar(nbr + '0');
	else
		i += rn_putchar(nbr + 'W');
	return (i);
}

int	rn_hexu(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr > 15)
		i += rn_hexu(nbr / 16);
	nbr %= 16;
	if (nbr < 10)
		i += rn_putchar(nbr + '0');
	else
		i += rn_putchar(nbr + '7');
	return (i);
}

int	rn_longhexl(unsigned long nbr)
{
	int	i;

	i = 0;
	if (nbr > 15)
		i += rn_longhexl(nbr / 16);
	nbr %= 16;
	if (nbr < 10)
		i += rn_putchar(nbr + '0');
	else
		i += rn_putchar(nbr + 'W');
	return (i);
}

int	rn_point(unsigned long nbr)
{
	int	i;

	i = 2;
	if (nbr == 0)
		return (write(1, "0x0", 3));
	else
		write(1, "0x", 2);
	i += rn_longhexl(nbr);
	return (i);
}
