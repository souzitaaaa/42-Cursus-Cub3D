/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:06:45 by jede-ara          #+#    #+#             */
/*   Updated: 2024/04/16 16:13:07 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.mapa_y)
	{
		j = 0;
		while (j < game->map.mapa_x)
		{
			ft_printf("%d", game->map.map_a[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

bool	is_wall_or_space(char c)
{
	if (c == '1' || c == ' ')
		return (true);
	return (false);
}

bool	verify_neighbors(t_game *game, char **map, int x, int y)
{
	if (x > 0 && is_wall_or_space(map[y][x - 1]) == false)
		return (false);
	if (x + 1 < game->map.mapa_x && is_wall_or_space(map[y][x + 1]) == false)
		return (false);
	if (y > 0 && (int)ft_strlen(map[y - 1]) > x
		&& is_wall_or_space(map[y - 1][x]) == false)
		return (false);
	if (y + 1 < game->map.mapa_y && (int)ft_strlen(map[y + 1]) > x
		&& is_wall_or_space(map[y + 1][x]) == false)
		return (false);
	return (true);
}

bool	verify_around_spaces(t_game *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.mapa_y)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == ' ')
			{
				if (verify_neighbors(game, map, x, y) == false)
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}
