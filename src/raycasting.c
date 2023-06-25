#include "cub3d.h"

int rgbToHex(int red, int green, int blue) {
    int hexCode = (red << 16) | (green << 8) | blue;
    return hexCode;
}

uint32_t tmpimg[32][32]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,0,0,3,0,0,0,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int	key_handle(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	if (keycode == LEFT_KEY || keycode == LEFT_KEY_M1)
    {
      double oldDirX = vars->map->dirX;
      vars->map->dirX = vars->map->dirX * cos(ROT_SPEED) - vars->map->dirY * sin(ROT_SPEED);
      vars->map->dirY = oldDirX * sin(ROT_SPEED) + vars->map->dirY * cos(ROT_SPEED);
      double oldPlaneX = vars->map->planeX;
      vars->map->planeX = vars->map->planeX * cos(ROT_SPEED) - vars->map->planeY * sin(ROT_SPEED);
      vars->map->planeY = oldPlaneX * sin(ROT_SPEED) + vars->map->planeY * cos(ROT_SPEED);
    }
	else if (keycode == RIGHT_KEY || keycode == RIGHT_KEY_M1)
	{
      double oldDirX = vars->map->dirX;
      vars->map->dirX = vars->map->dirX * cos(-ROT_SPEED) - vars->map->dirY * sin(-ROT_SPEED);
      vars->map->dirY = oldDirX * sin(-ROT_SPEED) + vars->map->dirY * cos(-ROT_SPEED);
      double oldPlaneX = vars->map->planeX;
      vars->map->planeX = vars->map->planeX * cos(-ROT_SPEED) - vars->map->planeY * sin(-ROT_SPEED);
      vars->map->planeY = oldPlaneX * sin(-ROT_SPEED) + vars->map->planeY * cos(-ROT_SPEED);
    }
	else if (keycode == DOWN_KEY || keycode == DOWN_KEY_M1)
	{
    if(vars->map->line[(int)(vars->map->posX + vars->map->dirX * MOVE_SPEED)][(int)vars->map->posY] == '0')
      vars->map->posX -= vars->map->dirX * MOVE_SPEED;
    if(vars->map->line[(int)vars->map->posX][(int)(vars->map->posY + vars->map->dirY * MOVE_SPEED)] == '0')
      vars->map->posY -= vars->map->dirY * MOVE_SPEED;
    }
	else if (keycode == UP_KEY || keycode == UP_KEY_M1)
	{
        if(vars->map->line[(int)(vars->map->posX - vars->map->dirX * MOVE_SPEED)][(int)vars->map->posY] == '0')
            vars->map->posX += vars->map->dirX * MOVE_SPEED;
        if(vars->map->line[(int)vars->map->posX][(int)(vars->map->posY - vars->map->dirY * MOVE_SPEED)] == '0')
            vars->map->posY += vars->map->dirY * MOVE_SPEED;
  }
  else if (keycode == ESC_KEY || keycode == ESC_KEY_M1)
	{
		mlx_destroy_window(vars->mlx, vars->win);
    exit(EXIT_SUCCESS);
	}
	return (0);
}

void draw(int drawStart, int drawEnd, t_vars *vars, int x, int texX, int texNum, double step, double texPos)
{
  int ceil = 0;
    while (ceil < drawStart)
    {
      mlx_pixel_put(vars->mlx, vars->win, x, ceil, rgbToHex(0, 255, 0));
      ceil ++;
    }
    while (drawStart < drawEnd)
    {
        int texY = (int)texPos & (texHeight - 1);
        texPos += step;
        int color;
        color = rgbToHex(255, 0, 0);
        (void)texY;
        (void)texX;
        (void)texNum;
        // color = vars->img->n_img[texNum][texHeight * texY + texX];
        // switch(tmpimg[texNum][texHeight * texY + texX])
        // {
        //   case 1:  color = rgbToHex(255, 0, 0);    break; //red
        //   case 2:  color = rgbToHex(0, 255, 0);  break; //green
        //   case 3:  color = rgbToHex(0, 0, 255);   break; //blue
        //   case 4:  color = rgbToHex(0, 255, 0);  break; //white
        //   default: color = rgbToHex(255, 0, 0); break; //yellow
        // }
        mlx_pixel_put(vars->mlx, vars->win, x, drawStart, color);
        drawStart ++;
    }
    while (drawEnd < SCREEN_HEIGHT)
    {
      mlx_pixel_put(vars->mlx, vars->win, x, drawEnd, rgbToHex(0, 255, 0));
      drawEnd ++;
    }
}

void raycasting(t_vars *vars)
{
    for (int x = 0; x < SCREEN_WIDTH; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (double)SCREEN_WIDTH - 1; //x-coordinate in camera space
      double rayDirX = vars->map->dirX + vars->map->planeX * cameraX;
      double rayDirY = vars->map->dirY + vars->map->planeY * cameraX;
      //which box of the map we're in
      int mapX = vars->map->posX;
      int mapY = vars->map->posY;

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

      //length of ray from one x or y-side to next x or y-side
      //these are derived as:
      //deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
      //deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY))
      //which can be simplified to abs(|rayDir| / rayDirX) and abs(|rayDir| / rayDirY)
      //where |rayDir| is the length of the vector (rayDirX, rayDirY). Its length,
      //unlike (dirX, dirY) is not 1, however this does not matter, only the
      //ratio between deltaDistX and deltaDistY matters, due to the way the DDA
      //stepping further below works. So the values can be computed as below.
      //Division through zero is prevented, even though technically that's not
      //needed in C++ with IEEE 754 floating point values.
      double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
      double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?
      //calculate step and initial sideDist
      if(rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (vars->map->posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - vars->map->posX) * deltaDistX;
      }

      if(rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (vars->map->posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - vars->map->posY) * deltaDistY;
      }
      //perform DDA
      while(hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if(sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if(vars->map->line[mapX][mapY] > '0' || vars->map->line[mapX][mapY] == ' ') hit = 1;
      }
      //Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
      //hit to the camera plane. Euclidean to center camera point would give fisheye effect!
      //This can be computed as (mapX - posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
      //for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
      //because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
      //steps, but we subtract deltaDist once because one step more into the wall was taken above.
      if(side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist = (sideDistY - deltaDistY);

      //Calculate height of line to draw on screen
      int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe

      int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2 + PITCH;
      if(drawStart < 0) drawStart = 0;
      int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2 + PITCH;
      if(drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;
      //choose wall color
      int texNum = vars->map->line[mapX][mapY] - 48 - 1;//1 subtracted from it so that texture 0 can be used!
      //calculate value of wallX
      double wallX; //where exactly the wall was hit
      if(side == 0) wallX = vars->map->posY + perpWallDist * rayDirY;
      else          wallX = vars->map->posX + perpWallDist * rayDirX;
      wallX -= floor((wallX));

      //x coordinate on the texture
      int texX = (int)(wallX * (double)(texWidth));
      if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
      if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;

      // TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
      // How much to increase the texture coordinate per screen pixel
      double step = 1.0 * texHeight / lineHeight;
      // Starting texture coordinate
      double texPos = (drawStart - PITCH - SCREEN_HEIGHT / 2 + lineHeight / 2) * step;
      draw(drawStart, drawEnd, vars, x, texX, texNum, step, texPos);
    }
}
