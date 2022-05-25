/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:06:14 by akarafi           #+#    #+#             */
/*   Updated: 2022/05/25 01:09:03 by akarafi          ###   ########.fr       */
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
# define ALLOCATION_ERR      1U
# define OPEN_FILE_ERR       2U
# define MISSING_DATA_ERR    4U
# define DUPLICATED_DATA_ERR 8U
# define INVALID_DATA_ERR    16U
# define INVALID_MAP_ERR     32U
# define FILE_EXTENTION_ERR  64U
// end error numbers

// directions && ids
# define NO 1U
# define SO 2U
# define WE 3U
# define EA 4U
# define F	5U
# define C	6U
// end directions && ids

// map objs
# define EMPTY  0U
# define WALL   1U
# define SPACE  2U
# define PLAYER 4U
// end map objs

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
	int			width;
	int			height;
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
void	validate_map(t_data *data, int *error);
bool	_strcmp(char *start, char *end, char *str);
// end parsing

// rendring
# define PI 3.141592f
# define WIDTH 1920
# define HEIGHT 1080
# define MINI_WIDTH 384
# define MINI_HEIGHT 216

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_vector_i
{
	int	x;
	int	y;
}	t_vector_i;

typedef struct s_img
{
	int		width;
	int		height;
	int		*data;
	void	*img;
	int		bpp;
	int		sl;
	int		endian;
	int		c;
	int		f;
}	t_img;

typedef struct s_utils
{
	t_vector	pos;
	t_vector	dir;
	t_vector	camera_plane;
	t_vector	ray_dir;
	t_vector_i	step;
	t_vector_i	map;
	t_vector	dist;
	t_vector	new_dist;
	int			side;
	int			color;
	t_data		*data;
	void		*mlx_ptr;
	void		*mlx_win;
	t_img		*texture;
	t_img		no;
	t_img		so;
	t_img		ea;
	t_img		we;
	t_img		screen;
	t_img		minimap;
	double		_step;
	double		tex_pos;
	int			tex_x;
	int			tex_y;
	int			old_mouse;
}	t_utils;

void	render(t_data *data);
int		event_listener(int key, t_utils *utils);
int		raycaster(t_utils *utils);
void	dda_algorithm(t_utils *utils);
void	load_textures(t_utils *utils);
void	draw_minimap(t_utils *utils);
int		mouse_event(int x, int y, t_utils *uitils);
// end rendring

// key macros
# define KEY_A 0
# define KEY_D 2
# define KEY_S 1
# define KEY_W 13

# define KEY_AR_L 123
# define KEY_AR_R 124
# define KEY_AR_U 126
# define KEY_AR_D 125

# define KEY_ESC 53
// end key macros

#endif