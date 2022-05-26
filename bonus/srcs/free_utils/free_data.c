/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:34:04 by akarafi           #+#    #+#             */
/*   Updated: 2022/04/18 00:46:33 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	free_data(t_data *data)
{
	int	i;

	if (!data)
		return ;
	i = -1;
	while (data->map && ++i < data->height)
		free(data->map[i]);
	free(data->map);
	free(data->east_texture);
	free(data->west_texture);
	free(data->north_texture);
	free(data->south_texture);
	free(data);
}
