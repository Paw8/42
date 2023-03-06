/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:38:00 by pcordeir          #+#    #+#             */
/*   Updated: 2022/04/19 19:58:46 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	putimage(t_screen *win, int fd)
{
	double	mx;
	double	my;
	int		i;

	win->file2 = c_line(fd);
	my = win->factor * 6;
	mx = 700;
	i = 0;
	while (i <= win->width - 1)
	{
		win->file1 = win->file2;
		putline_l(win, mx, my);
		win->file2 = c_line(fd);
		if (i < win->width - 1)
		{
			putline_w(win, mx, my);
			mx += win->factor * -0.866;
			my += win->factor * 0.5 + (win->file2->z - win->file1->z) * -1;
		}
		freelist(win->file1);
		i++;
	}
	free(win->file2);
}

void	putline_l(t_screen *img, double mx, double my)
{
	t_file	*temp;

	temp = img->file1;
	while (temp->next)
	{
		while (temp->x <= img->factor)
		{
			temp->u = temp->x * 0.866 + temp->y * -0.866;
			temp->v = temp->x * 0.5 + temp->y * 0.5 + (temp->x * \
			((temp->next->z - temp->z) / img->factor)) * -1;
			my_mlx_pixel_put(img, mx + temp->u, my + temp->v, 0x00FFFFFF);
			(temp->x)++;
		}
		mx += temp->u;
		my += temp->v;
		temp = temp->next;
	}
}

void	putline_w(t_screen *img, double mx, double my)
{
	int		i;
	t_file	*temp;
	t_file	*temp2;

	temp = img->file1;
	temp2 = img->file2;
	i = 1;
	while (i <= img->length && temp2 && temp)
	{
		while (temp2->y <= img->factor)
		{
			temp2->u = temp2->x * 0.866 + temp2->y * -0.866;
			temp2->v = temp2->x * 0.5 + temp2->y * 0.5 + (temp2->y * \
			((temp2->z - temp->z) / img->factor)) * -1;
			my_mlx_pixel_put(img, mx + temp2->u, my + temp2->v, 0x00FFFFFF);
			(temp2->y)++;
		}
		temp2->y = 0;
		temp2 = temp2->next;
		mx += img->factor * 0.866;
		if (temp->next)
			my += img->factor * 0.5 + (temp->next->z - temp->z) * -1;
		temp = temp->next;
		i++;
	}
}

t_file	*c_line(int fd)
{
	char	*line;
	t_file	*head;

	head = 0;
	line = get_next_line(fd);
	if (line)
		head = create_list(line);
	free(line);
	return (head);
}

t_file	*create_list(char *temp)
{
	double	hight;
	t_file	*head;

	hight = 0;
	head = 0;
	while (*temp)
	{
		if (*temp == '-' || ft_isdigit(*temp))
		{
			hight = ft_atoi(temp);
			head = newnode(head, (double)hight);
			while (*temp != '\n' && *temp != ' ')
				temp++;
		}
		temp++;
	}
	return (head);
}
