/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 06:42:18 by akarafi           #+#    #+#             */
/*   Updated: 2022/05/25 00:42:58 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_minimap(t_utils *utils)
{
	int				i;
	int				j;
	int8_t			c;
	t_vector_i		step;

	i = -1;
	step.x = MINI_WIDTH / utils->data->width;
	step.y = MINI_HEIGHT / utils->data->height;
	while (++i < MINI_HEIGHT)
	{
		j = -1;
		while (++j < MINI_WIDTH)
		{
			if ((j / step.x) >= utils->data->width \
				|| (i / step.y) >= utils->data->height)
				c = EMPTY;
			else
			{
				c = utils->data->map[(i / step.y)][(j / step.x)];
				if (utils->pos.x - ((double)j / step.x) < .3 \
					&& utils->pos.x - ((double)j / step.x) >= -.3 \
					&& utils->pos.y - ((double)i / step.y) >= -.3
					&& utils->pos.y - ((double)i / step.y) < .3)
					c = PLAYER;
			}
			if (c == PLAYER)
				utils->minimap.data[i * MINI_WIDTH + j] = 0x00ff00U;
			else if (c == SPACE || c == EMPTY)
				utils->minimap.data[i * MINI_WIDTH + j] = 0xffffffffU;
			else
				utils->minimap.data[i * MINI_WIDTH + j] = 0x44000000U;
		}
	}
}
