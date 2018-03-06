/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 18:31:38 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/22 18:36:26 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int			mouse_hook(int keycode, int x, int y, t_map *map)
{
	float	scaling;

	scaling = 0;
	if ((keycode == 4 || keycode == 5) && IN_MAP)
	{
		scaling = (keycode == 4) ? 1.25 : 0.8;
		map->zoom *= scaling;
		mlx_clear_window(map->mlx, map->win);
		draw_in_centre(map, x, y);
		init_fractal(map);
	}
	return (1);
}

static int	key_hook(int keycode, t_map *map)
{
	if (keycode == PLUS)
		zoom(map, 1);
	else if (keycode == MINUS)
		zoom(map, -1);
	else if (keycode == SPACE)
		add_iter(map);
	else if (keycode == ESC)
		end(map);
	else if (keycode >= 83 && keycode <= 85)
		change_color(map, keycode);
	else if (keycode == 8)
		change_type_color(map);
	else if (keycode >= 123 && keycode <= 126)
		move_fractal(map, keycode);
	else if (keycode == PAUSE)
		julia_pause(map);
	return (0);
}

static void	get_usage(void)
{
	ft_putstr_fd("usage: mandelbrot, io, julia, ship, newton\n", 2);
	exit(1);
}

static void	check_fractal(int argc, char *name, t_map *map)
{
	if (argc != 2)
		get_usage();
	else if (ft_strcmp("mandelbrot", name) == 0)
		map->type_fractal = 1;
	else if (ft_strcmp("julia", name) == 0)
		map->type_fractal = 2;
	else if (ft_strcmp("io", name) == 0)
		map->type_fractal = 3;
	else if (ft_strcmp("ship", name) == 0)
		map->type_fractal = 4;
	else if (ft_strcmp("newton", name) == 0)
		map->type_fractal = 5;
	else
		get_usage();
}

int			main(int argc, char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->type_fractal = -1;
	check_fractal(argc, argv[1], map);
	init(map, "Fractal");
	init_fractal(map);
	mlx_mouse_hook(map->win, mouse_hook, map);
	mlx_hook(map->win, 2, 0, key_hook, map);
	mlx_hook(map->win, 6, 0, change_julia_c, map);
	mlx_expose_hook(map->win, menu, map);
	mlx_loop(map->mlx);
	return (0);
}
