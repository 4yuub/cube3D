/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:34:04 by akarafi           #+#    #+#             */
/*   Updated: 2022/04/11 18:45:39 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	free_data(t_data *data)
{
	free(data->east_texture);
	free(data->west_texture);
	free(data->north_texture);
	free(data->south_texture);
	free(data);
}
