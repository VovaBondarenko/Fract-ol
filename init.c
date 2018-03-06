/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 18:16:01 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/22 18:17:06 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	end(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	exit(0);
}

void	init(t_map *map, char *name)
{
	map->mlx = mlx_init();
	map->width = WIN_WIDTH;
	map->heigth = WIN_HEIGTH;
	map->index.x = 0;
	map->index.y = 0;
	map->move_x = 0;
	map->move_y = 0;
	map->zoom = 1;
	map->max_iter = MAX_ITER;
	map->color = 0x00cbff;
	map->julia.real = 0;
	map->julia.image = 0;
	map->pause = 0;
	map->rainbow_color.frequency = 0.4;
	map->rainbow_color.center = 164;
	map->rainbow_color.width = 91;
	map->rainbow_color.r = 3;
	map->rainbow_color.g = 5;
	map->rainbow_color.b = 6;
	map->type_color = 1;
	map->win = mlx_new_window(map->mlx, map->width, map->heigth, name);
}
