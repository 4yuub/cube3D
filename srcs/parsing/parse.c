/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:18:13 by akarafi           #+#    #+#             */
/*   Updated: 2022/04/14 05:11:20 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "../gnl/get_next_line.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (!*lst)
		*lst = new;
	else
	{
		head = *lst;
		while (head->next)
			head = head->next;
		head->next = new;
	}
}

t_list	*get_lst(int fd, int *error)
{
	char	*line;
	t_list	*lst;
	t_list	*node;

	lst = NULL;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		node = malloc(sizeof(t_list));
		if (!node)
			return (*error = ALLOCATION_ERR, lst);
		node->content = line;
		node->next = NULL;
		ft_lstadd_back(&lst, node);
	}
	return (lst);
}

static void	init_data(t_data *data)
{
	data->ceil_color.r = -1;
	data->ceil_color.g = -1;
	data->ceil_color.b = -1;
	data->floor_color.r = -1;
	data->floor_color.g = -1;
	data->floor_color.b = -1;
	data->palyer_position.x = -1;
	data->palyer_position.y = -1;
	data->palyer_position.direction = 0;
	data->north_texture = NULL;
	data->south_texture = NULL;
	data->west_texture = NULL;
	data->east_texture = NULL;
	data->map = NULL;
}

t_data	*get_data(char *filename, int *error)
{
	int		fd;
	t_data	*data;
	t_list	*lst;
	t_list	*first_line_in_map;

	data = malloc(sizeof(t_data));
	if (!data)
		return (*error = ALLOCATION_ERR, NULL);
	init_data(data);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (*error = OPEN_FILE_ERR, data);
	lst = get_lst(fd, error);
	if (!lst || *error)
		return (free_list(lst), close(fd), data);
	data->north_texture = get_texture(lst, NO, error);
	data->south_texture = get_texture(lst, SO, error);
	data->west_texture = get_texture(lst, WE, error);
	data->east_texture = get_texture(lst, EA, error);
	first_line_in_map = get_colors(lst, data, error);
	get_map(first_line_in_map, data, error);
	return (free_list(lst), close(fd), data);
}
