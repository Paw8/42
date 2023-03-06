/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:04:07 by pcordeir          #+#    #+#             */
/*   Updated: 2022/04/15 12:52:38 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_file	*newnode(t_file *head, double z)
{
	t_file	*new;
	t_file	*temp;

	new = malloc(sizeof(t_file));
	new->x = 0;
	new->y = 0;
	new->u = 0;
	new->v = 0;
	new->z = z;
	new->next = 0;
	if (head)
	{
		temp = head;
		while (temp->next != 0)
			temp = temp->next;
		temp->next = new;
		return (head);
	}
	else
		return (new);
}

void	freelist(t_file *del)
{
	t_file	*temp;

	while (del->next)
	{
		temp = del;
		del = del->next;
		free(temp);
	}
	free(del);
}

int	getlength(char *line)
{
	char	**arr;
	char	*temp;
	int		length;

	length = 0;
	temp = ft_strtrim(line, "\n");
	arr = ft_split(temp, ' ');
	while (arr[length] != NULL)
	{
		free(arr[length]);
		length++;
	}
	free(arr);
	free(temp);
	return (length);
}
