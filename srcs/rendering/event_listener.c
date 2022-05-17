/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 00:35:20 by akarafi           #+#    #+#             */
/*   Updated: 2022/05/17 23:01:32 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	move_down(t_utils *utils);
void	move_up(t_utils *utils);
void	move_left(t_utils *utils);
void	move_right(t_utils *utils);

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

	x_prime = utils->dir.x * cos(angel) + utils->dir.y * sin(angel);
	y_prime = utils->dir.x * -sin(angel) + utils->dir.y * cos(angel);
	utils->dir.x = x_prime;
	utils->dir.y = y_prime;
	x_prime = utils->camera_plane.x * cos(angel) + \
										utils->camera_plane.y * sin(angel);
	y_prime = utils->camera_plane.x * -sin(angel) + \
										utils->camera_plane.y * cos(angel);
	utils->camera_plane.x = x_prime;
	utils->camera_plane.y = y_prime;
}

int	event_listener(int key, t_utils *utils)
{
	if (key == KEY_ESC)
		__exit(utils->data);
	if (key == KEY_AR_L)
		rotate(utils, 0.15);
	else if (key == KEY_A)
		move_left(utils);
	else if (key == KEY_D)
		move_right(utils);
	else if (key == KEY_AR_R)
		rotate(utils, -0.15);
	else if (key == KEY_W)
		move_up(utils);
	else if (key == KEY_S)
		move_down(utils);
	return (0);
}
