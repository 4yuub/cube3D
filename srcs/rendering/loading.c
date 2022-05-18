/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 00:57:49 by akarafi           #+#    #+#             */
/*   Updated: 2022/05/18 20:29:45 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "colors.h"

void	load_img(t_utils *utils, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(utils->mlx_ptr, \
							path, &img->width, &img->height);
	if (!img->img)
	{
		printf("%sInvalid XPM File%s\n", RED, RESET);
		free_data(utils->data);
		exit(0);
	}
	img->data = (int *) mlx_get_data_addr(img->img, \
							&img->bpp, &img->sl, &img->endian);
}

void	load_textures(t_utils *utils)
{
	load_img(utils, utils->data->north_texture, &utils->no);
	load_img(utils, utils->data->south_texture, &utils->so);
	load_img(utils, utils->data->west_texture, &utils->we);
	load_img(utils, utils->data->east_texture, &utils->ea);
}
