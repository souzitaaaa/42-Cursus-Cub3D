#include "../includes/cub3d.h"

void draw_line(t_game *game, int hitSide, double wallX)
{
	int y = 0;
	int	textureX = 0;
	textureX = (int)(wallX * (double)TEXTURE_X);
	if ((hitSide == 0 || hitSide == 1) && game->ray.rayDir.x > 0)
		textureX = TEXTURE_X - textureX - 1;
	if ((hitSide == 2 || hitSide == 3) && game->ray.rayDir.y < 0)
		textureX = TEXTURE_X - textureX - 1;
	double step = 1.0 * TEXTURE_X / game->ray.wallLineSize;
	printf(YELLOW "linestart: %f\n" RESET, game->ray.lineStartY);
	printf("Step Math: %f\n", 1.0 * 64 / game->ray.wallLineSize);
	printf("wallLineStart: %f\n", game->ray.wallLineSize);
	double texturePos = (game->ray.lineStartY - SCREEN_Y / 2 + game->ray.wallLineSize / 2) * step;
	printf("Math1: %f\n", game->ray.lineStartY - SCREEN_Y / 2);
	printf("Math2: %f\n", game->ray.wallLineSize / 2);
	printf("step: %f\n", step);
	printf("texturePos: %f\n", texturePos);
	//usleep(99999999);
	while (y < game->ray.lineStartY) {
		game->data.addr[y * SCREEN_X + game->ray.screen_pixel] = CEILING_COLOR;
		y++;
	}
	int textureY = 0;
	unsigned int color = 0;
	while (y < game->ray.lineEndY) {
		color = 0;
		textureY = (int)texturePos & (TEXTURE_X - 1);
		texturePos += step;
		if (hitSide == 0){
			game->data.addr[y * SCREEN_X + game->ray.screen_pixel] = COLOR1;
		}
		else if (hitSide == 1)
			game->data.addr[y * SCREEN_X + game->ray.screen_pixel] = COLOR2;
	 	else if (hitSide == 2) {
			color = game->texture.N_addr[TEXTURE_X * textureY + textureX];
			game->data.addr[y * SCREEN_X + game->ray.screen_pixel] = color;
		}
			//game->data.addr[y * SCREEN_X + game->ray.screen_pixel] = COLOR3;
	 	else if (hitSide == 3)
			game->data.addr[y * SCREEN_X + game->ray.screen_pixel] = COLOR4;
		y++;
	}
	while (y <= SCREEN_Y) {
		game->data.addr[y * SCREEN_X + game->ray.screen_pixel] = FLOOR_COLOR;
		y++;
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
			if (game->ray.step.x == -1)
				hitSide = 0;
			else
				hitSide = 1;
		}
		else
		{
			y += game->ray.step.y;
			lineSizeY += game->ray.deltaDistY;
			if (game->ray.step.y == -1)
				hitSide = 2;
			else
				hitSide = 3;
		}
		if (game->map.map_a[(int)y][(int)x] == '1')
		{
			hit = true;
		}
	}
	//printf("hitWall\t\t| col(y): %i\t\t| row(x): %i\t\t|\n", (int)y, (int)x);
	//printf("hitSide\t\t| %i\t\t\t|\n", hitSide);
	if (hitSide == 0 || hitSide == 1)
		perpendicularDist = fabs(x - game->pos.row + ((1 - game->ray.step.x) / 2)) / game->ray.rayDir.x;
		//perpendicularDist = game->ray.distTo.y - game->ray.deltaDistY; 
	else
		perpendicularDist = fabs(y - game->pos.col + ((1 - game->ray.step.y) / 2)) / game->ray.rayDir.y;
		//perpendicularDist = game->ray.distTo.x - game->ray.deltaDistX; 
	//printf("perpendicularD\t| %f\t\t|\n", perpendicularDist);
	game->ray.wallLineSize = fabs(SCREEN_Y / perpendicularDist);
	//printf("wallLineSize\t| %f\t|\n", game->ray.wallLineSize);
	game->ray.lineStartY = -game->ray.wallLineSize / 2 + SCREEN_Y / 2;
	if (game->ray.lineStartY < 0)
		game->ray.lineStartY = 0;
	game->ray.lineEndY = game->ray.wallLineSize / 2 + SCREEN_Y / 2;
	if (game->ray.lineEndY >= SCREEN_Y)
		game->ray.lineEndY = SCREEN_Y - 1;
	double wallX;
	if (hitSide == 0 || hitSide == 1)
		wallX = game->pos.row + perpendicularDist * game->ray.rayDir.x;
	else
		wallX = game->pos.col + perpendicularDist * game->ray.rayDir.y;
	wallX -= floor(wallX);
	draw_line(game, hitSide, wallX);
}