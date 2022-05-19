/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:17:08 by akarafi           #+#    #+#             */
/*   Updated: 2022/05/19 06:32:25 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	dda_algorithm(t_utils *utils)
{
	while (utils->data->map[utils->map.y][utils->map.x] != WALL)
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
	}
}
