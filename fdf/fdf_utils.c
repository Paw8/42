/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:01:47 by pcordeir          #+#    #+#             */
/*   Updated: 2022/04/19 14:41:23 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_screen *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + x * (data->bits_per_pixel / 8) + y * data->size_line;
	*(unsigned int *)dst = color;
}

int	render_next_frame(void *vars)
{
	t_screen	*dest;

	dest = vars;
	if (dest->img)
		mlx_put_image_to_window(dest->mlx, dest->win, dest->img, 0, 0);
	return (0);
}

int	key_hook(int keycode, t_screen *vars)
{
	if (keycode == 65307)
		ft_close(vars);
	return (0);
}

int	ft_close(t_screen *vars)
{
	mlx_loop_end(vars->mlx);
	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = 0;
	return (0);
}
