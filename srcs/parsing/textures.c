/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:51:13 by akarafi           #+#    #+#             */
/*   Updated: 2022/04/10 05:47:08 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static char	*duplicat(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	tmp = malloc(i + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

static void	check_and_get_data(t_list *lst, t_dir *directons, int *error)
{
	int		id;
	char	*value;

	while (lst && !*error)
	{
		id = get_identifier(lst->content, &value);
		if ((id == SO && directons->south) || (id == NO && directons->north)
			|| (id == WE && directons->west) || (id == EA && directons->east))
			*error = DUPLICATED_DATA_ERR;
		if (id == -1 || *error)
			break ;
		value = duplicat(value);
		if (!value)
			*error = ALLOCATION_ERR;
		else if (id == SO)
			directons->south = value;
		else if (id == NO)
			directons->north = value;
		else if (id == WE)
			directons->west = value;
		else if (id == EA)
			directons->east = value;
		lst = lst->next;
	}
}

char	*get_texture(t_list *lst, int direction, int *error)
{
	static t_dir	directions;

	if (*error)
		return (NULL);
	if (direction == NO && directions.north)
		return (directions.north);
	if (direction == SO && directions.south)
		return (directions.south);
	if (direction == WE && directions.west)
		return (directions.west);
	if (direction == EA && directions.east)
		return (directions.east);
	check_and_get_data(lst, &directions, error);
	if (!*error && (!directions.north || !directions.south
			|| !directions.west || !directions.east))
		(*error) = MISSING_DATA_ERR;
	return (get_texture(lst, direction, error));
}
