/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 00:13:35 by akarafi           #+#    #+#             */
/*   Updated: 2022/05/26 05:58:55 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	__exit(t_utils *data);

static void	init_utils(t_utils *utils)
{
	int	dir;

	utils->mlx_ptr = mlx_init();
	utils->mlx_win = mlx_new_window(utils->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	utils->pos.x = utils->data->palyer_position.x + .0001;
	utils->pos.y = utils->data->palyer_position.y + .0001;
	dir = utils->data->palyer_position.direction;
	utils->dir.x = -1;
	if (dir == NO || dir == SO)
		utils->dir.x = 0;
	else if (dir == WE)
		utils->dir.x = 1;
	utils->dir.y = -1;
	if (dir == EA || dir == WE)
		utils->dir.y = 0;
	else if (dir == NO)
		utils->dir.y = 1;
	utils->camera_plane.x = (utils->dir.x * cos(-PI / 2) + \
							utils->dir.y * sin(-PI / 2)) * (1 / tan(PI / 3));
	utils->camera_plane.y = (utils->dir.x * -sin(-PI / 2) + \
							utils->dir.y * cos(-PI / 2)) * (1 / tan(PI / 3));
	utils->screen.img = mlx_new_image(utils->mlx_ptr, WIDTH, HEIGHT);
	utils->screen.data = (int *)mlx_get_data_addr(utils->screen.img, \
		&utils->screen.bpp, &utils->screen.sl, &utils->screen.endian);
}

static void	init_colors(t_utils *utils)
{
	t_color	*c;

	c = &utils->data->floor_color;
	utils->screen.f = (c->r << 16) | (c->g << 8) | c->b;
	c = &utils->data->ceil_color;
	utils->screen.c = (c->r << 16) | (c->g << 8) | c->b;
}

void	render(t_data *data)
{
	t_utils	*utils;

	utils = malloc(sizeof(t_utils));
	if (!utils)
	{
		printf("An error have been occured: Allcoation Error");
		free_data(data);
		exit(0);
	}
	utils->data = data;
	init_utils(utils);
	utils->minimap.img = mlx_new_image(utils->mlx_ptr, MINI_WIDTH, MINI_HEIGHT);
	utils->minimap.data = (int *)mlx_get_data_addr(utils->minimap.img, \
		&utils->minimap.bpp, &utils->minimap.sl, &utils->minimap.endian);
	load_textures(utils);
	load_torch(utils);
	init_colors(utils);
	utils->old_mouse = -1;
	mlx_loop_hook(utils->mlx_ptr, raycaster, utils);
	mlx_hook(utils->mlx_win, 2, 1L, event_listener, utils);
	mlx_hook(utils->mlx_win, 6, 1L, mouse_event, utils);
	mlx_hook(utils->mlx_win, 17, 1L, __exit, utils);
	mlx_loop(utils->mlx_ptr);
}
