/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:54:53 by pcordeir          #+#    #+#             */
/*   Updated: 2022/01/25 11:00:11 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **dest, char c)
{
	t_stack	*temp;

	if (*dest && (*dest)->next != 0)
	{
		temp = *dest;
		*dest = temp->next;
		temp->next = (*dest)->next;
		(*dest)->next = temp;
		if (c == 'a')
			write(1, "sa\n", 3);
		else if (c == 'b')
			write(1, "sb\n", 3);
	}
}

void	sswap(t_stack **a, t_stack **b)
{
	char	c;

	c = 's';
	if (*a && (*a)->next != 0 && *b && (*b)->next != 0)
	{
		write(1, "ss\n", 3);
		swap(a, c);
		swap(b, c);
	}
	else if (*a && (*a)->next != 0)
	{
		c = 'a';
		swap(a, c);
	}
	else if (*b && (*b)->next != 0)
	{
		c = 'b';
		swap(b, c);
	}
}

void	push(t_stack **src, t_stack **dest, char c)
{
	t_stack	*temp;

	if (*src)
	{
		temp = (*src)->next;
		if (!(*dest))
		{
			*dest = *src;
			(*dest)->next = 0;
		}
		else
		{
			(*src)->next = *dest;
			*dest = *src;
		}
		*src = temp;
		if (c == 'a')
			write(1, "pa\n", 3);
		else if (c == 'b')
			write(1, "pb\n", 3);
	}
}
