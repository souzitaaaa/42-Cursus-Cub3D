/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:44:12 by jede-ara          #+#    #+#             */
/*   Updated: 2024/04/21 23:28:10 by dinoguei         ###   ########.fr       */
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
	game->ray.dda.hitside = 0;
	game->ray.dda.perpendiculardist = 0;
	game->ray.dda.wallx = 0;
	game->ray.line.y = 0;
	assign_ivector_values(&game->ray.line.texture, 0, 0);
	game->ray.line.step = 0;
	game->ray.line.texturepos = 0;
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
	game->texture.n = NULL;
	game->texture.we = NULL;
	game->texture.so = NULL;
	game->texture.ea = NULL;
	game->map.mapa_y = 0;
	game->map.mapa_x = 0;
	game->ray.screen_pixel = 0;
	assign_vector_values(&game->ray.distto, 0, 0);
	assign_vector_values(&game->ray.step, 0, 0);
	assign_vector_values(&game->ray.velocity, 0, 0);
	init_struct2(game);
}

void	get_xpm(t_game *game)
{
	auto int tile_size = 64;
	game->texture.n = mlx_xpm_file_to_image(
			game->data.mlx, game->map.no_texture, &tile_size, &tile_size);
	game->texture.naddr = (unsigned int *)mlx_get_data_addr(
			game->texture.n, &game->texture.nbitspixel,
			&game->texture.nlinelen, &game->texture.nendian);
	game->texture.we = mlx_xpm_file_to_image(
			game->data.mlx, game->map.we_texture, &tile_size, &tile_size);
	game->texture.waddr = (unsigned int *)mlx_get_data_addr(
			game->texture.we, &game->texture.wbitspixel,
			&game->texture.wlinelen, &game->texture.wendian);
	game->texture.so = mlx_xpm_file_to_image(
			game->data.mlx, game->map.so_texture, &tile_size, &tile_size);
	game->texture.saddr = (unsigned int *)mlx_get_data_addr(game->texture.so,
			&game->texture.sbitspixel, &game->texture.slinelen,
			&game->texture.sendian);
	game->texture.ea = mlx_xpm_file_to_image(
			game->data.mlx, game->map.ea_texture, &tile_size, &tile_size);
	game->texture.eaddr = (unsigned int *)mlx_get_data_addr(game->texture.ea,
			&game->texture.ebitspixel, &game->texture.elinelen,
			&game->texture.eendian);
}

int	esc_key(t_game *game)
{
	ft_printf("🍒🍒🍒🍒🍒🍒🍒🍒🍒🍒🍒🍒🍒🍒🍒🍒🍒🍒🍒🍒🍒🍒🍒\n");
	ft_printf("🥥                                          🍑\n");
	ft_printf("🥥      This game isn't fruit related       🍑\n" RESET);
	ft_printf("🥥                                          🍑\n");
	ft_printf("🫐🫐🫐🫐🫐🫐🫐🫐🫐🫐🫐🫐🫐🫐🫐🫐🫐🫐🫐🫐🫐🫐🫐\n");
	free_exit(game);
	exit (1);
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
