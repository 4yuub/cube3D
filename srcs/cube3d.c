/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:10:32 by akarafi           #+#    #+#             */
/*   Updated: 2022/04/17 17:27:54 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "colors.h"

const char	*str_error(int error)
{
	if (error == ALLOCATION_ERR)
		return ("Allocation failed");
	if (error == OPEN_FILE_ERR)
		return ("Can't open file");
	if (error == MISSING_DATA_ERR)
		return ("Data isn't completed");
	if (error == INVALID_DATA_ERR)
		return ("Invalide data");
	if (error == INVALID_MAP_ERR)
		return ("Invalde map");
	if (error == FILE_EXTENTION_ERR)
		return ("Invalde file extention");
	return ("Undefined error");
}

int	_strlen(char *s)
{
	int	l;

	l = 0;
	while (l[s])
		l++;
	return (l);
}

int	main(int ac, char **av)
{	
	int		error;
	int		len;
	t_data	*data;

	if (ac != 2)
		return (printf("%sInvalid number of args%s\n", RED, RESET), 0);
	error = 0;
	len = _strlen(av[1]);
	if (len < 4 || !_strcmp(av[1] + len - 4, av[1] + len, ".cub"))
		error = FILE_EXTENTION_ERR;
	else
		data = get_data(av[1], &error);
	if (error)
	{
		printf("An error have been occured: %s\n", str_error(error));
		free_data(data);
		return (0);
	}
	free_data(data);
}
