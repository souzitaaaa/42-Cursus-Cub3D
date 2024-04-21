/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:03:46 by jede-ara          #+#    #+#             */
/*   Updated: 2024/04/21 17:18:19 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	check_extension(t_game *game)
{
	if (ft_strncmp(".xpm", game->map.no_texture
			+ ft_strlen(game->map.no_texture) - 4, 4) != 0
		|| ft_strncmp(".xpm", game->map.so_texture
			+ ft_strlen(game->map.so_texture) - 4, 4) != 0
		|| ft_strncmp(".xpm", game->map.we_texture
			+ ft_strlen(game->map.we_texture) - 4, 4) != 0
		|| ft_strncmp(".xpm", game->map.ea_texture
			+ ft_strlen(game->map.ea_texture) - 4, 4) != 0)
		return (false);
	return (true);
}

bool	check_permission_loop(char *line, int i)
{
	if (i == 0)
	{
		if (ft_strncmp("/* XPM */\n", line, ft_strlen(line)) != 0)
			return (false);
	}
	if (i == 3)
	{
		if (ft_strncmp("\"64 64", line, 5) != 0)
			return (false);
	}
	return (true);
}

bool	check_permission(char *texture)
{
	char	*line;

	auto int fd = 0;
	auto int i = 0;
	fd = open(texture, O_RDONLY);
	if (fd == -1)
		return (false);
	while (i < 4)
	{
		line = get_next_line_free(fd, false);
		if (!check_permission_loop(line, i))
		{
			free(line);
			line = get_next_line_free(fd, true);
			return (false);
		}
		free(line);
		i++;
	}
	line = get_next_line_free(fd, true);
	free(line);
	close(fd);
	return (true);
}

bool	check_permissions(t_game *game)
{
	if (!check_permission(game->map.no_texture)
		|| !check_permission(game->map.so_texture)
		|| !check_permission(game->map.we_texture)
		|| !check_permission(game->map.ea_texture))
		return (false);
	return (true);
}

void	check_textures(t_game *game)
{
	if (check_extension(game) == false)
		error(game, "The texture you provided isn't .xpm");
	else if (check_permissions(game) == false)
		error(game, "The texture you provided doesn't exist");
}
