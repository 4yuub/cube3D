/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 00:46:06 by akarafi           #+#    #+#             */
/*   Updated: 2022/05/18 04:00:53 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	calc_distance_to_next_wall(t_utils *utils)
{
	utils->new_dist.x = fabs(1 / utils->ray_dir.x);
	utils->new_dist.y = fabs(1 / utils->ray_dir.y);
	utils->map.x = (int) utils->pos.x;
	utils->map.y = (int) utils->pos.y;
	utils->dist.x = (utils->map.x + 1 - utils->pos.x) * utils->new_dist.x;
	utils->dist.y = (utils->map.y + 1 - utils->pos.y) * utils->new_dist.y;
	utils->step.x = 1;
	utils->step.y = 1;
	if (utils->ray_dir.x < 0)
	{
		utils->step.x = -1;
		utils->dist.x = (utils->pos.x - utils->map.x) * utils->new_dist.x;
	}
	if (utils->ray_dir.y < 0)
	{
		utils->step.y = -1;
		utils->dist.y = (utils->pos.y - utils->map.y) * utils->new_dist.y;
	}
	dda_algorithm(utils);
}

static void	draw_vertical_line(t_utils *utils, int start, int end, int x)
{
	int	i;

	i = -1;
	while (++i <= start)
		utils->img_data[WIDTH * i + x] = 0x0f0f0f;
	while (i < end)
		utils->img_data[WIDTH * i++ + x] = utils->color;
	while (i < HEIGHT)
		utils->img_data[WIDTH * i++ + x] = 0xe3e3e3;
}

static void	get_color(t_utils *utils)
{
	if (utils->side)
	{
		utils->color = 0xff0000; // NO
		if (utils->step.y == -1)
			utils->color = 0x00ff00; // SO
	}
	else
	{
		utils->color = 0x0000ff; // EA
		if (utils->step.x == -1)
			utils->color = 0xffff00; // WE
	}
}

static void	draw_in_screen(t_utils *utils, int x)
{
	int	line_height;
	int	start;
	int	end;

	line_height = HEIGHT / (utils->dist.y - utils->new_dist.y);
	if (utils->side == 0)
		line_height = HEIGHT / (utils->dist.x - utils->new_dist.x);
	start = -line_height / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = line_height / 2 + HEIGHT / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	get_color(utils);
	draw_vertical_line(utils, start, end, x);
}

int	raycaster(t_utils *utils)
{
	int		x;
	double	a;
	double	b;

	x = -1;
	b = -1;
	a = 2.0 / WIDTH;
	while (++x < WIDTH)
	{
		utils->ray_dir.x = utils->dir.x + utils->camera_plane.x * (a * x + b);
		utils->ray_dir.y = utils->dir.y + utils->camera_plane.y * (a * x + b);
		calc_distance_to_next_wall(utils);
		draw_in_screen(utils, x);
	}
	mlx_put_image_to_window(utils->mlx_ptr, utils->mlx_win, utils->img, 0, 0);
	return (0);
}
