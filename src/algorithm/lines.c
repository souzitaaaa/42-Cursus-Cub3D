/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:05:12 by dinoguei          #+#    #+#             */
/*   Updated: 2024/04/21 23:28:10 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_textures_2(t_game *game)
{
	if (game->ray.dda.hitside == 2)
	{
		game->ray.line.color = game->texture.naddr[TEXTURE_X
			* game->ray.line.texture.y + game->ray.line.texture.x];
		game->data.addr[game->ray.line.y * SCREEN_X
			+ game->ray.screen_pixel] = game->ray.line.color;
	}
	else if (game->ray.dda.hitside == 3)
	{
		game->ray.line.color = game->texture.saddr[TEXTURE_X
			* game->ray.line.texture.y + game->ray.line.texture.x];
		game->data.addr[game->ray.line.y * SCREEN_X
			+ game->ray.screen_pixel] = game->ray.line.color;
	}
}

void	draw_textures(t_game *game)
{
	if (game->ray.dda.hitside == 0)
	{
		game->ray.line.color = game->texture.waddr[TEXTURE_X
			* game->ray.line.texture.y + game->ray.line.texture.x];
		game->data.addr[game->ray.line.y * SCREEN_X
			+ game->ray.screen_pixel] = game->ray.line.color;
	}
	else if (game->ray.dda.hitside == 1)
	{
		game->ray.line.color = game->texture.eaddr[TEXTURE_X
			* game->ray.line.texture.y + game->ray.line.texture.x];
		game->data.addr[game->ray.line.y * SCREEN_X
			+ game->ray.screen_pixel] = game->ray.line.color;
	}
	draw_textures_2(game);
}

void	draw_line(t_game *game)
{
	get_texture_info(game);
	while (game->ray.line.y < game->ray.linestart)
	{
		game->data.addr[game->ray.line.y * SCREEN_X
			+ game->ray.screen_pixel] = encode_rgb(game->map.c_range[0],
				game->map.c_range[1], game->map.c_range[2]);
		game->ray.line.y++;
	}
	while (game->ray.line.y < game->ray.lineend)
	{
		game->ray.line.color = 0;
		game->ray.line.texture.y = (int)game->ray.line.texturepos
			& (TEXTURE_X - 1);
		game->ray.line.texturepos += game->ray.line.step;
		draw_textures(game);
		game->ray.line.y++;
	}
	while (game->ray.line.y <= SCREEN_Y)
	{
		game->data.addr[game->ray.line.y * SCREEN_X
			+ game->ray.screen_pixel] = encode_rgb(game->map.f_range[0],
				game->map.f_range[1], game->map.f_range[2]);
		game->ray.line.y++;
	}
}
