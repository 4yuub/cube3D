/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 06:42:18 by akarafi           #+#    #+#             */
/*   Updated: 2022/05/20 01:14:16 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_minimap(t_utils *utils)
{
	int				i;
	int				j;
	int8_t			c;
	unsigned int	color;
	t_vector_i		step;

	i = -1;
	step.x = MINI_WIDTH / utils->data->width;
	step.y = MINI_HEIGHT / utils->data->height;
	while (++i < MINI_HEIGHT)
	{
		j = -1;
		while (++j < MINI_WIDTH)
		{
			if ((j / step.x) >= utils->data->width
				|| (i / step.y) >= utils->data->height)
				c = EMPTY;
			else
				c = utils->data->map[(i / step.y)] \
									[(j / step.x)];
			if (c == SPACE || c == EMPTY)
				color = 0xffffffff;
			else
				color = 0x44000000;
			utils->minimap.data[i * MINI_WIDTH + j] = color;
		}
	}
}
