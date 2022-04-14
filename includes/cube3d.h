/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:06:14 by akarafi           #+#    #+#             */
/*   Updated: 2022/04/14 05:10:47 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include <stdio.h>
//# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

// error numbers:
# define ALLOCATION_ERR 1U
# define OPEN_FILE_ERR 2U
# define MISSING_DATA_ERR 4U
# define DUPLICATED_DATA_ERR 8U
# define INVALID_DATA_ERR 16U
// end error numbers

// directions && ids
# define NO 1U
# define SO 2U
# define WE 3U
# define EA 4U
# define F	5U
# define C	6U
// end directions && ids

// parsing:
typedef struct s_list
{
	char	*content;
	void	*next;
}	t_list;

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

typedef struct s_dir
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_dir;

// free utils:
void	free_list(t_list *lst);
void	free_data(t_data *data);
// end free utils

t_data	*get_data(char *filename, int *error);
char	*get_texture(t_list *lst, int direction, int *error);
int		get_identifier(char *line, char **ptr);
t_list	*get_colors(t_list *lst, t_data *data, int *error);
void	get_map(t_list *lst, t_data *data, int *error);
// end parsing

#endif