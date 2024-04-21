/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:06:36 by jede-ara          #+#    #+#             */
/*   Updated: 2024/04/21 23:17:00 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	destroy_image(t_game *game)
{
	if (game->texture.n != NULL)
		mlx_destroy_image(game->data.mlx, game->texture.n);
	if (game->texture.we != NULL)
		mlx_destroy_image(game->data.mlx, game->texture.we);
	if (game->texture.so != NULL)
		mlx_destroy_image(game->data.mlx, game->texture.so);
	if (game->texture.ea != NULL)
		mlx_destroy_image(game->data.mlx, game->texture.ea);
	if (game->data.img != NULL)
		mlx_destroy_image(game->data.mlx, game->data.img);
	if (game->data.win != NULL)
		mlx_destroy_window(game->data.mlx, game->data.win);
	if (game->data.mlx != NULL)
	{
		mlx_destroy_display(game->data.mlx);
		free(game->data.mlx);
	}
}

void	free_exit(t_game *game)
{
	if (game->map.map_a != NULL)
		ft_free_array(&game->map.map_a);
	if (game->map.area != NULL)
		ft_free_array(&game->map.area);
	if (game->map.line != NULL)
		free(game->map.line);
	if (game->map.no_texture != NULL)
		free(game->map.no_texture);
	if (game->map.ea_texture != NULL)
		free(game->map.ea_texture);
	if (game->map.we_texture != NULL)
		free(game->map.we_texture);
	if (game->map.so_texture != NULL)
		free(game->map.so_texture);
	destroy_image(game);
	exit(0);
}

void	error(t_game *game, char *msg)
{
	(void)game;
	ft_printf("Error\n%s\n", msg);
	free_exit(game);
}

void	assign_ivector_values(t_ivector *vector, int y, int x)
{
	vector->y = y;
	vector->x = x;
}
