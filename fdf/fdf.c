/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:48:34 by pcordeir          #+#    #+#             */
/*   Updated: 2022/04/19 20:27:30 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(char *file, int length, int width)
{
	t_screen	win;
	int			fd;

	win.factor = getsize(length + width);
	win.length = length;
	win.width = width;
	fd = open(file, O_RDONLY);
	win.mlx = mlx_init();
	win.img = mlx_new_image(win.mlx, 1600, 960);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, \
	&win.size_line, &win.endian);
	win.win = mlx_new_window(win.mlx, 1600, 960, file);
	mlx_loop_hook(win.mlx, render_next_frame, &win);
	mlx_key_hook(win.win, key_hook, &win);
	mlx_hook(win.win, 17, 0, ft_close, &win);
	putimage(&win, fd);
	mlx_loop(win.mlx);
	mlx_destroy_window(win.mlx, win.win);
	mlx_destroy_display(win.mlx);
	free(win.mlx);
}

int	getsize(int size)
{
	if (size <= 40)
		return (32);
	else if (size <= 100 && size > 40)
		return (16);
	else if (size <= 200 && size > 100)
		return (8);
	else if (size <= 400 && size > 200)
		return (4);
	else
		return (1);
}
