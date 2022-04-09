/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:10:32 by akarafi           #+#    #+#             */
/*   Updated: 2022/04/09 19:50:57 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "colors.h"

void	checkleaks(void)
{
	system("leaks cube3D");
}

int	main(int ac, char **av)
{	
	int		error;
	t_data	*data;

	atexit(checkleaks);
	if (ac != 2)
		return (printf("%sInvalid number of args%s\n", RED, RESET), 0);
	error = 0;
	data = get_data(av[1], &error);
	if (error)
	{
		// todo...
		printf("An error have been occured %d\n", error);
		free(data);
		return (0);
	}
	free(data);
}
