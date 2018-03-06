/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 18:46:56 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/22 18:53:36 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "minilibx_macos/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# include "libft/libft.h"

# define WIN_HEIGTH 800
# define WIN_WIDTH 1200
# define MAX_ITER 60
# define NUM_THREADS 4

# define RADIUS_NOT_MAX ((new.real * new.real + new.image * new.image) < 4)
# define IN_MAP (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGTH)

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define SPACE 49
# define PLUS 69
# define MINUS 78
# define NUM_1 83
# define NUM_2 84
# define NUM_3 85
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_UP 126
# define PAUSE 35
# define KEY_C 8

typedef struct	s_complex
{
	double		real;
	double		image;
}				t_complex;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_color
{
	double		frequency;
	int			center;
	int			width;
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_map
{
	void		*mlx;
	void		*win;
	int			width;
	int			heigth;
	int			type_fractal;
	int			max_iter;
	int			color;
	int			type_color;
	int			pause;
	t_point		index;
	t_color		rainbow_color;
	t_complex	julia;
	double		zoom;
	float		move_x;
	float		move_y;
	int			iter;
	int			center_x;
	int			center_y;
}				t_map;

typedef struct	s_thread
{
	t_map		*map;
	int			index;
	int			y;
}				t_thread;

void			init(t_map *map, char *name);
void			end(t_map *map);
void			mandelbrot(t_map *map);
void			julia(t_map *map);
void			ship(t_map *map);
void			newton(t_map *map);
void			io(t_map *map);
void			init_fractal(t_map *map);
void			draw_fractal(t_map *map);
void			draw_in_centre(t_map *map, int x, int y);
void			move_fractal(t_map *map, int keycode);
int				get_color(t_map *map);
void			change_color(t_map *map, int keycode);
int				rainbow_color(t_map *map);
int				use_type_color(t_map *map);
void			change_type_color(t_map *map);
void			add_iter(t_map *map);
void			zoom(t_map *map, int d);
void			julia_pause(t_map *map);
int				change_julia_c(int x, int y, t_map *map);
int				menu(t_map *map);

#endif
