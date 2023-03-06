/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:56:45 by pcordeir          #+#    #+#             */
/*   Updated: 2022/02/16 13:57:16 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		*arr;
	t_stack	*a_head;

	if (argc > 1)
	{
		arr = malloc(sizeof(int) * (argc - 1));
		checkall(argc, argv, &arr);
		i = 0;
		a_head = newnode(arr[i++]);
		while (i < argc - 1)
			addnode(arr[i++], a_head);
		free(arr);
		if (issorted(a_head))
		{
			freestack(a_head);
			exit(0);
		}
		setsvalue(a_head, argc - 1);
		setbivalue(a_head);
		push_swap(&a_head, argc - 1);
	}
	return (0);
}

void	setbivalue(t_stack *a)
{
	while (a->next != 0)
	{
		a->bivalue = ft_itobi(a->svalue);
		a = a->next;
	}
	a->bivalue = ft_itobi(a->svalue);
}

void	error(int *arr)
{
	free(arr);
	write(2, "Error\n", 6);
	exit(0);
}
