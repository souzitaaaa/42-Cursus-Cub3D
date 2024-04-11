#include "../includes/cub3d.h"

void draw_line(t_game *game, int hitSide, double wallX)
{
	int y = 0;
	int	textureX = 0;
	textureX = (int)(wallX * (double)TEXTURE_X);
			//printf("wallX: %f\n", wallX);
	if ((hitSide == 0 || hitSide == 1) && game->ray.rayDir.x > 0)
		textureX = TEXTURE_X - textureX - 1;
	if ((hitSide == 2 || hitSide == 3) && game->ray.rayDir.y < 0)
		textureX = TEXTURE_X - textureX - 1;
	printf( "textureX\t| %i\t\t\t|\n"  , textureX);
	double step = 1.0 * TEXTURE_X / game->ray.wallLineSizeInt;
	printf( "step\t\t| %f\t\t|\n", step);
			//printf( "linestart: %f\n", game->ray.lineStartY);
			//printf("wallLineSize: %f\n", game->ray.wallLineSize);
	double texturePos = (game->ray.lineStart - SCREEN_Y / 2 + game->ray.wallLineSizeInt / 2) * step;
	printf( "texturePos\t| %f\t\t|\n"  , texturePos);
	while (y < game->ray.lineStart) {
		game->data.addr[y * SCREEN_X + game->ray.screen_pixel] = CEILING_COLOR;
		y++;
	}
	int textureY = 0;
	unsigned int color = 0;
	while (y < game->ray.lineEnd) {
		color = 0;
		textureY = (int)texturePos & (TEXTURE_X - 1);
		texturePos += step;
		if (hitSide == 0){
			color = game->texture.W_addr[TEXTURE_X * textureY + textureX];
			game->data.addr[y * SCREEN_X + game->ray.screen_pixel] = color;		}
		else if (hitSide == 1) {
			color = game->texture.W_addr[TEXTURE_X * textureY + textureX];
			game->data.addr[y * SCREEN_X + game->ray.screen_pixel] = color;
		}
	 	else if (hitSide == 2) {
			color = game->texture.N_addr[TEXTURE_X * textureY + textureX];
			game->data.addr[y * SCREEN_X + game->ray.screen_pixel] = color;
		}
			//game->data.addr[y * SCREEN_X + game->ray.screen_pixel] = COLOR3;
	 	else if (hitSide == 3)
			game->data.addr[y * SCREEN_X + game->ray.screen_pixel] = 0x00FFC0CB;
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
	int hitSide;
	double perpendicularDist;

	hit = false;
	hitSide = 0;
	perpendicularDist = 0;
	while (!hit)
	{
		if (game->ray.distTo.x < game->ray.distTo.y)
		{
			game->ray.distTo.x += game->ray.deltaDist.x;
			game->ray.mapPos.x += game->ray.step.x;
			if (game->ray.step.x == -1)
				hitSide = 0;
			else
				hitSide = 1;
		}
		else
		{
			game->ray.distTo.y += game->ray.deltaDist.y;
			game->ray.mapPos.y += game->ray.step.y;
			if (game->ray.step.y == -1)
				hitSide = 2;
			else
				hitSide = 3;
		}
		if (game->map.map_a[(int)game->ray.mapPos.y][(int)game->ray.mapPos.x] == '1')
			hit = true;
	}
	if (hitSide == 0 || hitSide == 1)
		perpendicularDist = (game->ray.distTo.x - game->ray.deltaDist.x);
	else
		perpendicularDist = (game->ray.distTo.y - game->ray.deltaDist.y);
	printf("perpendicularD\t| %f\t\t|\n", perpendicularDist);
	game->ray.wallLineSizeInt = (int)(SCREEN_Y / perpendicularDist);
	printf( "wallLineSize\t| %i\t\t\t|\n"  , game->ray.wallLineSizeInt);
	game->ray.lineStart = -game->ray.wallLineSizeInt / 2 + SCREEN_Y / 2;
	if (game->ray.lineStart < 0)
		game->ray.lineStart = 0;
	game->ray.lineEnd = game->ray.wallLineSizeInt / 2 + SCREEN_Y / 2;
	if (game->ray.lineEnd >= SCREEN_Y)
		game->ray.lineEnd = SCREEN_Y - 1;
	printf( "lineStart\t| %i\t\t\t|\n"  ,game->ray.lineStart);
	printf( "lineEnd\t\t| %i\t\t\t|\n"  ,game->ray.lineEnd);
	double wallX;
	//? ERRO DE TEXTURA ANDAR PODE ESTAR AQUI, TROCAR A ROW PELA COL
	if (hitSide == 0 || hitSide == 1)
		wallX = game->pos.col + perpendicularDist * game->ray.rayDir.y;
	else
		wallX = game->pos.row + perpendicularDist * game->ray.rayDir.x;
	wallX -= floor(wallX);
	printf( "wallX\t\t| %f\t\t|\n"  ,wallX);
	draw_line(game, hitSide, wallX);
}