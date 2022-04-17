/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:10:32 by akarafi           #+#    #+#             */
/*   Updated: 2022/04/17 16:46:42 by akarafi          ###   ########.fr       */
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
	if (INVALID_MAP_ERR)
		return ("Invalde map");
	return ("Undefined error");
}

int	main(int ac, char **av)
{	
	int		error;
	t_data	*data;

	if (ac != 2)
		return (printf("%sInvalid number of args%s\n", RED, RESET), 0);
	error = 0;
	data = get_data(av[1], &error);
	if (error)
	{
		printf("An error have been occured: %s\n", str_error(error));
		free_data(data);
		return (0);
	}
	free_data(data);
}
