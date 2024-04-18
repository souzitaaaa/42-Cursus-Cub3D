/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:15:10 by jede-ara          #+#    #+#             */
/*   Updated: 2024/04/18 18:29:32 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_isprint_error(t_game *game, char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (ft_isprint(line[i]))
			error(game, "Invalid map");
		i++;
	}
}

void	parse_map(t_game *game, int *y)
{
	int	i;

	game->map.map_a = (char **)malloc(sizeof(char *) * (game->map.area_y + 1));
	i = 0;
	while (*y < game->map.area_y && game->map.area[*y][0] != '\0'
		&& is_not_texture(game->map.area[*y]))
	{
		game->map.map_a[i] = special_strtrim(ft_strdup(game->map.area[*y]));
		i++;
		(*y)++;
	}
	game->map.map_a[i] = NULL;
	game->map.mapa_y = i;
	if (*y < game->map.area_y)
	{
		while (*y < game->map.area_y)
			ft_isprint_error(game, game->map.area[(*y)++]);
	}
}

bool	textures_finish(bool ceiling, bool floor, t_game *game)
{
	if (ceiling == false || floor == false)
		return (false);
	if (!game->map.no_texture || !game->map.so_texture
		|| !game->map.we_texture || !game->map.ea_texture)
		return (false);
	return (true);
}

bool	check_beggin_map(bool ceiling, bool floor, t_game *game, int *y)
{
	if (textures_finish(ceiling, floor, game) == false)
		ft_isprint_error(game, game->map.area[*y]);
	if (textures_finish(ceiling, floor, game) == true)
	{
		if (ft_strchr(game->map.area[*y], '1') != NULL)
		{
			parse_map(game, y);
			return (true);
		}
		ft_isprint_error(game, game->map.area[*y]);
	}
	return (false);
}

void	map_info(t_game *game)
{
	int		y;
	bool	ceiling;
	bool	floor;

	y = 0;
	ceiling = false;
	floor = false;
	while (y < game->map.area_y)
	{
		game->map.line = ft_strtrim(game->map.area[y], " \t");
		parse_textures(game, game->map.line, &ceiling, &floor);
		if (is_not_texture(game->map.line))
		{
			if (check_beggin_map(ceiling, floor, game, &y) == true)
			{
				ft_free_str(&game->map.line);
				break ;
			}
		}
		y++;
		ft_free_str(&game->map.line);
	}
}
