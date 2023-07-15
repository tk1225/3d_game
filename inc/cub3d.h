/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:49:39 by takumasaoka       #+#    #+#             */
/*   Updated: 2023/07/15 14:11:23 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include "../lib/gnl/get_next_line.h"
# include "../lib/libft/libft.h"

# define SUCCESS 1
# define ERROR 0

// ----------------------------------------
// map info
// ----------------------------------------
# define MAX_MAP_COL	50
# define MAX_MAP_ROW	50
# define MOVE_SPEED 	1
# define ROT_SPEED 		0.5
# define MAX_FILE_COL	100
# define MAX_FILE_ROW	100
# define NORTH			0
# define SOUTH			1
# define EAST			2
# define WEST			3
# define MAP_WIDTH		24
# define MAP_HEIGHT		24
# define SCREEN_WIDTH	640
# define SCREEN_HEIGHT	480
# define TEX_WIDTH		32
# define TEX_HEIGHT		32
# define PITCH			100

// ----------------------------------------
// key code
// ----------------------------------------
# define ESC_KEY		53
# define LEFT_KEY		123
# define RIGHT_KEY		124
# define DOWN_KEY		125
# define UP_KEY			126
# define W_KEY			13
# define A_KEY			0
# define S_KEY			1
# define D_KEY			2
# define SPACE_KEY		49
# define ESC_KEY_M1		65307
# define LEFT_KEY_M1	65361
# define RIGHT_KEY_M1	65363
# define DOWN_KEY_M1	65364
# define UP_KEY_M1		65362
# define X_KEY_PRESS	2
# define X_KEY_EXIT		17

// ----------------------------------------
// ERROR
// ----------------------------------------
// file
# define ERROR_ARGS			"not args 2"
# define ERROR_FILE			"not exist file"
# define ERROR_CUB			"not cub file"
# define ERROR_FORMAT		"bad file format"

// map
# define ERROR_BIG_MAP		"map too big"
# define ERROR_SMALL_MAP		"map too small"
# define ERROR_MAP_VALUE	"Illegal value in map"
# define ERROR_INIT_POINT	"not one start point"
# define ERROR_NOT_SURROND	"not surrounded by walls"

// system
# define ERROR_MALLOC	"error malloc"
# define ERROR_READ		"error read"

typedef struct s_vars		t_vars;
typedef struct s_data		t_data;
typedef struct s_map		t_map;
typedef struct s_file_data	t_file_data;

struct s_vars
{
	void		*mlx;
	void		*win;
	t_map		*map;
	int			draw_start;
	int			draw_end;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	int			direction;
	double		delta_x;
	double		delta_y;
	double		side_dist_x;
	double		side_dist_y;
	int			step_x;
	int			step_y;
	uint32_t	**img_north;
	uint32_t	**img_south;
	uint32_t	**img_east;
	uint32_t	**img_west;
};

struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct s_file_data
{
	int		fd;
	char	*file_path;
	char	**line;
	int		col;
	int		row;
	int		row_map_start;
	char	*texture_no;
	char	*texture_so;
	char	*texture_we;
	char	*texture_ea;
	int		floor_rgb[3];
	int		ceiling_rgb[3];
};

struct s_map
{
	t_file_data	*file_data;
	char		**line;
	int			row;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
};

void		initialized(t_vars *vars, char *map_path);
void		raycasting(t_vars *vars);
int			key_handle(int keycode, t_vars *vars);
int			input_file(t_map *map, char *file_path);
void		setting_element(t_file_data *file_data);
void		set_map(t_map *map, t_file_data *file_data);
void		exit_error(const char *message);
void		check_pre(int argc, char **argv);
void		check_map(t_map *map);
void		check_wall(t_map *map);
bool		check_start_point(char p);
void		draw(t_vars *vars, int x, int direction);
int			key_handle(int keycode, t_vars *vars);
void		calculate_vars(t_vars *vars, int x);
void		calculate_side_dist(t_vars *vars, double deltaDistX,
				double deltaDistY);
void		calculate_wall_dist(t_vars *vars, double deltaDistX,
				double deltaDistY);
void		free_array(char **array);
void		free_line(char **line, int row);
int			end_cub3d(t_vars *vars);
uint32_t	get_color(t_data *img, int x, int y);
t_data		*img_init(t_vars *vars, char *relative_path);
void		vars_img_init(t_vars *vars, char *path, u_int32_t **img);

#endif
