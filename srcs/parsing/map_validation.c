/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 06:31:49 by ayoub             #+#    #+#             */
/*   Updated: 2022/04/16 08:51:48 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	surrounded_by_walls(t_data *data);
bool	only_walls(t_data *data);
bool	first_and_last(t_data *data);

static bool	is_valid_member(int8_t c)
{
	return (c == SPACE || c == WALL || c == EMPTY
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static bool	is_player(int8_t c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	set_player_details(t_data *data, int y, int x)
{
	int	dir;

	data->palyer_position.x = x;
	data->palyer_position.y = y;
	dir = WE;
	if (data->map[y][x] == 'N')
		dir = NO;
	else if (data->map[y][x] == 'S')
		dir = SO;
	else if (data->map[y][x] == 'E')
		dir = EA;
	data->palyer_position.direction = dir;
	data->map[y][x] = EMPTY;
}

/** find player position
*   in addition to check if there is in valid members in map
*/
static void	get_player_position(t_data *data, int *error)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->height)
		{
			if (!is_valid_member(data->map[i][j]))
			{
				*error = INVALID_MAP_ERR;
				return ;
			}
			if (is_player(data->map[i][j]))
			{
				set_player_details(data, i, j);
				count++;
			}
		}
	}
	if (count != 1)
		*error = INVALID_MAP_ERR;
}

void	validate_map(t_data *data, int *error)
{
	if (*error)
		return ;
	if (!only_walls(data)
		|| !first_and_last(data)
		|| !surrounded_by_walls(data))
		*error = INVALID_MAP_ERR;
	get_player_position(data, error);
}
