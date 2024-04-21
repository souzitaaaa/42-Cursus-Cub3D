/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:26:50 by jede-ara          #+#    #+#             */
/*   Updated: 2024/04/21 16:11:27 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_texture(char *line, char *compare, char **texture, t_game *game)
{
	auto int i = 2;
	if (ft_strncmp(line, compare, 3) == 0)
	{
		if (*texture)
			error(game, "Duplicate texture");
		while (line[i] == '\t' || line[i] == ' ')
			i++;
		*texture = ft_strdup(line + i);
	}
}

void	check_color(char *line, char *compare, bool *color, t_game *game)
{
	if (ft_strncmp(line, compare, 2) == 0)
	{
		if (*color == true)
			error(game, "Duplicate floor color");
		*color = true;
		if (ft_strncmp(compare, "F ", 2) == 0)
			floor_colors(game);
		if (ft_strncmp(compare, "C ", 2) == 0)
			ceiling_colors(game);
	}
}

void	parse_textures(t_game *game, char *line, bool *ceiling, bool *floor)
{
	int		i;

	i = 0;
	if (line[0] != '\0')
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		check_texture(line, "NO ", &game->map.no_texture, game);
		check_texture(line, "SO ", &game->map.so_texture, game);
		check_texture(line, "WE ", &game->map.we_texture, game);
		check_texture(line, "EA ", &game->map.ea_texture, game);
		check_color(line, "C ", ceiling, game);
		check_color(line, "F ", floor, game);
	}
}

bool	is_not_texture(char *line)
{
	if (ft_strncmp(line, "NO ", 3) != 0
		&& ft_strncmp(line, "SO ", 3) != 0
		&& ft_strncmp(line, "WE ", 3) != 0
		&& ft_strncmp(line, "EA ", 3) != 0
		&& ft_strncmp(line, "F ", 2) != 0
		&& ft_strncmp(line, "C ", 2) != 0)
		return (true);
	return (false);
}
