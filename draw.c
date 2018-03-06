/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 18:05:07 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/22 18:13:59 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	move_fractal(t_map *map, int keycode)
{
	if (keycode == 123 || keycode == 124)
		map->move_x += (keycode == 124) ? 10 : -10;
	else if (keycode == 125 || keycode == 126)
		map->move_y += (keycode == 125) ? 10 : -10;
	mlx_clear_window(map->mlx, map->win);
	init_fractal(map);
}

void	draw_in_centre(t_map *map, int x, int y)
{
	int	centre_x;
	int	centre_y;
	int	delta_x;
	int	delta_y;

	centre_x = WIN_WIDTH / 2;
	centre_y = WIN_HEIGTH / 2;
	delta_x = x - centre_x;
	delta_y = y - centre_y;
	map->move_x += delta_x;
	map->move_y += delta_y;
}

void	init_fractal(t_map *map)
{
	map->index.y = 0;
	while (map->index.y < WIN_HEIGTH)
	{
		map->index.x = 0;
		while (map->index.x < WIN_WIDTH)
		{
			map->iter = 0;
			draw_fractal(map);
			++map->index.x;
		}
		++map->index.y;
	}
}

void	draw_fractal(t_map *map)
{
	if (map->type_fractal == 1)
		mandelbrot(map);
	else if (map->type_fractal == 2)
		julia(map);
	else if (map->type_fractal == 3)
		io(map);
	else if (map->type_fractal == 4)
		ship(map);
	else if (map->type_fractal == 5)
		newton(map);
	if (map->iter < map->max_iter)
		mlx_pixel_put(map->mlx, map->win, map->index.x
				, map->index.y, use_type_color(map));
	else
		mlx_pixel_put(map->mlx, map->win, map->index.x, map->index.y, 0x000000);
}
