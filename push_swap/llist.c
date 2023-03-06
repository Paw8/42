/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:44:51 by pcordeir          #+#    #+#             */
/*   Updated: 2022/02/15 10:04:17 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	addnode(int nbr, t_stack *root)
{
	t_stack	*new;

	while (root->next != 0)
		root = root->next;
	new = malloc(sizeof(t_stack));
	new->value = nbr;
	new->svalue = 0;
	new->next = 0;
	root->next = new;
}

t_stack	*newnode(int nbr)
{
	t_stack	*temp;

	temp = malloc(sizeof(t_stack));
	temp->value = nbr;
	temp->svalue = 0;
	temp->next = 0;
	return (temp);
}

void	freestack(t_stack *root)
{
	t_stack	*del;
	t_stack	*temp;

	if (!root || root->next == 0)
		free(root);
	else
	{
		while (root->next != 0)
		{
			del = root;
			while (del->next != 0)
			{
				temp = del;
				del = del->next;
			}
			free(del->bivalue);
			free(del);
			temp->next = 0;
		}
		free(temp->bivalue);
		free(temp);
	}
}

int	issorted(t_stack *src)
{
	while (src->next != 0)
	{
		if (src->value > src->next->value)
			return (0);
		src = src->next;
	}
	return (1);
}

void	setsvalue(t_stack *src, int size)
{
	t_stack	*temp;
	t_stack	*set;

	if (src->svalue != 0)
	{
		temp = src;
		while (temp->next != 0)
			temp->svalue = 0;
		temp->svalue = 0;
	}
	while (size)
	{
		set = src;
		while (set->svalue >= size)
			set = set->next;
		temp = set;
		while (temp->next != 0)
		{
			if (set->value < temp->next->value && temp->next->svalue == 0)
				set = temp->next;
			temp = temp->next;
		}
		set->svalue = size--;
	}
}
