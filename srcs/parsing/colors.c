/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 05:39:39 by ayoub             #+#    #+#             */
/*   Updated: 2022/04/10 18:25:41 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	_init(t_data *data)
{
	data->floor_color.r = -1;
	data->floor_color.g = -1;
	data->floor_color.b = -1;
	data->ceil_color.r = -1;
	data->ceil_color.g = -1;
	data->ceil_color.b = -1;
}

static void	get_color_of(int id, char *value, t_data *data, int *error)
{
	//t_color	color;

	// get color from value and write it to its place
	(void) id, (void) value, (void) data, (void) error;
}

void	get_colors(t_list *lst, t_data *data, int *error)
{
	int		id;
	char	*value;

	_init(data);
	while (lst && !*error)
	{
		id = get_identifier(lst->content, &value);
		if ((id == F && data->floor_color.r != -1)
			|| (id == C && data->ceil_color.r != -1))
			*error = DUPLICATED_DATA_ERR;
		if (id == -1 || *error)
			break ;
		if (id == F || id == C)
			get_color_of(id, value, data, error);
		lst = lst->next;
	}
	if (!*error && (data->ceil_color.r == -1 || data->floor_color.r == -1))
		*error = MISSING_DATA_ERR;
}
