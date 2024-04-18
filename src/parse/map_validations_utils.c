/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:00:17 by jede-ara          #+#    #+#             */
/*   Updated: 2024/04/18 17:18:42 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	get_len_line(t_game *game, char **map, int y, t_len_line *len_info)
{
	len_info->len_current_line = ft_strlen(map[y]);
	if (y > 0)
		len_info->len_prev_line = ft_strlen(map[y - 1]);
	else
		len_info->len_prev_line = len_info->len_current_line;
	if (y < game->map.mapa_y - 1)
		len_info->len_next_line = ft_strlen(map[y + 1]);
	else
		len_info->len_next_line = len_info->len_current_line;
	len_info->len_current_line = ft_strlen(map[y]);
	return (0);
}

bool	verify_long_lines(t_game *game, char **map)
{
	t_len_line	len_info;
	int			x;
	int			y;

	init_len_info(&len_info);
	y = 0;
	while (y < game->map.mapa_y)
	{
		get_len_line(game, map, y, &len_info);
		if (len_info.len_prev_line < len_info.len_current_line
			|| len_info.len_next_line < len_info.len_current_line)
		{
			x = get_min(len_info.len_prev_line, len_info.len_next_line);
			while (map[y][x] != '\0')
			{
				if (map[y][x] != '1')
					return (false);
				x++;
			}
		}
		y++;
	}
	return (true);
}

bool	check_middle_lines(t_game *game, char **map)
{
	int		i;
	char	first_char;
	char	last_char;
	int		pos_last_char;

	i = 1;
	while (i < game->map.mapa_y - 1)
	{
		pos_last_char = ft_strlen(map[i]) - 1;
		first_char = map[i][0];
		last_char = map[i][pos_last_char];
		if ((first_char != '1' && first_char != ' ')
			|| (last_char != '1' && last_char != ' '))
			return (false);
		i++;
	}
	return (true);
}

bool	first_last_lines(char *line)
{
	int	x;

	x = 0;
	while (line[x] != '\0')
	{
		if (line[x] != '1' && line[x] != ' ')
			return (false);
		x++;
	}
	return (true);
}
