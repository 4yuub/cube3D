/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:57:47 by akarafi           #+#    #+#             */
/*   Updated: 2022/05/17 23:27:51 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	move_up(t_utils *utils)
{
	double	x_prime;
	double	y_prime;

	x_prime = utils->pos.x + utils->dir.x * .15;
	y_prime = utils->pos.y + utils->dir.y * .15;
	if (utils->data->map[(int)y_prime][(int)x_prime] == EMPTY)
	{
		utils->pos.x = x_prime;
		utils->pos.y = y_prime;
	}
}

void	move_down(t_utils *utils)
{
	double	x_prime;
	double	y_prime;

	x_prime = utils->pos.x - utils->dir.x * .15;
	y_prime = utils->pos.y - utils->dir.y * .15;
	if (utils->data->map[(int)y_prime][(int)x_prime] == EMPTY)
	{
		utils->pos.x = x_prime;
		utils->pos.y = y_prime;
	}
}

void	move_left(t_utils *utils)
{
	t_vector	move_dir;
	double		x_prime;
	double		y_prime;

	move_dir.x = utils->dir.x * cos(PI / 2) + utils->dir.y * -sin(-PI / 2);
	move_dir.y = utils->dir.x * -sin(-PI / 2) + utils->dir.y * cos(PI / 2);
	x_prime = utils->pos.x + move_dir.x * .15;
	y_prime = utils->pos.y - move_dir.y * .15;
	if (utils->data->map[(int)y_prime][(int)x_prime] == EMPTY)
	{
		utils->pos.x = x_prime;
		utils->pos.y = y_prime;
	}
}

void	move_right(t_utils *utils)
{
	t_vector	move_dir;
	double		x_prime;
	double		y_prime;

	move_dir.x = utils->dir.x * cos(PI / 2) + utils->dir.y * -sin(PI / 2);
	move_dir.y = utils->dir.x * -sin(PI / 2) + utils->dir.y * cos(PI / 2);
	x_prime = utils->pos.x + move_dir.x * .15;
	y_prime = utils->pos.y - move_dir.y * .15;
	if (utils->data->map[(int)y_prime][(int)x_prime] == EMPTY)
	{
		utils->pos.x = x_prime;
		utils->pos.y = y_prime;
	}
}
