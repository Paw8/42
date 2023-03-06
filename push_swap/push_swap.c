/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:23:10 by pcordeir          #+#    #+#             */
/*   Updated: 2022/02/15 12:50:57 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, int size)
{
	t_stack	*b;

	b = 0;
	if (size == 2)
		if ((*a)->svalue - (*a)->next->svalue == 1)
			swap(a, 'a');
	if (size == 3)
		sort3(a);
	else if (size == 4)
		sort4(a, &b);
	else if (size > 4 && size < 42)
		sortsmall(a, &b, size);
	else
		sortbig(a, &b, size);
	freestack(*a);
	freestack(b);
}
