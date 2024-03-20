#include "../includes/cub3d.h"

void draw_line(t_game *game, int hitSide)
{
	int drawStart = -game->ray.wallLineSize / 2 + SCREEN_Y / 2;
	if (drawStart < 0)
		drawStart = 0;
	else if (drawStart >= SCREEN_Y)
		drawStart = 0;
	int drawEnd = game->ray.wallLineSize / 2 + SCREEN_Y / 2;
	if (drawEnd >= SCREEN_Y)
		drawEnd = SCREEN_Y - 1;
	else if (drawEnd < 0)
		drawEnd = SCREEN_Y;
	//printf("draws |start: %i | end: %i |\n", drawStart, drawEnd);
	//printf("hitSide\t\t| %i\t\t\t|\n", hitSide);
	if (drawStart <= drawEnd)
	{
		int i = drawStart;
		while (i < drawEnd)
		{
			if (hitSide == 1)
			{
				my_mlx_pixel_put(game, (int)game->ray.screen_pixel, (int)i, COLOR);
			}
			else
			{
				my_mlx_pixel_put(game, (int)game->ray.screen_pixel, (int)i, COLOR2);
			}
			i++;
		}
	//printf("i: %i\n", i);
	}
	else {
		int i = drawStart;
		while (i > drawEnd)
		{
			if (hitSide == 1)
			{
				my_mlx_pixel_put(game, (int)game->ray.screen_pixel, (int)i, COLOR);
			}
			else
			{
				my_mlx_pixel_put(game, (int)game->ray.screen_pixel, (int)i, COLOR2);
			}
			i--;
		}
	//printf("i: %i\n", i);
	}
}

/**
 * @brief       This function implements the Digital Differential Analyzer(DDA)
 * 			algorithm, which calculates the intersections of rays with the walls
 * 			in the game map
 * 				@brief //? NOT FINISHED BECAUSE I NEED TO SORT IN STRUCTS
 *
 * @param game  Struct that contains every information on the program
 */
void dda(t_game *game)
{
	bool hit;
	double lineSizeY;
	double lineSizeX;
	int hitSide;
	double perpendicularDist;
	double x = 0;
	double y = 0;

	x = game->ray.mapPos.x;
	y = game->ray.mapPos.y;
	lineSizeY = game->ray.distTo.y;
	lineSizeX = game->ray.distTo.x;
	hit = false;
	hitSide = 0;
	perpendicularDist = 0;
	//! calcula o caminho em que o raio passa até chegar á parede
	while (!hit)
	{
		//printf( YELLOW "LineSize\t| col(y): %f\t| row(x): %f\t|\n" RESET, lineSizeY, lineSizeX);
		//printf("WallMapPos\t| col(y): %f\t| row(x): %f\t|\n", y, x);
		if (lineSizeX < lineSizeY)
		{
			x += game->ray.step.x;
			lineSizeX += game->ray.deltaDistX;
			hitSide = 0;
		}
		else
		{
			y += game->ray.step.y;
			lineSizeY += game->ray.deltaDistY;
			hitSide = 1;
		}
		if (game->map.map_a[(int)y][(int)x] == '1')
		{
			hit = true;
		}
	}
	//printf("hitWall\t\t| col(y): %i\t\t| row(x): %i\t\t|\n", (int)y, (int)x);
	//printf("hitSide\t\t| %i\t\t\t|\n", hitSide);
	if (hitSide == 0)
	{
		perpendicularDist = fabs(x - game->pos.row + ((1 - game->ray.step.x) / 2)) / game->ray.rayDir.x;
	}
	else
	{
		perpendicularDist = fabs(y - game->pos.col + ((1 - game->ray.step.y) / 2)) / game->ray.rayDir.y;
	}
	//printf("perpendicularD\t| %f\t\t|\n", perpendicularDist);
	game->ray.wallLineSize = SCREEN_Y / perpendicularDist;
	game->ray.lineStartY = SCREEN_Y / 2 - game->ray.wallLineSize / 2;
	game->ray.lineEndY = SCREEN_Y / 2 + game->ray.wallLineSize / 2;
	draw_line(game, hitSide);
}