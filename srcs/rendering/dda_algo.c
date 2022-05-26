/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:17:08 by akarafi           #+#    #+#             */
/*   Updated: 2022/05/26 03:28:06 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	dda_algorithm(t_utils *utils)
{
	utils->door = false;
	while (!utils->door && utils->data->map[utils->map.y][utils->map.x] != WALL)
	{
		if (utils->dist.x < utils->dist.y)
		{
			utils->dist.x += utils->new_dist.x;
			utils->map.x += utils->step.x;
			utils->side = 0;
		}
		else
		{
			utils->dist.y += utils->new_dist.y;
			utils->map.y += utils->step.y;
			utils->side = 1;
		}
		if (utils->data->map[utils->map.y][utils->map.x] == DOOR)
		{
			if ((utils->side == 0 && (int)utils->dist.x > 3) \
				|| (utils->side == 1 && (int)utils->dist.y > 3))
				utils->door = true;
		}
	}
}
