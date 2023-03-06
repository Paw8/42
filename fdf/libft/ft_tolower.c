/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:44:31 by pcordeir          #+#    #+#             */
/*   Updated: 2021/10/01 16:46:11 by pcordeir         ###   ########.de       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (64 < c && c < 91)
		c = c + 32;
	return (c);
}
