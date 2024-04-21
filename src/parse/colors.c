/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:24:20 by jede-ara          #+#    #+#             */
/*   Updated: 2024/04/18 18:34:03 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	validate_color(t_game *game, char *color_str)
{
	int		comma;

	comma = 0;
	while (*color_str != '\0')
	{
		if (*color_str == ',')
			comma++;
		color_str++;
	}
	if (comma != 2)
		error(game, "Invalid color format");
}

void	parse_color(t_game *game, char *color_str, int *color_values)
{
	int		count;
	char	*ptr;

	ptr = color_str;
	count = 0;
	while (*ptr != '\0' && count < 3)
	{
		while (*ptr == ' ' || *ptr == '\t')
			ptr++;
		if (!ft_isdigit(*ptr))
			error(game, "Invalid color format");
		color_values[count++] = ft_atoi(ptr);
		while (ft_isdigit(*ptr))
			ptr++;
		if (*ptr == ',')
			ptr++;
	}
	if (count != 3)
		error(game, "Invalid color format");
}

void	floor_colors(t_game *game)
{
	char	*color_str;
	int		i;
	int		color_values[3];

	i = 0;
	while (i < game->map.area_y)
	{
		if (ft_strncmp(game->map.area[i], "F ", 2) == 0)
		{
			color_str = game->map.area[i] + 2;
			validate_color(game, color_str);
			parse_color(game, color_str, color_values);
			game->map.f_range[0] = color_values[0];
			game->map.f_range[1] = color_values[1];
			game->map.f_range[2] = color_values[2];
			if (color_values[0] < 0 || color_values[0] > 255
				|| color_values[1] < 0 || color_values[1] > 255
				|| color_values[2] < 0 || color_values[2] > 255)
				error(game, "Ceiling color range is out of range");
		}
		i++;
	}
}

void	ceiling_colors(t_game *game)
{
	char	*color_str;
	int		i;
	int		color_values[3];

	i = 0;
	while (i < game->map.area_y)
	{
		if (ft_strncmp(game->map.area[i], "C ", 2) == 0)
		{
			color_str = game->map.area[i] + 2;
			validate_color(game, color_str);
			parse_color(game, color_str, color_values);
			game->map.c_range[0] = color_values[0];
			game->map.c_range[1] = color_values[1];
			game->map.c_range[2] = color_values[2];
			if (color_values[0] < 0 || color_values[0] > 255
				|| color_values[1] < 0 || color_values[1] > 255
				|| color_values[2] < 0 || color_values[2] > 255)
				error(game, "Floor color range is out of range");
		}
		i++;
	}
}
