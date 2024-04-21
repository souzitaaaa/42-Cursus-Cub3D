/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:28:47 by jede-ara          #+#    #+#             */
/*   Updated: 2024/04/18 16:29:22 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N'
		|| c == 'S' || c == 'W' || c == 'E' || c == ' ');
}

void	get_direction(t_map	*map, double dir_x, double dir_y)
{
	map->dir.x = dir_x;
	map->dir.y = dir_y;
}

void	get_plane(t_map	*map, double plane_x, double plane_y)
{
	map->plane.x = plane_x;
	map->plane.y = plane_y;
}
