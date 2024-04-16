/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:38:16 by jede-ara          #+#    #+#             */
/*   Updated: 2024/04/16 20:01:28 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	verify_walls(t_game *game)
{
	if (check_middle_lines(game, game->map.map_a) == false)
		return (false);
	if (first_last_lines(game->map.map_a[0]) == false
		|| first_last_lines(game->map.map_a[game->map.mapa_y - 1]) == false)
		return (false);
	if (verify_around_spaces(game, game->map.map_a) == false)
		return (false);
	if (verify_long_lines(game, game->map.map_a) == false)
		return (false);
	return (true);
}

void	map_validations(t_game *game)
{
	int	pos;

	pos = strlen(game->map.map_folder) - 4;
	if (ft_strncmp(".cub", &game->map.map_folder[pos], 4) != 0)
		error(game, "The map isn't .cub");
	get_area_y(game);
	read_map_area(game);
	get_area_x(game);
	map_info(game);
	check_textures(game);
	get_mapa_x(game);
	if (verify_walls(game) == false)
		error(game, "The map needs to be surrounded by walls");
}
