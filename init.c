/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:44:12 by jede-ara          #+#    #+#             */
/*   Updated: 2024/04/18 18:50:33 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"
#include "./minilibx-linux/mlx.h"

void	init_struct2(t_game *game)
{
	game->map.no_texture = NULL;
	game->map.so_texture = NULL;
	game->map.we_texture = NULL;
	game->map.ea_texture = NULL;
	game->ray.dda.hit = false;
	game->ray.dda.hitSide = 0;
	game->ray.dda.perpendicularDist = 0;
	game->ray.dda.wallX = 0;
	game->ray.line.y = 0;
	assign_ivector_values(&game->ray.line.texture, 0, 0);
	game->ray.line.step = 0;
	game->ray.line.texturePos = 0;
	game->ray.line.color = 0;
	game->map.map_a = NULL;
	game->map.area = NULL;
	game->map.line = NULL;
}

void	init_struct(t_game *game)
{
	game->data.mlx = NULL;
	game->data.win = NULL;
	game->data.img = NULL;
	game->texture.N = NULL;
	game->texture.WE = NULL;
	game->texture.SO = NULL;
	game->texture.EA = NULL;
	game->map.mapa_y = 0;
	game->map.mapa_x = 0;
	game->ray.screen_pixel = 0;
	assign_vector_values(&game->ray.distTo, 0, 0);
	assign_vector_values(&game->ray.step, 0, 0);
	assign_vector_values(&game->ray.velocity, 0, 0);
	init_struct2(game);
}

void	get_xpm(t_game *game)
{
	auto int tile_size = 32;
	game->texture.N = mlx_xpm_file_to_image(
			game->data.mlx, game->map.no_texture, &tile_size, &tile_size);
	game->texture.N_addr = (unsigned int *)mlx_get_data_addr(
			game->texture.N, &game->texture.N_bitsPixel,
			&game->texture.N_lineLen, &game->texture.N_endian);
	game->texture.WE = mlx_xpm_file_to_image(
			game->data.mlx, game->map.we_texture, &tile_size, &tile_size);
	game->texture.W_addr = (unsigned int *)mlx_get_data_addr(
			game->texture.WE, &game->texture.W_bitsPixel,
			&game->texture.W_lineLen, &game->texture.W_endian);
	game->texture.SO = mlx_xpm_file_to_image(
			game->data.mlx, game->map.so_texture, &tile_size, &tile_size);
	game->texture.S_addr = (unsigned int *)mlx_get_data_addr(game->texture.SO,
			&game->texture.S_bitsPixel, &game->texture.S_lineLen,
			&game->texture.S_endian);
	game->texture.EA = mlx_xpm_file_to_image(
			game->data.mlx, game->map.ea_texture, &tile_size, &tile_size);
	game->texture.E_addr = (unsigned int *)mlx_get_data_addr(game->texture.EA,
			&game->texture.E_bitsPixel, &game->texture.E_lineLen,
			&game->texture.E_endian);
}

void	init_game(t_game *game)
{
	game->data.mlx = mlx_init();
	game->data.win = mlx_new_window(game->data.mlx, SCREEN_X,
			SCREEN_Y, "cub3D");
	game->data.img = mlx_new_image(game->data.mlx, SCREEN_X, SCREEN_Y);
	game->data.addr = (unsigned int *)mlx_get_data_addr(game->data.img,
			&game->data.bits_per_pixel, &game->data.line_len,
			&game->data.endian);
	get_xpm(game);
	mlx_loop_hook(game->data.mlx, loop, game);
	mlx_hook(game->data.win, 2, 1L << 0, key_press, game);
	mlx_hook(game->data.win, 17, 0, esc_key, game);
	mlx_loop(game->data.mlx);
}
