/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 18:18:26 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/22 18:20:55 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	julia_pause(t_map *map)
{
	if (map->pause == 0)
		map->pause = 1;
	else
		map->pause = 0;
}

int		change_julia_c(int x, int y, t_map *map)
{
	if (IN_MAP && (map->pause == 0))
	{
		map->julia.real = ((double)x / (double)(WIN_WIDTH / 4)) - 2;
		map->julia.image = ((double)y / (double)(WIN_HEIGTH / 4)) - 2;
		mlx_clear_window(map->mlx, map->win);
		init_fractal(map);
	}
	return (1);
}

void	zoom(t_map *map, int d)
{
	if (d < 0)
		map->zoom *= 0.8;
	else
		map->zoom *= 1.2;
	mlx_clear_window(map->mlx, map->win);
	init_fractal(map);
}

void	add_iter(t_map *map)
{
	map->max_iter += 10;
	mlx_clear_window(map->mlx, map->win);
	init_fractal(map);
}

int		menu(t_map *map)
{
	mlx_string_put(map->mlx, map->win, 0, 10, 0xffff4d,
			"Change color: C,NUM1,NUM2,NUM3 ");
	mlx_string_put(map->mlx, map->win, 0, 22, 0xffff4d,
			"Increase max iter: SPACE");
	mlx_string_put(map->mlx, map->win, 0, 34, 0xffff4d,
			"Zoom: +,- or mouse wheel");
	mlx_string_put(map->mlx, map->win, 0, 46, 0xffff4d,
			"Pause: P");
	mlx_string_put(map->mlx, map->win, 0, 58, 0xffff4d,
			"Move fractal: arrows");
	return (1);
}
