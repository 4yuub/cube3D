/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:27:11 by ayoub             #+#    #+#             */
/*   Updated: 2022/05/26 03:00:17 by akarafi          ###   ########.fr       */
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

static void	fill_map(t_data *data, t_list *lst)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->height && lst)
	{
		j = 0;
		while (lst->content[j] != '\n' && lst->content[j])
		{
			if (lst->content[j] == '1')
				data->map[i][j] = WALL;
			else if (lst->content[j] == '0')
				data->map[i][j] = EMPTY;
			else if (lst->content[j] == 'D')
				data->map[i][j] = DOOR;
			else if (lst->content[j] == ' ')
				;
			else
				data->map[i][j] = lst->content[j];
			j++;
		}
		lst = lst->next;
	}
}

void	get_map(t_list *lst, t_data *data, int *error)
{
	int		i;
	t_list	*head;

	data->height = 0;
	data->width = 0;
	if (*error)
		return ;
	head = lst;
	while (lst && ++(data->height))
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
	fill_map(data, head);
	validate_map(data, error);
}
