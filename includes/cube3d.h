/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:06:14 by akarafi           #+#    #+#             */
/*   Updated: 2022/04/06 02:48:41 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

// error numbers:
# define ALLOCATION_ERR 1U
# define OPEN_FILE_ERR 2U
// end error numbers

// directions
# define NO 1U
# define SO 2U
# define WE 3U
# define EA 4U
// end directions


// parsing:
typedef struct s_list
{
	char	*content;
	void	*next;
}	t_list;
// free utils:
void	free_list(t_list *lst);
// end free utils

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_position
{
	double	x;
	double	y;
	int		direction;
}	t_position;

typedef struct s_data
{
	int8_t		**map;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	t_color		floor_color;
	t_color		ceil_color;
	t_position	palyer_position;
}	t_data;

t_data	*get_data(char *filename, int *error);

// end parsing

#endif