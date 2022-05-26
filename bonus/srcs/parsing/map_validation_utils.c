/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 08:28:29 by ayoub             #+#    #+#             */
/*   Updated: 2022/04/16 08:29:58 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static bool	space_wall(int8_t c)
{
	return (c == SPACE || c == WALL);
}

bool	surrounded_by_walls(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
		{
			if ((data->map[i][j] == SPACE)
				&& ((i - 1 >= 0 && !space_wall(data->map[i - 1][j]))
					|| (i + 1 < data->height
						&& !space_wall(data->map[i + 1][j]))
					|| (j - 1 >= 0 && !space_wall(data->map[i][j - 1]))
					|| (j + 1 < data->width
						&& !space_wall(data->map[i][j + 1]))
				))
				return (false);
		}
	}
	return (true);
}

// first_line and last line only contains walls or spaces
bool	only_walls(t_data *data)
{
	bool	first_line;
	bool	last_line;
	int8_t	*line;
	int8_t	*line2;
	int		i;

	first_line = false;
	last_line = false;
	line = data->map[0];
	line2 = data->map[data->height - 1];
	i = -1;
	while (++i < data->width)
	{
		if ((line[i] != SPACE && line[i] != WALL)
			|| (line2[i] != SPACE && line2[i] != WALL))
			return (false);
		if (line[i] == WALL)
			first_line = true;
		if (line2[i] == WALL)
			last_line = true;
	}
	return (first_line && last_line);
}

// first and last should be one or space in each line
bool	first_and_last(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	j = data->width - 1;
	while (++i < data->height)
		if ((data->map[i][0] != SPACE && data->map[i][0] != WALL)
			|| ((data->map[i][j] != SPACE && data->map[i][j] != WALL)))
			return (false);
	return (true);
}
