/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:48:04 by mokatova          #+#    #+#             */
/*   Updated: 2021/11/18 23:04:36 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int number)
{
	if ((number >= 'A' && number <= 'Z') || (number >= 'a' && number <= 'z')
		|| (number >= '0' && number <= '9'))
		return (8);
	return (0);
}
