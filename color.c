/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 17:54:44 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/22 18:04:53 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		change_type_color(t_map *map)
{
	if (map->type_color == 1)
		map->type_color = 0;
	else
		map->type_color = 1;
	mlx_clear_window(map->mlx, map->win);
	init_fractal(map);
}

int			rainbow_color(t_map *map)
{
	int		color;
	int		r;
	int		g;
	int		b;

	r = sin(map->rainbow_color.frequency * map->iter
			+ map->rainbow_color.r) * map->rainbow_color.width
		+ map->rainbow_color.center;
	g = sin(map->rainbow_color.frequency * map->iter +
			map->rainbow_color.g) * map->rainbow_color.width
		+ map->rainbow_color.center;
	b = sin(map->rainbow_color.frequency * map->iter +
			map->rainbow_color.b) * map->rainbow_color.width
		+ map->rainbow_color.center;
	color = ((b >> 16) & 0xFF);
	color = ((g >> 8) & 0xFF);
	color = ((r) & 0xFF);
	return (color);
}

void		change_color(t_map *map, int keycode)
{
	if (keycode == 83)
		map->color = 0xff0000;
	else if (keycode == 84)
		map->color = 0xff0083;
	else if (keycode == 85)
		map->color = 0x00cbff;
	init_fractal(map);
}

int			get_color(t_map *map)
{
	int		color;

	if (map->iter < map->max_iter * 0.1)
		color = 0xffffff;
	else if (map->iter < map->max_iter * 0.3)
		color = map->color * (map->iter / 2);
	else
		color = map->color * map->iter;
	return (color);
}

int			use_type_color(t_map *map)
{
	int		color;

	color = 0xffffff;
	if (map->type_color == 1)
		color = rainbow_color(map);
	else
		color = get_color(map);
	return (color);
}
