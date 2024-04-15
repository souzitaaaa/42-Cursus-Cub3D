/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:05:12 by dinoguei          #+#    #+#             */
/*   Updated: 2024/04/15 23:06:40 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_textures_2(t_game *game)
{
	if (game->ray.dda.hitSide == 2)
	{
		game->ray.line.color = game->texture.N_addr[TEXTURE_X
			* game->ray.line.texture.y + game->ray.line.texture.x];
		game->data.addr[game->ray.line.y * SCREEN_X
			+ game->ray.screen_pixel] = game->ray.line.color;
	}
	else if (game->ray.dda.hitSide == 3)
	{
		game->ray.line.color = game->texture.N_addr[TEXTURE_X
			* game->ray.line.texture.y + game->ray.line.texture.x];
		game->data.addr[game->ray.line.y * SCREEN_X
			+ game->ray.screen_pixel] = game->ray.line.color;
	}
}

void	draw_textures(t_game *game)
{
	if (game->ray.dda.hitSide == 0)
	{
		game->ray.line.color = game->texture.W_addr[TEXTURE_X
			* game->ray.line.texture.y + game->ray.line.texture.x];
		game->data.addr[game->ray.line.y * SCREEN_X
			+ game->ray.screen_pixel] = game->ray.line.color;
	}
	else if (game->ray.dda.hitSide == 1)
	{
		game->ray.line.color = game->texture.W_addr[TEXTURE_X
			* game->ray.line.texture.y + game->ray.line.texture.x];
		game->data.addr[game->ray.line.y * SCREEN_X
			+ game->ray.screen_pixel] = game->ray.line.color;
	}
	draw_textures_2(game);
}

void	draw_line(t_game *game)
{
	get_texture_info(game);
	while (game->ray.line.y < game->ray.lineStart)
	{
		game->data.addr[game->ray.line.y * SCREEN_X
			+ game->ray.screen_pixel] = CEILING_COLOR;
		game->ray.line.y++;
	}
	while (game->ray.line.y < game->ray.lineEnd)
	{
		game->ray.line.color = 0;
		game->ray.line.texture.y = (int)game->ray.line.texturePos
			& (TEXTURE_X - 1);
		game->ray.line.texturePos += game->ray.line.step;
		draw_textures(game);
		game->ray.line.y++;
	}
	while (game->ray.line.y <= SCREEN_Y)
	{
		game->data.addr[game->ray.line.y * SCREEN_X
			+ game->ray.screen_pixel] = FLOOR_COLOR;
		game->ray.line.y++;
	}
}
