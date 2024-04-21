/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:32:29 by jede-ara          #+#    #+#             */
/*   Updated: 2024/04/21 17:19:32 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	ft_isprint_str(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (ft_isprint(line[i]))
			return (true);
		i++;
	}
	return (false);
}

void	check_empty_file(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->map.area_y)
	{
		if (ft_isprint_str(game->map.area[i]))
			return ;
		i++;
	}
	error(game, "Empty File");
}

void	read_map_area(t_game *game)
{
	int		i;
	char	*out;

	i = 0;
	game->map.fd = open(game->map.map_folder, O_RDONLY);
	game->map.area = ft_calloc(game->map.area_y + 1, sizeof(char *));
	if (!game->map.area)
		error(game, "Error allocating memory");
	while (i < game->map.area_y + 1)
	{
		out = get_next_line(game->map.fd);
		game->map.area[i] = ft_strtrim(out, "\n");
		free(out);
		i++;
	}
	close(game->map.fd);
	check_empty_file(game);
}

void	get_area_x(t_game *game)
{
	int	i;
	int	len;
	int	x;

	i = 1;
	x = ft_strlen(game->map.area[0]);
	len = 0;
	while (i < game->map.area_y)
	{
		len = ft_strlen(game->map.area[i]);
		if (len > x)
			x = len;
		i++;
	}
	game->map.area_x = x;
}

void	get_area_y(t_game *game)
{
	int		y;
	char	*out;

	game->map.fd = open(game->map.map_folder, O_RDONLY);
	if (game->map.fd == -1)
		error(game, "Map doesn't open");
	y = 0;
	while (1)
	{
		out = get_next_line(game->map.fd);
		if (!out)
			break ;
		y++;
		free(out);
	}
	if (y == 0)
		error(game, "Empty File");
	game->map.area_y = y;
	close(game->map.fd);
}
