/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:18:59 by pcordeir          #+#    #+#             */
/*   Updated: 2022/02/14 13:55:41 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort3(t_stack **a)
{
	while (!issorted(*a))
	{
		if ((*a)->svalue - (*a)->next->svalue == 1 || \
			(*a)->svalue - (*a)->next->svalue == -2)
			swap(a, 'a');
		else if ((*a)->svalue - (*a)->next->svalue == 2)
			rotate(a, 'a');
		else if ((*a)->svalue - (*a)->next->svalue == -1)
			rrotate(a, 'a');
	}
}

void	sort4(t_stack **a, t_stack **b)
{
	while (!issorted(*a))
	{
		if (((*a)->svalue - (*a)->next->svalue == -1 && (*a)->next->svalue - \
		(*a)->next->next->svalue == -2) || ((*a)->svalue - (*a)->next->svalue \
		== -3 && (*a)->next->svalue - (*a)->next->next->svalue == 1))
		{
			push(a, b, 'b');
			sort3(a);
			push(b, a, 'a');
		}
		else
			action(a);
	}
}

void	sortsmall(t_stack **src, t_stack **b, int size)
{
	int		i;

	while (size > 4)
	{
		i = findsmallest(*src);
		if (i <= (size / 2))
		{
			while (i--)
				rotate(src, 'a');
		}
		else if (i > (size / 2))
		{
			while (size - i++)
				rrotate(src, 'a');
		}
		push(src, b, 'b');
		size--;
	}
	sort4(src, b);
	while (*b)
		push(b, src, 'a');
}

int	findsmallest(t_stack *src)
{
	t_stack	*temp;
	t_stack	*set;
	int		i;
	int		j;

	i = 1;
	j = 0;
	temp = src;
	set = src;
	while (temp->next != 0)
	{
		if (set->svalue > temp->next->svalue)
		{
			set = temp->next;
			j = i;
		}
		temp = temp->next;
		i++;
	}
	return (j);
}

void	action(t_stack **a)
{
	if ((*a)->svalue - (*a)->next->svalue == 1 || ((*a)->svalue - (*a) \
	->next->svalue == -3 && (*a)->next->svalue - (*a)->next->next->svalue \
	== 2) || ((*a)->svalue - (*a)->next->svalue == 2 && (*a)->next->svalue \
	- (*a)-> next->next->svalue == -3) || ((*a)->svalue - (*a)->next-> \
	svalue == -2 && (*a)->next->svalue - (*a)->next->next->svalue == 3))
		swap(a, 'a');
	else if (((*a)->svalue - (*a)->next-> svalue == 3 && (*a)->next->svalue \
	< (*a)->next->next->svalue) || ((*a)->svalue - (*a)->next->svalue == -1 \
	&& (*a)->next->svalue - (*a)->next->next->svalue != -1) || ((*a)-> \
	svalue - (*a)->next-> svalue == 2 && (*a)->next->svalue - (*a)->next-> \
	next->svalue == 1) || ((*a)->svalue - (*a)->next->svalue == -2 && (*a) \
	->next->svalue - (*a)->next->next->svalue == 1))
		rotate(a, 'a');
	else if (((*a)->svalue - (*a)->next->svalue == -1 && (*a)->next->svalue \
	- (*a)->next->next->svalue == -1) || ((*a)->svalue - (*a)->next->svalue \
	== 2 && (*a)->next->svalue - (*a)->next->next->svalue == -1) || ((*a)-> \
	svalue - (*a)->next->svalue == -2 && (*a)->next->svalue < (*a)->next-> \
	next->svalue))
		rrotate(a, 'a');
}
