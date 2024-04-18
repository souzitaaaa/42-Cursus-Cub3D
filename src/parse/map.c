/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:32:29 by jede-ara          #+#    #+#             */
/*   Updated: 2024/04/18 18:32:37 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	{
		printf("Error\nEmpty file!\n");
		exit(EXIT_FAILURE);
	}
	game->map.area_y = y;
	close(game->map.fd);
}
