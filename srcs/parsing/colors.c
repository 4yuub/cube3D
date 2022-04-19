/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 05:39:39 by ayoub             #+#    #+#             */
/*   Updated: 2022/04/19 07:26:45 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	get_color_of(char *value, t_color *c, int *error)
{
	int		n;

	n = 0;
	while (!*error && *value)
	{
		if (*value == ',' || *value == '\n')
		{
			if (n == 0 && *(value - 1) != '0')
				*error = INVALID_DATA_ERR;
			else if (c->r == -1 && n <= 255)
				c->r = n;
			else if (c->g == -1 && n <= 255)
				c->g = n;
			else if (c->b == -1 && n <= 255)
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

t_list	*get_colors(t_list *lst, t_data *data, int *error)
{
	int		id;
	char	*value;

	while (lst && !*error)
	{
		id = get_identifier(lst->content, &value);
		if ((id == F && data->floor_color.b != -1)
			|| (id == C && data->ceil_color.b != -1))
			*error = DUPLICATED_DATA_ERR;
		if (id == -1 || *error)
			break ;
		if (id == F)
			get_color_of(value, &data->floor_color, error);
		else if (id == C)
			get_color_of(value, &data->ceil_color, error);
		lst = lst->next;
	}
	if (!*error && (data->ceil_color.b == -1 || data->floor_color.b == -1))
		*error = MISSING_DATA_ERR;
	return (lst);
}
