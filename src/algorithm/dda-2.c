/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda-2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:03:05 by dinoguei          #+#    #+#             */
/*   Updated: 2024/04/21 23:28:10 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_texture_info(t_game *game)
{
	game->ray.line.texture.x = (int)(game->ray.dda.wallx * (double)TEXTURE_X);
	if ((game->ray.dda.hitside == 0 || game->ray.dda.hitside == 1)
		&& game->ray.raydir.x > 0)
		game->ray.line.texture.x = TEXTURE_X - game->ray.line.texture.x - 1;
	if ((game->ray.dda.hitside == 2 || game->ray.dda.hitside == 3)
		&& game->ray.raydir.y < 0)
		game->ray.line.texture.x = TEXTURE_X - game->ray.line.texture.x - 1;
	game->ray.line.step = 1.0 * TEXTURE_X / game->ray.walllinesizeint;
	game->ray.line.texturepos = (game->ray.linestart - SCREEN_Y
			/ 2 + game->ray.walllinesizeint / 2) * game->ray.line.step;
}

void	dda_2(t_game *game)
{
	if (game->ray.dda.hitside == 0 || game->ray.dda.hitside == 1)
		game->ray.dda.perpendiculardist = (game->ray.distto.x
				- game->ray.deltadist.x);
	else
		game->ray.dda.perpendiculardist = (game->ray.distto.y
				- game->ray.deltadist.y);
	game->ray.walllinesizeint = (int)(SCREEN_Y
			/ game->ray.dda.perpendiculardist);
	game->ray.linestart = -game->ray.walllinesizeint / 2 + SCREEN_Y / 2;
	if (game->ray.linestart < 0)
		game->ray.linestart = 0;
	game->ray.lineend = game->ray.walllinesizeint / 2 + SCREEN_Y / 2;
	if (game->ray.lineend >= SCREEN_Y)
		game->ray.lineend = SCREEN_Y - 1;
	if (game->ray.dda.hitside == 0 || game->ray.dda.hitside == 1)
		game->ray.dda.wallx = game->pos.col
			+ game->ray.dda.perpendiculardist * game->ray.raydir.y;
	else
		game->ray.dda.wallx = game->pos.row
			+ game->ray.dda.perpendiculardist * game->ray.raydir.x;
	game->ray.dda.wallx -= floor(game->ray.dda.wallx);
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
		if (game->ray.distto.x < game->ray.distto.y)
		{
			game->ray.distto.x += game->ray.deltadist.x;
			game->ray.mappos.x += game->ray.step.x;
			if (game->ray.step.x == -1)
				game->ray.dda.hitside = 0;
			else
				game->ray.dda.hitside = 1;
		}
		else
		{
			game->ray.distto.y += game->ray.deltadist.y;
			game->ray.mappos.y += game->ray.step.y;
			if (game->ray.step.y == -1)
				game->ray.dda.hitside = 2;
			else
				game->ray.dda.hitside = 3;
		}
		if (game->map.map_a[(int)game->ray.mappos.y]
			[(int)game->ray.mappos.x] == '1')
			game->ray.dda.hit = true;
	}
	dda_2(game);
}
