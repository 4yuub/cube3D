/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 05:42:13 by ayoub             #+#    #+#             */
/*   Updated: 2022/04/17 17:00:15 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	_strcmp(char *start, char *end, char *str)
{
	char	*it;

	it = start;
	while (it < end && *str)
	{
		if (*str != *it)
			return (false);
		str++;
		it++;
	}
	return (!*str && it == end);
}

int	get_identifier(char *line, char **ptr)
{
	char	*end;

	while (line && *line == ' ')
		line++;
	end = line;
	while (*end && *end != ' ' && *end != '\n')
		end++;
	*ptr = end;
	while (**ptr == ' ' && **ptr)
		(*ptr)++;
	if (_strcmp(line, end, "F"))
		return (F);
	if (_strcmp(line, end, "C"))
		return (C);
	if (_strcmp(line, end, "NO"))
		return (NO);
	if (_strcmp(line, end, "SO"))
		return (SO);
	if (_strcmp(line, end, "WE"))
		return (WE);
	if (_strcmp(line, end, "EA"))
		return (EA);
	if (_strcmp(line, end, ""))
		return (0);
	return (-1);
}
