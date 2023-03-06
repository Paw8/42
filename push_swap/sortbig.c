/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:26:59 by pcordeir          #+#    #+#             */
/*   Updated: 2022/02/15 12:50:19 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortbig(t_stack **a, t_stack **b, int size)
{
	int	i;
	int	step;

	i = 0;
	while (!issorted(*a))
	{
		i++;
		step = 0;
		while (step < size)
		{
			if (ft_strlen((*a)->bivalue) < i || *(((*a)->bivalue) + \
			ft_strlen((*a)->bivalue) - i) == '0')
				push(a, b, 'b');
			else
				rotate(a, 'a');
			step++;
		}
		while (*b)
			push(b, a, 'a');
	}
}
