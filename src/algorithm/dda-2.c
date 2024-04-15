#include "../includes/cub3d.h"

void	get_texture_info(t_game *game) {
	game->ray.line.y = 0;
	assign_vector_values(&game->ray.line.texture, 0, 0);
}

void	draw_line(t_game *game)
{
	get_texture_info(game);
	int y = 0;
	int	textureX = 0;
	textureX = (int)(game->ray.dda.wallX * (double)TEXTURE_X);
	if ((game->ray.dda.hitSide == 0 || game->ray.dda.hitSide == 1) && game->ray.rayDir.x > 0)
		textureX = TEXTURE_X - textureX - 1;
	if ((game->ray.dda.hitSide == 2 || game->ray.dda.hitSide == 3) && game->ray.rayDir.y < 0)
		textureX = TEXTURE_X - textureX - 1;
	double step = 1.0 * TEXTURE_X / game->ray.wallLineSizeInt;
	double texturePos = (game->ray.lineStart - SCREEN_Y / 2 + game->ray.wallLineSizeInt / 2) * step;
	while (y < game->ray.lineStart)
	{
		game->data.addr[y * SCREEN_X + game->ray.screen_pixel] = CEILING_COLOR;
		y++;
	}
	int textureY = 0;
	unsigned int color = 0;
	while (y < game->ray.lineEnd)
	{
		color = 0;
		textureY = (int)texturePos & (TEXTURE_X - 1);
		texturePos += step;
		if (game->ray.dda.hitSide == 0){
			color = game->texture.W_addr[TEXTURE_X * textureY + textureX];
			game->data.addr[y * SCREEN_X + game->ray.screen_pixel] = color;		}
		else if (game->ray.dda.hitSide == 1) {
			color = game->texture.W_addr[TEXTURE_X * textureY + textureX];
			game->data.addr[y * SCREEN_X + game->ray.screen_pixel] = color;
		}
	 	else if (game->ray.dda.hitSide == 2) {
			color = game->texture.N_addr[TEXTURE_X * textureY + textureX];
			game->data.addr[y * SCREEN_X + game->ray.screen_pixel] = color;
		}
	 	else if (game->ray.dda.hitSide == 3)
			game->data.addr[y * SCREEN_X + game->ray.screen_pixel] = 0x00FFC0CB;
		y++;
	}
	while (y <= SCREEN_Y)
	{
		game->data.addr[y * SCREEN_X + game->ray.screen_pixel] = FLOOR_COLOR;
		y++;
	}
}

void	dda_2(t_game *game)
{
	if (game->ray.dda.hitSide == 0 || game->ray.dda.hitSide == 1)
		game->ray.dda.perpendicularDist = (game->ray.distTo.x
				- game->ray.deltaDist.x);
	else
		game->ray.dda.perpendicularDist = (game->ray.distTo.y
				- game->ray.deltaDist.y);
	game->ray.wallLineSizeInt = (int)(SCREEN_Y
			/ game->ray.dda.perpendicularDist);
	game->ray.lineStart = -game->ray.wallLineSizeInt / 2 + SCREEN_Y / 2;
	if (game->ray.lineStart < 0)
		game->ray.lineStart = 0;
	game->ray.lineEnd = game->ray.wallLineSizeInt / 2 + SCREEN_Y / 2;
	if (game->ray.lineEnd >= SCREEN_Y)
		game->ray.lineEnd = SCREEN_Y - 1;
	if (game->ray.dda.hitSide == 0 || game->ray.dda.hitSide == 1)
		game->ray.dda.wallX = game->pos.col
			+ game->ray.dda.perpendicularDist * game->ray.rayDir.y;
	else
		game->ray.dda.wallX = game->pos.row
			+ game->ray.dda.perpendicularDist * game->ray.rayDir.x;
	game->ray.dda.wallX -= floor(game->ray.dda.wallX);
	draw_line(game);
}

/**
 * @brief       This function implements the Digital Differential Analyzer(DDA)
 * 			algorithm, which calculates the intersections of rays with the walls
 * 			in the game map
 * 				@brief //? NOT FINISHED BECAUSE I NEED TO SORT IN STRUCTS
 *
 * @param game  Struct that contains every information on the program
 */
void	dda(t_game *game)
{
	while (!game->ray.dda.hit)
	{
		if (game->ray.distTo.x < game->ray.distTo.y)
		{
			game->ray.distTo.x += game->ray.deltaDist.x;
			game->ray.mapPos.x += game->ray.step.x;
			if (game->ray.step.x == -1)
				game->ray.dda.hitSide = 0;
			else
				game->ray.dda.hitSide = 1;
		}
		else
		{
			game->ray.distTo.y += game->ray.deltaDist.y;
			game->ray.mapPos.y += game->ray.step.y;
			if (game->ray.step.y == -1)
				game->ray.dda.hitSide = 2;
			else
				game->ray.dda.hitSide = 3;
		}
		if (game->map.map_a[(int)game->ray.mapPos.y]
			[(int)game->ray.mapPos.x] == '1')
			game->ray.dda.hit = true;
	}
	dda_2(game);
}
