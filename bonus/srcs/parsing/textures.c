/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:51:13 by akarafi           #+#    #+#             */
/*   Updated: 2022/04/19 07:31:20 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static char	*duplicat(char *str, int *error)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	tmp = malloc(i + 1);
	if (!tmp)
		return (*error = ALLOCATION_ERR, NULL);
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
		if (id != 0 && (!*value || *value == '\n'))
			*error = INVALID_DATA_ERR;
		else if (id == SO)
			directons->south = duplicat(value, error);
		else if (id == NO)
			directons->north = duplicat(value, error);
		else if (id == WE)
			directons->west = duplicat(value, error);
		else if (id == EA)
			directons->east = duplicat(value, error);
		lst = lst->next;
	}
}

char	*get_texture(t_list *lst, int direction, int *error)
{
	static t_dir	directions;

	if (direction == NO && directions.north)
		return (directions.north);
	if (direction == SO && directions.south)
		return (directions.south);
	if (direction == WE && directions.west)
		return (directions.west);
	if (direction == EA && directions.east)
		return (directions.east);
	if (*error)
		return (NULL);
	check_and_get_data(lst, &directions, error);
	if (!*error && (!directions.north || !directions.south
			|| !directions.west || !directions.east))
		(*error) = MISSING_DATA_ERR;
	return (get_texture(lst, direction, error));
}
