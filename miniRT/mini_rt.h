/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:12:46 by chelmerd          #+#    #+#             */
/*   Updated: 2022/09/25 20:58:41 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include "matrix.h"
# include "mlx.h"
# include "vector.h"
# include "libft.h"
# include "keys.h"
# include "scene.h"
# include "ray.h"
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>

# define HEIGHT 900 //960
# define WIDTH 1440 //1280

# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF

# define MIN_RATIO 0.f
# define MAX_RATIO 1.f

# define MAX_UNIT_VECTOR_COMP 1.f
# define MIN_UNIT_VECTOR_COMP -1.f

# define MIN_COLOR_VALUE 0
# define MAX_COLOR_VALUE 255

# define MIN_FOV 0
# define MAX_FOV 180

# define MAX_FLOAT 2000
# define MAX_PRECISION 4

# define SHADOW_BIAS 0.1f

struct s_data
{
	void				*mlx;
	void				*win;
	void				*img;
};
typedef struct s_data		t_data;

struct					s_img_info
{
	int					bits_per_pixel;
	int					line_size;
	int					endian;
	float				aspectratio;
};

struct					s_2d_coord
{
	int					x;
	int					y;
};

struct s_hit_record
{
	float					pos[VEC3_SIZE];
	float					normal[VEC3_SIZE];
	float					color[VEC3_SIZE];
};
typedef struct s_hit_record	t_hit_record;

//	check_file.c
int				checkfile(char *path);
int				readfile(int fd);
int				checkline(char *line, char *duplicate);
int				check_cylinder(char *line);
void			readfile_helper(char *line, int fd, int *err);

//	check_elements.c
int				check_amlight(char *line, char *duplicate);
int				check_camera(char *line, char *duplicate);
int				check_light(char *line, char *duplicate);
int				check_sphere(char *line);
int				check_plane(char *line);

//	check_utils.c
int				arr_size(char **arr);
void			arr_free(char **arr);
void			replace_tabs(char *line);
float			ft_atof(const char *str);
int				check_string_range(char *str, int min, int max);

//	check_info.c
int				check_color(char *color, int islight);
int				check_int(char *info);
int				check_float(char *info);
int				check_vector(char *argument);
int				check_vector_range(char *argument, int min, int max);

//	store_data.c
int				store_data(char *path, t_scene	*scene);
void			get_data(char *line, int fd, int *err, t_scene *scene);
int				save_data(char *line, t_scene *scene);
int				str_to_vec(char *info, float *vec);
int				save_cylinder(char *line, t_scene *scene);

//	store_elements.c
int				save_amlight(char *line, t_scene *scene);
int				save_camera(char *line, t_scene *scene);
int				save_light(char *line, t_scene *scene);
int				save_sphere(char *line, t_scene *scene);
int				save_plane(char *line, t_scene *scene);

//	utils.c
void			exit_fatal(void);
void			*new(size_t size);
bool			intersection_with_light_ray(t_scene *scene, \
				float point[VEC3_SIZE], float dis_to_light);
float			distance(float start_point[VEC3_SIZE], \
				float end_point[VEC3_SIZE]);
float			ufo(int pixel, struct s_img_info img_info, t_scene *scene, \
				int coordinate);

//	ray.c
float			*ray_at(struct s_ray *ray, float t, float *point);
void			ray_cast(float *origin, float *point, struct s_ray *ray);
void			ray_camera(t_camera *camera, float *point, struct s_ray *ray);
bool			ray_intersect(struct s_ray *ray, t_scene *scene, \
				t_list **intersections);
bool			hit_object(t_obj *obj, struct s_ray *ray, t_hit_record *hit);

//	render.c
unsigned int	choose_color(t_scene *scene, float u, float v);

//	color.c
unsigned int	get_color(unsigned alpha, unsigned r, unsigned g, unsigned b);
float			*color_vec(float color[VEC3_SIZE], float *result);
int				convert_to_argb(float rgb[VEC3_SIZE]);

//	transform.c
void			set_transform(float transl[VEC3_SIZE], float rotation \
				[VEC3_SIZE], float scale[VEC3_SIZE], t_tform *transform);
float			*apply_transform(float vec[VEC3_SIZE], \
				float transf[MAT4_SIZE], bool is_point, float *result);
void			translate_rotate(float pos[VEC3_SIZE], float normal[VEC3_SIZE],
					float v_up[VEC3_SIZE], t_tform *transform);

//	intersection.c
void			fill_hit_record(float *pos, float *normal, float *color,
					t_hit_record *hit);
t_hit_record	*new_hit_record(float *pos, float *normal, float *color);
bool			add_hit_record(t_list **records, t_hit_record *hit);
t_hit_record	*get_hit_record(t_list *records, int index);
t_hit_record	*get_closest_hit(t_list *hits, float pos[VEC3_SIZE]);

#endif
