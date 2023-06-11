#include "sample.h"

uint32_t	get_color(t_data *img, int x, int y)
{
	return (*(uint32_t*)(img->addr +
		(y * img->line_length + x * (img->bits_per_pixel / 8))));
}

t_data	*img_init(t_vars *vars, char *relative_path)
{
	t_data	*read_img;
	int		read_img_width;
	int		read_img_height;

	read_img = (t_data *)malloc(sizeof(t_data));
	if (read_img == NULL)
		exit(EXIT_FAILURE);
	read_img->img = mlx_xpm_file_to_image(vars->mlx, \
	relative_path, &read_img_width, &read_img_height);
	if (read_img->img == NULL)
		exit(EXIT_FAILURE);
	read_img->addr = mlx_get_data_addr(read_img->img, &read_img->bits_per_pixel,
		&read_img->line_length, &read_img->endian);
	if (read_img->addr == NULL)
		exit(EXIT_FAILURE);
	return (read_img);
}

void	window_reflesh(t_vars *vars, int width, int height)
{
	t_data	black_img;

	black_img.img = mlx_new_image(vars->mlx, width, height);
	black_img.addr = mlx_get_data_addr(black_img.img, \
	&black_img.bits_per_pixel, &black_img.line_length, &black_img.endian);
	mlx_put_image_to_window(vars->mlx, \
	vars->win, black_img.img, 0, 0);
}

int	render_next_frame(t_vars *vars)
{
  window_reflesh(vars, screenWidth, screenHeight);
//   t_data *img = img_init(vars, "./ghost.xpm");
  t_data *img;
  raycasting(vars, img);
  return (SUCCESS);
}

int main(void)
{
	t_vars *vars;
	vars = (t_vars *)malloc(sizeof(t_vars));

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, screenWidth, screenHeight, "so_long");
	t_data *img = img_init(vars, "./ghost.xpm");
	uint32_t tmp = get_color(img, 10, 10);

	printf("%x\n", tmp);

	raycasting(vars, img);
	mlx_loop_hook(vars->mlx, render_next_frame, vars);
	mlx_hook(vars->win, 2, 1L << 0, key_handle, vars);
	// mlx_hook(vars->win, 17, 0L, x_click_handle, vars);
	mlx_loop(vars->mlx);
}