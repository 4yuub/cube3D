/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 04:49:17 by akarafi           #+#    #+#             */
/*   Updated: 2022/05/26 05:13:41 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	load_img(t_utils *utils, char *path, t_img *img);

void	load_torch(t_utils *utils)
{
	load_img(utils, "./assets/torch/1.xpm", &utils->torch[0]);
	load_img(utils, "./assets/torch/2.xpm", &utils->torch[1]);
	load_img(utils, "./assets/torch/3.xpm", &utils->torch[2]);
	load_img(utils, "./assets/torch/4.xpm", &utils->torch[3]);
	load_img(utils, "./assets/torch/5.xpm", &utils->torch[4]);
	load_img(utils, "./assets/torch/6.xpm", &utils->torch[5]);
	load_img(utils, "./assets/torch/7.xpm", &utils->torch[6]);
	load_img(utils, "./assets/torch/8.xpm", &utils->torch[7]);
	load_img(utils, "./assets/torch/9.xpm", &utils->torch[8]);
	load_img(utils, "./assets/torch/10.xpm", &utils->torch[9]);
	load_img(utils, "./assets/torch/11.xpm", &utils->torch[10]);
	load_img(utils, "./assets/torch/12.xpm", &utils->torch[11]);
	load_img(utils, "./assets/torch/13.xpm", &utils->torch[12]);
	load_img(utils, "./assets/torch/14.xpm", &utils->torch[13]);
	load_img(utils, "./assets/torch/15.xpm", &utils->torch[14]);
	load_img(utils, "./assets/torch/16.xpm", &utils->torch[15]);
	load_img(utils, "./assets/torch/17.xpm", &utils->torch[16]);
	load_img(utils, "./assets/torch/18.xpm", &utils->torch[17]);
	load_img(utils, "./assets/torch/19.xpm", &utils->torch[18]);
	load_img(utils, "./assets/torch/20.xpm", &utils->torch[19]);
	load_img(utils, "./assets/torch/21.xpm", &utils->torch[20]);
	load_img(utils, "./assets/torch/22.xpm", &utils->torch[21]);
	load_img(utils, "./assets/torch/23.xpm", &utils->torch[22]);
}
