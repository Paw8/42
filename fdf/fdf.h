/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:44:26 by pcordeir          #+#    #+#             */
/*   Updated: 2022/04/19 20:27:42 by pcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct _file_ {
	int				x;
	int				y;
	double			z;
	double			u;
	double			v;
	int				color;
	struct _file_	*next;
}t_file;

typedef struct _screen_ {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		length;
	int		factor;
	t_file	*file1;
	t_file	*file2;
}t_screen;

int		checkfile(char *path, int *width);
void	invalid(char *s, int fd);
char	*loop1(char *s);
char	*loop2(char *s);
char	*loop3(char *s);
int		getlength(char *line);
int		getsize(int size);

t_file	*newnode(t_file *head, double z);
t_file	*c_line(int fd);
t_file	*create_list(char *temp);
void	freelist(t_file *del);

void	fdf(char *file, int length, int width);
void	my_mlx_pixel_put(t_screen *data, int x, int y, int color);
int		key_hook(int keycode, t_screen *vars);
int		ft_close(t_screen *vars);
int		render_next_frame(void *vars);
void	putimage(t_screen *win, int fd);
void	putline_l(t_screen *img, double mx, double my);
void	putline_w(t_screen *img, double mx, double my);

#endif