/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:03:46 by jede-ara          #+#    #+#             */
/*   Updated: 2024/04/16 16:05:40 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	check_extension(t_game *game)
{
	if (strncmp(".xpm", game->map.no_texture
			+ strlen(game->map.no_texture) - 4, 4) != 0
		|| strncmp(".xpm", game->map.so_texture
			+ strlen(game->map.so_texture) - 4, 4) != 0
		|| strncmp(".xpm", game->map.we_texture
			+ strlen(game->map.we_texture) - 4, 4) != 0
		|| strncmp(".xpm", game->map.ea_texture
			+ strlen(game->map.ea_texture) - 4, 4) != 0)
		return (false);
	return (true);
}

void	check_textures(t_game *game)
{
	if (check_extension(game) == false)
	{
		ft_printf("Error\n The texture you provided isn't .xpm\n");
		exit(EXIT_FAILURE);
	}
}
