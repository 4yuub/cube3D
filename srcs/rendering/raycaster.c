/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 00:46:06 by akarafi           #+#    #+#             */
/*   Updated: 2022/05/19 00:14:28 by akarafi          ###   ########.fr       */
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
		utils->screen.data[WIDTH * i + x] = (unsigned int)utils->screen.c;
	while (i < end)
	{
		utils->tex_y = (int)utils->tex_pos & (utils->texture->height - 1);
		utils->screen.data[WIDTH * i++ + x] = utils->texture->data[\
			utils->texture->height * utils->tex_y + utils->tex_x];
		utils->tex_pos += utils->_step;
	}
	while (i < HEIGHT)
		utils->screen.data[WIDTH * i++ + x] = (unsigned int)utils->screen.f;
}

static void	get_texture_type(t_utils *utils)
{
	if (utils->side)
	{
		utils->texture = &utils->no;
		if (utils->step.y == -1)
			utils->texture = &utils->so;
	}
	else
	{
		utils->texture = &utils->ea;
		if (utils->step.x == -1)
			utils->texture = &utils->we;
	}
}

static void	draw_in_screen(t_utils *utils, int x)
{
	int		line_height;
	double	wall_x;	
	int		start;
	int		end;

	line_height = HEIGHT / (utils->dist.y - utils->new_dist.y);
	if (utils->side == 0)
		line_height = HEIGHT / (utils->dist.x - utils->new_dist.x);
	start = -line_height / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = line_height / 2 + HEIGHT / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	wall_x = utils->pos.x + \
		(utils->dist.y - utils->new_dist.y) * utils->ray_dir.x;
	if (utils->side == 0)
		wall_x = utils->pos.y + \
			(utils->dist.x - utils->new_dist.x) * utils->ray_dir.y;
	wall_x -= (int)wall_x;
	utils->tex_x = (int)(wall_x * (double)utils->texture->width);
	utils->_step = (double) utils->texture->height / line_height;
	utils->tex_pos = (start - HEIGHT / 2 + line_height / 2) * utils->_step; // prouf
	get_texture_type(utils);
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
	mlx_put_image_to_window(utils->mlx_ptr, utils->mlx_win, \
											utils->screen.img, 0, 0);
	return (0);
}
