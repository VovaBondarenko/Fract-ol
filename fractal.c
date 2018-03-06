/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 18:21:57 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/22 18:30:14 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void			mandelbrot(t_map *map)
{
	t_complex	new;
	t_complex	old;
	t_complex	c;

	c.real = 1.5 * (map->index.x + map->move_x -
			WIN_WIDTH / 2) / (0.5 * map->zoom * WIN_WIDTH);
	c.image = (map->index.y + map->move_y -
			WIN_HEIGTH / 2) / (0.5 * map->zoom * WIN_HEIGTH);
	new.real = 0;
	new.image = 0;
	while (map->iter < map->max_iter)
	{
		old.real = new.real;
		old.image = new.image;
		new.real = old.real * old.real - old.image * old.image + c.real;
		new.image = 2 * old.real * old.image + c.image;
		if (new.real * new.real + new.image * new.image > 4.0)
			break ;
		++map->iter;
	}
	if (map->iter != map->max_iter)
		map->iter += 1 - (log((log(sqrt(new.real * new.real +
								new.image * new.image)) / 2) /
					log(2)) / log(2));
}

void			julia(t_map *map)
{
	t_complex	old;
	t_complex	new;

	new.real = 1.5 * (map->index.x + map->move_x -
			WIN_WIDTH / 2) / (0.5 * map->zoom * WIN_WIDTH);
	new.image = (map->index.y + map->move_y -
			WIN_HEIGTH / 2) / (0.5 * map->zoom * WIN_HEIGTH);
	while (map->iter < map->max_iter)
	{
		old.real = new.real;
		old.image = new.image;
		new.real = old.real * old.real -
			old.image * old.image + map->julia.real;
		new.image = 2 * old.real * old.image + map->julia.image;
		++map->iter;
		if (new.real * new.real + new.image * new.image > 4.0)
			break ;
	}
	if (map->iter != map->max_iter)
		map->iter += 1 - (log((log(sqrt(new.real * new.real +
								new.image * new.image)) / 2) /
					log(2)) / log(2));
}

void			ship(t_map *map)
{
	t_complex	new;
	t_complex	old;
	t_complex	c;

	c.real = 1.5 * (map->index.x + map->move_x -
			WIN_WIDTH / 2) / (0.5 * map->zoom * WIN_WIDTH);
	c.image = (map->index.y + map->move_y -
			WIN_HEIGTH / 2) / (0.5 * map->zoom * WIN_HEIGTH);
	new.real = 0;
	new.image = 0;
	while (map->iter < map->max_iter)
	{
		old.real = new.real;
		old.image = new.image;
		new.real = old.real * old.real - old.image * old.image + c.real;
		new.image = (2 * fabs(old.real) * fabs(old.image)) + c.image;
		++map->iter;
		if (new.real * new.real + new.image * new.image > 4.0)
			break ;
	}
}

void			newton(t_map *map)
{
	t_complex	new;
	t_complex	old;
	double		tmp;

	new.real = 1.5 * (map->index.x + map->move_x -
			WIN_WIDTH / 2) / (0.5 * map->zoom * WIN_WIDTH);
	new.image = (map->index.y + map->move_y -
			WIN_HEIGTH / 2) / (0.5 * map->zoom * WIN_HEIGTH);
	tmp = 1.0;
	while (tmp > 0.000001 && map->iter < map->max_iter)
	{
		old.real = new.real;
		old.image = new.image;
		tmp = (new.real * new.real + new.image * new.image) *
			(new.real * new.real + new.image * new.image);
		new.real = (2 * new.real * tmp + new.real * new.real -
				new.image * new.image) / (3.0 * tmp);
		new.image = (2 * new.image * (tmp - old.real)) / (3.0 * tmp);
		tmp = (new.real - old.real) * (new.real - old.real) +
			(new.image - old.image) * (new.image - old.image);
	}
	if (map->iter != map->max_iter)
		map->iter += 1 - (log((log(sqrt(new.real * new.real +
								new.image * new.image)) / 2) /
					log(2)) / log(2));
}

void			io(t_map *map)
{
	t_complex	new;
	t_complex	old;

	new.real = 1.5 * (map->index.x + map->move_x -
			WIN_WIDTH / 2) / (0.5 * map->zoom * WIN_WIDTH);
	new.image = (map->index.y + map->move_y -
			WIN_HEIGTH / 2) / (0.5 * map->zoom * WIN_HEIGTH);
	while (map->iter < map->max_iter)
	{
		old.real = new.real;
		old.image = new.image;
		new.real = old.real * old.real * old.real * old.real
			+ old.image * old.image * old.image * old.image -
			6 * old.real * old.real * old.image * old.image + map->julia.real;
		new.image = 4 * old.real * old.real * old.real * old.image -
			4 * old.real * old.image * old.image * old.image + map->julia.image;
		if (old.real * old.image > 4 || old.image * old.image > 4)
			break ;
		++map->iter;
	}
	if ((fabs(new.real)) > 10 || (fabs(new.image) > 1000))
		map->iter += 1 - (log((log(sqrt(new.real * new.real +
								new.image * new.image)) / 2) /
					log(2)) / log(2));
}
