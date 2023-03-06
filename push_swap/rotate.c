/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:39:16 by pcordeir          #+#    #+#             */
/*   Updated: 2022/02/03 11:40:11 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **src, char c)
{
	t_stack	*temp;

	if (*src && (*src)->next != 0)
	{
		temp = *src;
		while (temp->next != 0)
			temp = temp->next;
		temp->next = *src;
		temp = *src;
		*src = (*src)->next;
		temp->next = 0;
		if (c == 'a')
			write(1, "ra\n", 3);
		else if (c == 'b')
			write(1, "rb\n", 3);
	}
}

void	rrotate(t_stack **src, char c)
{
	t_stack	*root;
	t_stack	*temp;

	if (*src && (*src)->next != 0)
	{
		root = *src;
		while ((*src)->next != 0)
		{
			temp = *src;
			*src = (*src)->next;
		}
		(*src)->next = root;
		temp->next = 0;
		if (c == 'a')
			write(1, "rra\n", 4);
		else if (c == 'b')
			write(1, "rrb\n", 4);
	}
}

void	rotateboth(t_stack **a, t_stack **b)
{
	rotate(a, 'a');
	rotate(b, 'b');
}

void	rrotateboth(t_stack **a, t_stack **b)
{
	rrotate(a, 'a');
	rrotate(b, 'b');
}
