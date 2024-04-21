/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:31:29 by jede-ara          #+#    #+#             */
/*   Updated: 2024/04/18 20:15:01 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	find_player(t_game *game, t_playerInfo *info, char **map)
{
	t_playerPos	*pos;

	auto int x;
	auto int y = 0;
	pos = info->pos;
	while (y < game->map.mapa_y)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (!is_valid_char(map[y][x]))
				error(game, "Invalid map character");
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'W')
			{
				if (pos->row != -1 || pos->col != -1)
					error(game, "Only one player allowed");
				pos->row = x;
				pos->col = y;
				pos->orientation = map[y][x];
			}
			x++;
		}
		y++;
	}
}

t_playerPos	get_position(t_game *game, char **map)
{
	auto t_playerPos pos = {-1, -1, ' '};
	auto t_playerInfo info = {&pos};
	find_player(game, &info, map);
	if (pos.orientation == ' ')
		error(game, "The game must have one player");
	return (pos);
}

void	set_direction(t_game *game, t_playerPos pos)
{
	t_map	*map;

	map = &(game->map);
	if (pos.orientation == 'N')
	{
		get_plane(map, 1, 0);
		get_direction(map, 0, -1);
	}
	else if (pos.orientation == 'S')
	{
		get_plane(map, -1, 0);
		get_direction(map, 0, 1);
	}
	else if (pos.orientation == 'W')
	{
		get_plane(map, 0, -1);
		get_direction(map, -1, 0);
	}
	else if (pos.orientation == 'E')
	{
		get_plane(map, 0, 1);
		get_direction(map, 1, 0);
	}
}
