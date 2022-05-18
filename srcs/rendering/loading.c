/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 00:57:49 by akarafi           #+#    #+#             */
/*   Updated: 2022/05/18 03:55:30 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "colors.h"

void	load_textures(t_utils *utils)
{
	int	x;

	utils->north_texture = mlx_xpm_file_to_image(utils->mlx_ptr, \
		utils->data->north_texture, &x, &x);
	utils->south_texture = mlx_xpm_file_to_image(utils->mlx_ptr, \
		utils->data->south_texture, &x, &x);
	utils->east_texture = mlx_xpm_file_to_image(utils->mlx_ptr, \
		utils->data->east_texture, &x, &x);
	utils->west_texture = mlx_xpm_file_to_image(utils->mlx_ptr, \
		utils->data->west_texture, &x, &x);
	if (!utils->north_texture || !utils->east_texture \
			|| !utils->west_texture || !utils->south_texture)
	{
		printf("%sInvalid Texture file%s\n", RED, RESET);
		free_data(utils->data);
		exit(0);
	}
	utils->img = mlx_new_image(utils->mlx_ptr, WIDTH, HEIGHT);
	utils->img_data = (int *)mlx_get_data_addr(utils->img, &x, &x, &x);
}
