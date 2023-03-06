/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:11:24 by mokatova          #+#    #+#             */
/*   Updated: 2021/11/18 22:39:15 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int number)
{
	if ((number >= 'A' && number <= 'Z') || (number >= 'a' && number <= 'z'))
	{
		return (1024);
	}
	return (0);
}
