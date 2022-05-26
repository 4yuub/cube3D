/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 06:42:18 by akarafi           #+#    #+#             */
/*   Updated: 2022/05/26 03:14:38 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static char	get_type(t_utils *utils, t_vector_i step, int i, int j)
{
	char	c;

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
	return (c);
}

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
			c = get_type(utils, step, i, j);
			if (c == PLAYER)
				utils->minimap.data[i * MINI_WIDTH + j] = 0x00ff00U;
			else if (c == SPACE || c == EMPTY)
				utils->minimap.data[i * MINI_WIDTH + j] = 0xffffffffU;
			else if (c == DOOR)
				utils->minimap.data[i * MINI_WIDTH + j] = 0x44e3e3e3U;
			else
				utils->minimap.data[i * MINI_WIDTH + j] = 0x44000000U;
		}
	}
}
