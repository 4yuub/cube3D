/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 00:35:20 by akarafi           #+#    #+#             */
/*   Updated: 2022/05/16 15:09:23 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	__exit(t_data *data)
{
	free_data(data);
	exit(0);
	return (0);
}

int	event_listener(int key, t_utils *utils)
{
	if (key == KEY_ESC)
		__exit(utils->data);
	return (0);
}
