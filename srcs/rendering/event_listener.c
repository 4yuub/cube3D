/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 00:35:20 by akarafi           #+#    #+#             */
/*   Updated: 2022/05/16 23:59:31 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	__exit(t_data *data)
{
	free_data(data);
	exit(0);
	return (0);
}

static void	rotate(t_utils *utils, double angel)
{
	double	x_prime;
	double	y_prime;

	mlx_clear_window(utils->mlx_ptr, utils->mlx_win);
	x_prime = utils->dir.x * cos(angel) - utils->dir.y * sin(angel);
	y_prime = utils->dir.y * sin(angel) + utils->dir.x * cos(angel);
	utils->dir.x = x_prime;
	utils->dir.y = y_prime;
	x_prime = utils->camera_plane.x * cos(angel) - \
										utils->camera_plane.y * sin(angel);
	y_prime = utils->camera_plane.y * sin(angel) + \
										utils->camera_plane.x * cos(angel);
	utils->camera_plane.x = x_prime;
	utils->camera_plane.y = y_prime;
}

static void	move_up(t_utils *utils)
{
	mlx_clear_window(utils->mlx_ptr, utils->mlx_win);
	if (utils->data->map[(int)(utils->pos.x + \
			utils->dir.x * .15)][(int) utils->pos.y] == EMPTY)
		utils->pos.x += utils->dir.x * .15;
	if (utils->data->map[(int)utils->pos.x][(int)(utils->pos.y + \
			utils->dir.y * .15)] == EMPTY)
		utils->pos.y += utils->dir.y * .15;
}

static void	move_down(t_utils *utils)
{
	mlx_clear_window(utils->mlx_ptr, utils->mlx_win);
	if (utils->data->map[(int)(utils->pos.x - \
			utils->dir.x * .15)][(int) utils->pos.y] == EMPTY)
		utils->pos.x -= utils->dir.x * .15;
	if (utils->data->map[(int) utils->pos.x][(int)(utils->pos.y - \
			utils->dir.y * .15)] == EMPTY)
		utils->pos.y -= utils->dir.y * .15;
}

int	event_listener(int key, t_utils *utils)
{
	if (key == KEY_ESC)
		__exit(utils->data);
	if (key == KEY_AR_L || key == KEY_A)
		rotate(utils, -0.15);
	else if (key == KEY_AR_R || key == KEY_D)
		rotate(utils, 0.15);
	if (key == KEY_AR_U || key == KEY_W)
		move_up(utils);
	if (key == KEY_AR_D || key == KEY_S)
		move_down(utils);
	return (0);
}
