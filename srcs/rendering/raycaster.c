/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 00:46:06 by akarafi           #+#    #+#             */
/*   Updated: 2022/05/16 19:06:22 by akarafi          ###   ########.fr       */
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
	utils->hit = false;
	utils->step.x = 1;
	utils->step.y = 1;
	if (utils->dir.x < 0)
	{
		utils->step.x = -1;
		utils->dist.x = (utils->pos.x - utils->map.x) * utils->new_dist.x;
	}
	if (utils->dir.y < 0)
	{
		utils->step.y = -1;
		utils->dist.y = (utils->pos.x - utils->map.y) * utils->new_dist.y;
	}
	dda_algorithm(utils);
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
		//draw_in_screen(utils);
	}
	return (0);
}
