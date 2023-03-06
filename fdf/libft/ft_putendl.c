/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:08:20 by pcordeir          #+#    #+#             */
/*   Updated: 2021/12/15 10:58:42 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *s);

void	ft_putendl(char *s)
{
	if (!s)
		write(1, "(null)", 6);
	else
		write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}
