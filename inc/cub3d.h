/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumasaokamoto <takumasaokamoto@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:49:39 by takumasaoka       #+#    #+#             */
/*   Updated: 2023/07/05 01:20:16 by takumasaoka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cub3d_H
# define cub3d_H

#include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include "../lib/gnl/get_next_line.h"
# include "../lib/libft/libft.h"

#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define TEX_WIDTH 32
#define TEX_HEIGHT 32
#define PITCH 100

#define SUCCESS 1
#define ERROR 0
#define ESC_KEY 53
#define LEFT_KEY 123
#define RIGHT_KEY 124
#define DOWN_KEY 125
#define UP_KEY 126
#define SPACE_KEY 49
#define ESC_KEY_M1 65307
#define LEFT_KEY_M1 65361
#define RIGHT_KEY_M1 65363
#define DOWN_KEY_M1 65364
#define UP_KEY_M1 65362
#define MAX_MAP_COL	50
#define MAX_MAP_ROW	50

# define MOVE_SPEED 1
# define ROT_SPEED 0.5

# define MAX_FILE_COL 100
# define MAX_FILE_ROW 100

# define NORTH	0
# define SOUTH	1
# define EAST	2
# define WEST	3

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


typedef struct s_vars t_vars;
typedef struct s_data t_data;
typedef struct s_map t_map;
typedef struct s_file_data t_file_data;

struct s_vars
{
	void	*mlx;
	void	*win;
	t_map	*map;
	int drawStart;
	int drawEnd;
	int texX;
	int texY;
	double step;
	double texPos;
	int texNum;
	double ray_dir_x;
	double ray_dir_y;
	int map_x;
	int map_y;
	int direction;
	double side_dist_x;
	double side_dist_y;
	uint32_t **img_north;
	uint32_t **img_south;
	uint32_t **img_east;
	uint32_t **img_west;
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
	int fd;
	char *file_path;
	char **line;
	int col;
	int row;
	int row_map_start;
	char *texture_no;
	char *texture_so;
	char *texture_we;
	char *texture_ea;
	int  floor_rgb[3];
	int  ceiling_rgb[3];
};

struct s_map
{
	t_file_data *file_data;
	char **line;
	int row;
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
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
void 		check_wall(t_map *map);
bool		check_start_point(char p);

void 		free_array(char **array);
void		free_line(char **line, int row);

uint32_t	get_color(t_data *img, int x, int y);
t_data		*img_init(t_vars *vars, char *relative_path);
void vars_img_init(t_vars *vars, char *path, u_int32_t **img);

#endif
