/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 05:39:39 by ayoub             #+#    #+#             */
/*   Updated: 2022/04/10 22:04:49 by akarafi          ###   ########.fr       */
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
	t_color	*c;
	int		n;

	if (id == F)
		c = &data->floor_color;
	else if (id == C)
		c = &data->ceil_color;
	n = 0;
	while (!*error && *value)
	{
		if (*value == ',' || *value == '\n')
		{
			if (c->r == -1)
				c->r = n;
			else if (c->g == -1)
				c->g = n;
			else if (c->b == -1)
				c->b = n;
			else
				*error = INVALID_DATA_ERR;
			value++;
			n = 0;
			continue ;
		}
		if (*value < '0' || *value > '9')
			*error = INVALID_DATA_ERR;
		n = (n * 10) + (*value - '0');
		value++;
	}
}

void	get_colors(t_list *lst, t_data *data, int *error)
{
	int		id;
	char	*value;

	_init(data);
	while (lst && !*error)
	{
		id = get_identifier(lst->content, &value);
		if ((id == F && data->floor_color.b != -1)
			|| (id == C && data->ceil_color.b != -1))
			*error = DUPLICATED_DATA_ERR;
		if (id == -1 || *error)
			break ;
		if (id == F || id == C)
			get_color_of(id, value, data, error);
		lst = lst->next;
	}
	if (!*error && (data->ceil_color.b == -1 || data->floor_color.b == -1))
		*error = MISSING_DATA_ERR;
}
