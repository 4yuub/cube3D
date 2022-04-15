/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:27:11 by ayoub             #+#    #+#             */
/*   Updated: 2022/04/15 04:32:33 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	init_columns(t_data *data, int *error)
{
	int	i;
	int	j;

	if (*error)
		return ;
	i = -1;
	while (!*error && ++i < data->height)
	{
		data->map[i] = malloc(data->width * sizeof(int8_t));
		if (!data->map[i])
			*error = ALLOCATION_ERR;
		else
		{
			j = -1;
			while (++j < data->width)
				data->map[i][j] = SPACE;
		}
	}
}

void	get_map(t_list *lst, t_data *data, int *error)
{
	int	i;

	data->height = 0;
	data->width = 0;
	if (*error)
		return ;
	while (lst && ++data->height)
	{
		i = 0;
		while (lst->content[i] && lst->content[i] != '\n')
			i++;
		if (i > data->width)
			data->width = i;
		lst = lst->next;
	}
	data->map = malloc(data->height * sizeof(int8_t *));
	if (!data->map)
		*error = ALLOCATION_ERR;
	init_columns(data, error);
	//fill_map(data->map, lst, error);
	//validate_map(data->map, error);
}
